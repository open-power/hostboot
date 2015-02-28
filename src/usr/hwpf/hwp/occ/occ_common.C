/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_common.C $                           */
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

#include    <occ/occ_common.H>

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
#include    <initservice/initserviceif.H>

// Procedures
#include <p8_pba_init.H>
#include <p8_occ_control.H>
#include <p8_pba_bar_config.H>
#include <p8_pm_init.H>
#include <p8_pm_firinit.H>
#include <p8_pm_prep_for_reset.H>

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

extern trace_desc_t* g_fapiTd;

using namespace TARGETING;

namespace HBOCC
{
    /**
     * @brief Fetches OCC image from FSP and writes to
     *        specified offset.
     *
     * @param[in] i_occVirtAddr Virtual
     *                       address where OCC image
     *                       should be loaded.
     *
     * @return errlHndl_t  Error log image load failed
     */
    errlHndl_t loadOCCImageToHomer(void* i_occVirtAddr)
    {
        TRACUCOMP( g_fapiTd,
                   ENTER_MRK"loadOCCImageToHomer(%p)",
                   i_occVirtAddr);

        errlHndl_t  l_errl  =   NULL;
        size_t lidSize = 0;
        do {
            UtilLidMgr lidMgr(HBOCC::OCC_LIDID);

            l_errl = lidMgr.getLidSize(lidSize);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageToHomer: Error getting lid size.  lidId=0x%.8x",
                           OCC_LIDID);
                break;
            }

            l_errl = lidMgr.getLid(i_occVirtAddr, lidSize);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageToHomer: Error getting lid..  lidId=0x%.8x",
                           OCC_LIDID);
                break;
            }

        }while(0);

        TRACUCOMP( g_fapiTd,
                   EXIT_MRK"loadOCCImageToHomer");

        return l_errl;
    }

    /**
     * @brief Sets up OCC Host data
     */
    errlHndl_t loadHostDataToHomer( TARGETING::Target* i_proc,
                                    void* i_occHostDataVirtAddr)
    {
        TRACUCOMP( g_fapiTd,
                   ENTER_MRK"loadHostDataToHomer(%p)",
                   i_occHostDataVirtAddr);

        errlHndl_t  l_errl  =   NULL;

        //Treat virtual address as starting pointer
        //for config struct
        HBOCC::occHostConfigDataArea_t * config_data =
          reinterpret_cast<HBOCC::occHostConfigDataArea_t *>
          (i_occHostDataVirtAddr);

        // Get top level system target
        TARGETING::TargetService & tS = TARGETING::targetService();
        TARGETING::Target * sysTarget = NULL;
        tS.getTopLevelTarget( sysTarget );
        assert( sysTarget != NULL );

        uint32_t nestFreq =  sysTarget->getAttr<ATTR_FREQ_PB>();

        config_data->version = HBOCC::OccHostDataVersion;
        config_data->nestFrequency = nestFreq;

        // Figure out the interrupt type
        if( INITSERVICE::spBaseServicesEnabled() )
        {
            config_data->interruptType = USE_FSI2HOST_MAILBOX;
        }
        else
        {
            config_data->interruptType = USE_PSIHB_COMPLEX;
        }

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
        // Figure out the FIR master
        TARGETING::Target* masterproc = NULL;
        tS.masterProcChipTargetHandle( masterproc );
        if( masterproc == i_proc )
        {
            config_data->firMaster = IS_FIR_MASTER;
        }
        else
        {
            config_data->firMaster = NOT_FIR_MASTER;
        }
#else
        config_data->firMaster = 0;
        //force to an older version so we can support
        // older levels of OCC
        config_data->version = PRE_FIR_MASTER_VERSION;
#endif

        TRACUCOMP( g_fapiTd,
                   EXIT_MRK"loadHostDataToHomer");

        return l_errl;
    }

     errlHndl_t loadOCC(TARGETING::Target* i_target,
                    uint64_t i_occImgPaddr,
                    uint64_t i_occImgVaddr,
                    uint64_t i_commonPhysAddr)
    {
        errlHndl_t  l_errl  =   NULL;
        TRACFCOMP( g_fapiTd,
                   ENTER_MRK"loadOCC" );
        do{
            // Remember where we put things
            if( i_target )
            {
                // Subtract HOMER_OFFSET_TO_OCC_IMG to be technically
                // correct though HOMER_OFFSET_TO_OCC_IMG happens to be zero
                i_target->setAttr<ATTR_HOMER_PHYS_ADDR>
                    (i_occImgPaddr - HOMER_OFFSET_TO_OCC_IMG);
                i_target->setAttr<ATTR_HOMER_VIRT_ADDR>
                    (i_occImgVaddr - HOMER_OFFSET_TO_OCC_IMG);
            }
            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapiTarg(fapi::TARGET_TYPE_PROC_CHIP,
                    (const_cast<Target*>(i_target)));
            TRACFCOMP( g_fapiTd, "FapiTarget: %s",l_fapiTarg.toEcmdString());

            //==============================
            //Setup for OCC Load
            //==============================

            // BAR0 is the Entire HOMER (start of HOMER contains OCC base Image)
            // Bar size is in MB, obtained value of 4MB from Greg Still
            TRACUCOMP( g_fapiImpTd,
                       INFO_MRK"loadOCC: OCC Address: 0x%.8X, size=0x%.8X",
                       i_occImgPaddr, VMM_HOMER_INSTANCE_SIZE_IN_MB);

            FAPI_INVOKE_HWP( l_errl,
                             p8_pba_bar_config,
                             l_fapiTarg,
                             0,
                             i_occImgPaddr,
                             VMM_HOMER_INSTANCE_SIZE_IN_MB,
                             PBA_CMD_SCOPE_NODAL );

            if (l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCC: Bar0 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            // BAR1 is what OCC uses to talk to the Centaur
            // Bar size is in MB
            uint64_t centaur_addr =
              i_target->getAttr<ATTR_IBSCOM_PROC_BASE_ADDR>();
            FAPI_INVOKE_HWP( l_errl,
                             p8_pba_bar_config,
                             l_fapiTarg,
                             1,                                 //i_index
                             centaur_addr,                      //i_pba_bar_addr
                             (uint64_t)OCC_IBSCOM_RANGE_IN_MB,  //i_pba_bar_size
                             PBA_CMD_SCOPE_NODAL );             //i_pba_cmd_scope

            if ( l_errl )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCC: Bar1 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

           // BAR3 is the OCC Common Area
           // Bar size is in MB, obtained value of 8MB from Tim Hallett
            TRACUCOMP( g_fapiImpTd,
                       INFO_MRK"loadOCC: OCC Common Addr: 0x%.8X,size=0x%.8X",
                       i_commonPhysAddr,VMM_OCC_COMMON_SIZE_IN_MB);

            FAPI_INVOKE_HWP( l_errl,
                             p8_pba_bar_config,
                             l_fapiTarg,
                             3,
                             i_commonPhysAddr,
                             VMM_OCC_COMMON_SIZE_IN_MB,
                             PBA_CMD_SCOPE_NODAL );

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCC: Bar3 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            //==============================
            //Load the OCC HOMER image
            //==============================
            void* occVirt = reinterpret_cast<void *>(i_occImgVaddr);
            l_errl = loadOCCImageToHomer( occVirt );
            if( l_errl != NULL )
            {
                TRACFCOMP(g_fapiImpTd,
                        ERR_MRK"loadOCC: loadOCCImageToHomer failed!");
                break;
            }
        }while(0);

        TRACFCOMP( g_fapiTd,
                   EXIT_MRK"loadOCC");

        return l_errl;

    }

    /**
     * @brief Start OCC for specified DCM pair of processors.
     *        If 2nd input is NULL, OCC will be setup on just
     *        one target.
     */
    errlHndl_t startOCC (Target* i_target0,
                         Target* i_target1,
                         Target *& o_failedTarget)
    {
        TRACFCOMP( g_fapiTd,
                   ENTER_MRK"startOCC");
        errlHndl_t l_errl = NULL;

        // cast OUR type of target to a FAPI type of target.
        // figure out homer offsets
        const fapi::Target
          l_fapiTarg0(fapi::TARGET_TYPE_PROC_CHIP,
            (const_cast<Target*>(i_target0)));
        fapi::Target l_fapiTarg1;
        if(i_target1)
        {
           l_fapiTarg1.setType(fapi::TARGET_TYPE_PROC_CHIP);
           l_fapiTarg1.set(const_cast<Target*>(i_target1));
        }
        else
        {
          l_fapiTarg1.setType(fapi::TARGET_TYPE_NONE);
        }
        do {
            //==============================
            // Initialize the logic
            //==============================

            // Config path
            // p8_pm_init.C enum: PM_CONFIG
            FAPI_INVOKE_HWP( l_errl,
                             p8_pm_init,
                             l_fapiTarg0,
                             l_fapiTarg1,
                             PM_CONFIG );

            if ( l_errl != NULL )
            {
                o_failedTarget = i_target0;
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"startOCC: p8_pm_init, config failed!");
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                break;
            }

            // Init path
            // p8_pm_init.C enum: PM_INIT
            FAPI_INVOKE_HWP( l_errl,
                             p8_pm_init,
                             l_fapiTarg0,
                             l_fapiTarg1,
                             PM_INIT );

            if ( l_errl != NULL )
            {
                o_failedTarget = i_target0;
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"startOCC: p8_pm_init, init failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            //==============================
            //Start the OCC on primary chip of DCM
            //==============================
            FAPI_INVOKE_HWP( l_errl,
                             p8_occ_control,
                             l_fapiTarg0,
                             PPC405_RESET_OFF,
                             PPC405_BOOT_MEM );

            if ( l_errl != NULL )
            {
                o_failedTarget = i_target0;
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"startOCC: occ_control failed!");
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            //==============================
            // Start the OCC on slave chip of DCM
            //==============================
            if ( l_fapiTarg1.getType() != fapi::TARGET_TYPE_NONE )
            {
                FAPI_INVOKE_HWP( l_errl,
                                 p8_occ_control,
                                 l_fapiTarg1,
                                 PPC405_RESET_OFF,
                                 PPC405_BOOT_MEM );

                if ( l_errl != NULL )
                {
                    o_failedTarget = i_target1;
                    TRACFCOMP( g_fapiImpTd,
                       ERR_MRK"startOCCocc_control failed on slave chip!");
                    l_errl->collectTrace(FAPI_TRACE_NAME,256);
                    l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                    break;
                }
            }
        } while (0);

        TRACFCOMP( g_fapiTd,
                   EXIT_MRK"startOCC");
        return l_errl;
    }
    /**
     * @brief Stop OCC for specified DCM pair of processors.
     *        If 2nd input is NULL, OCC will be setup on just
     *        one target.
     */
    errlHndl_t stopOCC(TARGETING::Target * i_target0,
                       TARGETING::Target * i_target1)
    {
        TRACFCOMP( g_fapiTd,
                   ENTER_MRK"stopOCC");
        errlHndl_t err = NULL;
        do
        {
            const fapi::Target
                l_fapiTarg0(fapi::TARGET_TYPE_PROC_CHIP,
                            (const_cast<TARGETING::Target*>(i_target0)));

            fapi::Target l_fapiTarg1;
            if(i_target1)
            {
                l_fapiTarg1.setType(fapi::TARGET_TYPE_PROC_CHIP);
                l_fapiTarg1.set(const_cast<TARGETING::Target*>(i_target1));

            }
            else
            {
                l_fapiTarg1.setType(fapi::TARGET_TYPE_NONE);
            }

            FAPI_INVOKE_HWP( err,
                             p8_pm_prep_for_reset,
                             l_fapiTarg0,
                             l_fapiTarg1,
                             PM_RESET );

            if ( err != NULL )
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"stopOCC:p8_pm_prep_for_reset failed!" );
                err->collectTrace(FAPI_TRACE_NAME,256);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

        } while(0);

        TRACFCOMP( g_fapiTd,
                   EXIT_MRK"stopOCC");
        return err;
    }

    /**
     * @brief Stops OCCs on all Processors in the node
     */
    errlHndl_t stopAllOCCs()
    {
        TRACFCOMP( g_fapiTd,ENTER_MRK"stopAllOCCs" );
        errlHndl_t l_errl    = NULL;
        bool winkle_loaded = false;
        do {

#ifndef __HOSTBOOT_RUNTIME
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
#endif


            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);

            if(procChips.size() == 0)
            {
                TRACFCOMP( g_fapiTd,INFO_MRK"loadnStartAllOccs: No processors found" );
                //We'll never get this far in the IPL without any processors,
                // so just exit.
                break;
            }

            TRACFCOMP( g_fapiTd,
                       INFO_MRK"loadnStartAllOccs: %d procs found",
                       procChips.size());

            //The OCC Procedures require processors within a DCM be
            //setup together.  If DCM installed is set, we work under
            //the assumption that each nodeID is a DCM.  So sort the
            //list by NodeID then call OCC Procedures on NodeID pairs.
            std::sort(procChips.begin(),
                      procChips.end(),
                      orderByNodeAndPosition);

            //The OCC master for the node must be reset last.  For all
            //OP systems there is only a single OCC that can be the
            //master so it is safe to look at the MASTER_CAPABLE flag.
            Target* masterProc0 = NULL;
            Target* masterProc1 = NULL;

            TargetHandleList::iterator itr1 = procChips.begin();

            if(0 == (*itr1)->getAttr<ATTR_PROC_DCM_INSTALLED>())
            {
                TRACUCOMP( g_fapiTd,
                       INFO_MRK"stopAllOCCs: non-dcm path entered");

                for (TargetHandleList::iterator itr = procChips.begin();
                     itr != procChips.end();
                     ++itr)
                {
                    TargetHandleList pOccs;
                    getChildChiplets(pOccs, *itr, TYPE_OCC);
                    if (pOccs.size() > 0)
                    {
                        if( pOccs[0]->getAttr<ATTR_OCC_MASTER_CAPABLE>() )
                        {
                            masterProc0 = *itr;
                            continue;
                        }
                    }

                    l_errl = HBOCC::stopOCC( *itr, NULL );
                    if (l_errl)
                    {
                        TRACFCOMP( g_fapiImpTd, ERR_MRK"stopAllOCCs: stop failed");
                        errlCommit (l_errl, HWPF_COMP_ID);
                        // just commit and try the next chip
                    }
                }
                if (l_errl)
                {
                    break;
                }
            }
            else
            {
                TRACFCOMP( g_fapiTd,
                           INFO_MRK"stopAllOCCs: Following DCM Path");

                for (TargetHandleList::iterator itr = procChips.begin();
                     itr != procChips.end();
                     ++itr)
                {
                    Target* targ0 = *itr;
                    Target* targ1 = NULL;

                    TRACFCOMP( g_fapiImpTd, INFO_MRK"stopAllOCCs: Cur target nodeID=%d",
                               targ0->getAttr<ATTR_FABRIC_NODE_ID>());

                    //if the next target in the list is in the same node
                    // they are on the same DCM, so bump itr forward
                    // and update targ0 pointer
                    if((itr+1) != procChips.end())
                    {
                        TRACFCOMP( g_fapiImpTd, INFO_MRK"stopAllOCCs: n+1 target nodeID=%d", ((*(itr+1))->getAttr<ATTR_FABRIC_NODE_ID>()));

                        if((targ0->getAttr<ATTR_FABRIC_NODE_ID>()) ==
                           ((*(itr+1))->getAttr<ATTR_FABRIC_NODE_ID>()))
                        {
                            //need to flip the numbers because we were reversed
                            targ1 = targ0;
                            itr++;
                            targ0 = *itr;
                        }
                    }

                    TargetHandleList pOccs;
                    getChildChiplets(pOccs, targ0, TYPE_OCC);
                    if (pOccs.size() > 0)
                    {
                        if( pOccs[0]->getAttr<ATTR_OCC_MASTER_CAPABLE>() )
                        {
                            masterProc0 = targ0;
                            masterProc1 = targ1;
                            continue;
                        }
                    }

                    l_errl = HBOCC::stopOCC( targ0, targ1 );
                    if (l_errl)
                    {
                        TRACFCOMP( g_fapiImpTd, ERR_MRK"stopAllOCCs: stop failed");
                        errlCommit (l_errl, HWPF_COMP_ID);
                        // just commit and try the next module
                    }
                }
                if (l_errl)
                {
                    break;
                }
            }

            //now do the master OCC
            if( masterProc0 )
            {
                l_errl = HBOCC::stopOCC( masterProc0, masterProc1 );
                if (l_errl)
                {
                    TRACFCOMP( g_fapiImpTd, ERR_MRK"stopAllOCCs: stop failed on master");
                    break;
                }
            }
        } while(0);

        //make sure we always unload the module if we loaded it
        if (winkle_loaded)
        {
#ifndef __HOSTBOOT_RUNTIME
            errlHndl_t l_tmpErrl =
              VFS::module_unload( "libbuild_winkle_images.so" );
            if ( l_tmpErrl )
            {
                TRACFCOMP( g_fapiTd,ERR_MRK"stopAllOCCs: Error unloading build_winkle module" );
                if(l_errl)
                {
                    errlCommit( l_tmpErrl, HWPF_COMP_ID );
                }
                else
                {
                    l_errl = l_tmpErrl;
                }
            }
#endif
        }

        TRACFCOMP( g_fapiTd,EXIT_MRK"stopAllOCCs" );
        return l_errl;
    }

}  //end OCC namespace

