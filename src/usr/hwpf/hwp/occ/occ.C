/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include    <stdint.h>
#include    <config.h>

#include    <hwpf/hwp/occ/occ.H>
#include    <hwpf/hwp/occ/occ_common.H>

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <devicefw/userif.H>
#include    <sys/misc.h>
#include    <sys/mm.h>
#include    <sys/mmio.h>
#include    <vmmconst.h>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>
#include    <targeting/common/util.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/plat/fapiPlatTrace.H>
#include    <hwpf/hwpf_reasoncodes.H>

#include    <vfs/vfs.H>
#include    <util/utillidmgr.H>

#include    <htmgt/htmgt.H>

// Procedures
#include <p8_pba_init.H>
#include <p8_occ_control.H>
#include <p8_pba_bar_config.H>
#include <p8_pm_init.H>
#include <p8_pm_firinit.H>

#include <config.h>
// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

extern trace_desc_t* g_fapiTd;

using namespace TARGETING;

namespace HBOCC
{
   /**
     * @brief Setup homer addresses and load OCC for a specified processor
     *
     * @param[in] i_target0  Target proc to load
     * @param[in] i_homerVirtAddrBase Base Virtual
     *                       address of all HOMER
     *                       images
     * @param[in] i_homerPhysAddrBase Base Physical
     *                       address of all HOMER
     *                       images
     *
     *  @return errlHndl_t  Error log
     */

     errlHndl_t Setupnload (Target* i_target,
                            void* i_homerVirtAddrBase,
                            uint64_t i_homerPhysAddrBase)
     {
         errlHndl_t  l_errl  =   NULL;

         TRACUCOMP( g_fapiTd,
                   ENTER_MRK"Setupnload" );


        do {
            //==============================
            //Setup Addresses
            //==============================
            uint8_t  tmpPos    = i_target->getAttr<ATTR_POSITION>();
            uint64_t tmpOffset = (tmpPos * VMM_HOMER_INSTANCE_SIZE);

            uint64_t i_homerPhysAddr  = i_homerPhysAddrBase + tmpOffset +
                                        HOMER_OFFSET_TO_OCC_IMG;
            uint64_t i_homerVirtAddr  = reinterpret_cast<uint64_t>
                                        (i_homerVirtAddrBase) + tmpOffset +
                                        HOMER_OFFSET_TO_OCC_IMG;

            uint64_t i_commonPhysAddr = i_homerPhysAddrBase +
                                        VMM_HOMER_REGION_SIZE;

            //==============================
            // Load OCC
            //==============================
            l_errl=  HBOCC::loadOCC(i_target,
                                        i_homerPhysAddr,
                                        i_homerVirtAddr,
                                        i_commonPhysAddr);
            if(l_errl != NULL)
            {
                TRACFCOMP( g_fapiImpTd, ERR_MRK"Setupnload: loadOCC failed" );
                break;
            }

            //==============================
            //Setup host data area of HOMER;
            //==============================
            uint64_t i_homerHostVirtAddr = reinterpret_cast<uint64_t>
                                           (i_homerVirtAddrBase) +
                                tmpOffset + HOMER_OFFSET_TO_OCC_HOST_DATA;
            void* occHostVirt = reinterpret_cast<void*>(i_homerHostVirtAddr);
            l_errl = HBOCC::loadHostDataToHomer(occHostVirt);
            if( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd, ERR_MRK"loading Host Data Area failed!" );
                break;
            }
        } while (0);

        return l_errl;
     }

    /**
     * @brief Starts OCCs on all Processors in the node
     *        This is intended to be used for AVP testing.
     *
     * @param[out] o_failedOccTarget: Pointer to the target failing
     *                       loadnStartAllOccs
     * @return errlHndl_t  Error log if OCC load failed
     */
    errlHndl_t loadnStartAllOccs(TARGETING::Target *& o_failedOccTarget)
    {
        errlHndl_t  l_errl  =   NULL;
        void* homerVirtAddrBase = NULL;
        bool winkle_loaded = false;

        TRACUCOMP( g_fapiTd,
                   ENTER_MRK"loadnStartAllOccs" );

        do {
            //OCC requires the build_winkle_images library
            if (  !VFS::module_is_loaded( "libbuild_winkle_images.so" ) )
            {
                l_errl = VFS::module_load( "libbuild_winkle_images.so" );

                if ( l_errl )
                {
                    //  load module returned with errl set
                    TRACFCOMP( g_fapiTd,ERR_MRK"loadnStartAllOccs: Could not load build_winkle module" );
                    // break from do loop if error occured
                    break;
                }
                winkle_loaded = true;
            }

            assert(VMM_HOMER_REGION_SIZE <= THIRTYTWO_GB,
                   "loadnStartAllOccs: Unsupported HOMER Region size");

            //If running Sapphire need to place this at the top of memory
            uint64_t homerPhysAddrBase = VMM_HOMER_REGION_START_ADDR;
            if(TARGETING::is_sapphire_load())
            {
                homerPhysAddrBase = TARGETING::get_top_mem_addr();
                assert (homerPhysAddrBase != 0,
                        "loadnStartAllOccs: Top of memory was 0!");
                homerPhysAddrBase -= VMM_ALL_HOMER_OCC_MEMORY_SIZE;
            }
            TRACFCOMP( g_fapiTd, "HOMER is at %.16X", homerPhysAddrBase );

            //Map entire homer region into virtual memory
            homerVirtAddrBase =
              mm_block_map(reinterpret_cast<void*>(homerPhysAddrBase),
                           VMM_HOMER_REGION_SIZE);

            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);

            if(procChips.size() == 0)
            {
                TRACFCOMP( g_fapiTd,INFO_MRK"loadnStartAllOccs: No processors found" );
                //We'll never get this far in the IPL without any processors,
                // so just exit.
                break;
            }

            TRACUCOMP( g_fapiTd,
                       INFO_MRK"loadnStartAllOccs: %d procs found",
                       procChips.size());

            //The OCC Procedures require processors within a DCM be
            //setup together.  So, first checking if any proc has
            //DCM installed attribute set.  If not, we can iterate
            //over the list in any order.

            //If DCM installed is set, we work under the assumption
            //that each nodeID is a DCM.  So sort the list by NodeID
            //then call OCC Procedures on NodeID pairs.

            TargetHandleList::iterator itr1 = procChips.begin();

            if(0 ==
               (*itr1)->getAttr<ATTR_PROC_DCM_INSTALLED>())
            {
                TRACUCOMP( g_fapiTd,
                       INFO_MRK"loadnStartAllOccs: non-dcm path entered");

                for (TargetHandleList::iterator itr = procChips.begin();
                     itr != procChips.end();
                     ++itr)
                {
                    /******* SETUP AND LOAD **************/
                    l_errl =  Setupnload   (*itr,
                                            homerVirtAddrBase,
                                            homerPhysAddrBase);
                    if(l_errl)
                    {
                        o_failedOccTarget = *itr;
                        TRACFCOMP( g_fapiImpTd, ERR_MRK
                         "loadnStartAllOccs:loadnStartOcc failed");
                        break;
                    }

                    /********* START OCC *************/
                    l_errl = HBOCC::startOCC (*itr, NULL, o_failedOccTarget);
                    if (l_errl)
                    {
                        TRACFCOMP( g_fapiImpTd, ERR_MRK"loadnStartAllOcc: start failed");
                        break;
                    }
                }
                if (l_errl)
                {
                    break;
                }

            }
            else
            {
                TRACUCOMP( g_fapiTd,
                           INFO_MRK"loadnStartAllOccs: Following DCM Path");

                std::sort(procChips.begin(),
                          procChips.end(),
                          orderByNodeAndPosition);

                TRACUCOMP( g_fapiTd,
                           INFO_MRK"loadnStartAllOccs: procChips list sorted");

                for (TargetHandleList::iterator itr = procChips.begin();
                     itr != procChips.end();
                     ++itr)
                {
                    TRACUCOMP( g_fapiImpTd, INFO_MRK"loadnStartAllOccs: Insepcting first target" );
                    Target* targ0 = *itr;
                    Target* targ1 = NULL;

                    TRACUCOMP( g_fapiImpTd, INFO_MRK"loadnStartAllOccs: Cur target nodeID=%d",
                               targ0->getAttr<ATTR_FABRIC_NODE_ID>());


                    //if the next target in the list is in the same node
                    // they are on the same DCM, so bump itr forward
                    // and update targ1 pointer
                    if((itr+1) != procChips.end())
                    {
                        TRACUCOMP( g_fapiImpTd, INFO_MRK"loadnStartAllOccs: n+1 target nodeID=%d", ((*(itr+1))->getAttr<ATTR_FABRIC_NODE_ID>()));

                        if((targ0->getAttr<ATTR_FABRIC_NODE_ID>()) ==
                           ((*(itr+1))->getAttr<ATTR_FABRIC_NODE_ID>()))
                        {
                            itr++;
                            targ1 = *itr;
                        }
                    }

                    /********** Setup and load targ0 ***********/
                    l_errl =  Setupnload   (targ0,
                                            homerVirtAddrBase,
                                            homerPhysAddrBase);
                    if(l_errl)
                    {
                        o_failedOccTarget = targ0;
                        TRACFCOMP( g_fapiImpTd, ERR_MRK
                        "loadnStartAllOccs: Setupnload failed on targ0");
                        break;
                    }

                    /*********** Setup and load targ1 **********/
                    l_errl =  Setupnload   (targ1,
                                            homerVirtAddrBase,
                                            homerPhysAddrBase);
                    if(l_errl)
                    {
                        o_failedOccTarget = targ1;
                        TRACFCOMP( g_fapiImpTd, ERR_MRK
                        "loadnStartAllOccs:Setupnload failed on targ1");
                        break;
                    }

                    /*********** Start OCC *******************/
                    l_errl = HBOCC::startOCC (targ0, targ1, o_failedOccTarget);
                    if (l_errl)
                    {
                        TRACFCOMP( g_fapiImpTd, ERR_MRK"loadnStartAllOccs: start failed");
                        break;
                    }
                }
                if (l_errl)
                {
                    break;
                }
            }

        } while(0);

        errlHndl_t  l_tmpErrl  =   NULL;
//Unless HTMGT is in use, there are no further accesses to HOMER memory
//required during the IPL
#ifndef CONFIG_HTMGT
        if(homerVirtAddrBase)
        {
            int rc = 0;
            rc =  mm_block_unmap(homerVirtAddrBase);
            if (rc != 0)
            {
                /*@
                 * @errortype
                 * @moduleid     fapi::MOD_OCC_LOAD_START_ALL_OCCS
                 * @reasoncode   fapi::RC_MM_UNMAP_ERR
                 * @userdata1    Return Code
                 * @userdata2    Unmap address
                 * @devdesc      mm_block_unmap() returns error
                 * @custdesc    A problem occurred during the IPL
                 *              of the system.
                 */
                l_tmpErrl =
                  new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi::MOD_OCC_LOAD_START_ALL_OCCS,
                                          fapi::RC_MM_UNMAP_ERR,
                                          rc,
                                          reinterpret_cast<uint64_t>
                                          (homerVirtAddrBase));
                if(l_tmpErrl)
                {
                    if(l_errl)
                    {
                        errlCommit( l_tmpErrl, HWPF_COMP_ID );
                    }
                    else
                    {
                        l_errl = l_tmpErrl;
                    }
                }
            }
        }
#endif
        //make sure we always unload the module
        if (winkle_loaded)
        {
            l_tmpErrl = VFS::module_unload( "libbuild_winkle_images.so" );
            if ( l_tmpErrl )
            {
                TRACFCOMP( g_fapiTd,ERR_MRK"loadnStartAllOccs: Error unloading build_winkle module" );
                if(l_errl)
                {
                    errlCommit( l_tmpErrl, HWPF_COMP_ID );
                }
                else
                {
                    l_errl = l_tmpErrl;
                }
            }
        }

        TRACUCOMP( g_fapiTd,
                   EXIT_MRK"loadnStartAllOccs" );

        return l_errl;
    }

    /**
     * @brief Starts OCCs on all Processors in the node
     *        This is intended to be used for Open Power.
     *
     * @return errlHndl_t  Error log if OCC load failed
     */
    errlHndl_t activateOCCs()
    {
        TRACUCOMP( g_fapiTd,ENTER_MRK"activateOCCs" );
        errlHndl_t l_errl    = NULL;
        TARGETING::Target* l_failedOccTarget = NULL;
#ifdef CONFIG_HTMGT
        bool occStartSuccess = true;
#endif

        l_errl = loadnStartAllOccs (l_failedOccTarget);
        if (l_errl)
        {
            errlCommit (l_errl, HWPF_COMP_ID);
#ifdef CONFIG_HTMGT
            occStartSuccess = false;
#endif
        }

        //TODO RTC:116027
        //HB configures/enables the occ buffers

        //TODO RTC:115636
        //HB enables the scon-via-i2c logic on the OCCs

#ifdef CONFIG_HTMGT
        // Report OCC status to HTMGT
        HTMGT::processOccStartStatus(occStartSuccess,l_failedOccTarget);
#endif
        TRACUCOMP( g_fapiTd,EXIT_MRK"activateOCC" );
        return l_errl;
    }


}  //end OCC namespace
