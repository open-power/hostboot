/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include    <stdint.h>

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

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/plat/fapiPlatTrace.H>
#include    <hwpf/hwpf_reasoncodes.H>

#include    <vfs/vfs.H>
#include    <util/utillidmgr.H>

// Procedures
#include <p8_pba_init.H>
#include <p8_occ_control.H>
#include <p8_pba_bar_config.H>
#include <p8_pm_init.H>
#include <p8_pm_firinit.H>

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

extern trace_desc_t* g_fapiTd;

using namespace TARGETING;

const uint32_t g_OCCLIDID = 0x81e00430;
const uint64_t OCC_IBSCOM_RANGE_IN_MB = 0x100000; /*128*1024*8*/

///////////////////////////////////////////////////////////////////////////////
// compareNodeId
///////////////////////////////////////////////////////////////////////////////
bool compareNodeId(  Target* t0,
                     Target* t1)
{
    uint8_t nodeId0 = t0->getAttr<ATTR_FABRIC_NODE_ID>();
    uint8_t nodeId1 = t1->getAttr<ATTR_FABRIC_NODE_ID>();

    if (nodeId0 == nodeId1)
    {
        return t0 < t1;
    }
    return nodeId0 < nodeId1;
}


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
            UtilLidMgr lidMgr(g_OCCLIDID);

            l_errl = lidMgr.getLidSize(lidSize);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageToHomer: Error getting lid size.  lidId=0x%.8x",
                           g_OCCLIDID);
                break;
            }

            l_errl = lidMgr.getLid(i_occVirtAddr, lidSize);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageToHomer: Error getting lid..  lidId=0x%.8x",
                           g_OCCLIDID);
                break;
            }

        }while(0);

        TRACUCOMP( g_fapiTd,
                   ENTER_MRK"loadOCCImageToHomer");

        return l_errl;
    }

    /**
     * @brief Sets up OCC Host data
     *
     * @param[in] i_occHostDataVirtAddr Virtual
     *                       address of current
     *                       proc's Host data area.
     *
     * @return errlHndl_t  Error log Host data setup failed
     */
    errlHndl_t loadHostDataToHomer(void* i_occHostDataVirtAddr)
    {
        TRACUCOMP( g_fapiTd,
                   ENTER_MRK"loadHostDataToHomer(%p)",
                   i_occHostDataVirtAddr);

        errlHndl_t  l_errl  =   NULL;

        struct occHostConfigDataArea_t
        {
            uint32_t version;
            uint32_t nestFrequency;
        };

        enum { OccHostDataVersion = 1 };

        //Treat virtual address as starting pointer
        //for config struct
        occHostConfigDataArea_t * config_data =
          reinterpret_cast<occHostConfigDataArea_t *>(i_occHostDataVirtAddr);

        // Get top level system target
        TARGETING::TargetService & tS = TARGETING::targetService();
        TARGETING::Target * sysTarget = NULL;
        tS.getTopLevelTarget( sysTarget );
        assert( sysTarget != NULL );

        uint32_t nestFreq =  sysTarget->getAttr<ATTR_FREQ_PB>();

        config_data->version = OccHostDataVersion;
        config_data->nestFrequency = nestFreq;

        TRACUCOMP( g_fapiTd,
                   EXIT_MRK"loadHostDataToHomer");

        return l_errl;
    }

    /**
     * @brief Execute procedures and steps necessary
     *        to load OCC data in specified processor
     *
     * @param[in] i_target   Target proc to load
     * @param[in] i_homerVirtAddrBase Virtual
     *                       address of current
     *                       procs HOMER
     *
     * @return errlHndl_t  Error log image load failed
     */
    errlHndl_t load(Target* i_target,
                    void* i_homerVirtAddrBase)
    {
        errlHndl_t  l_errl  =   NULL;
        uint64_t targHomer = 0;
        uint64_t tmpOffset = 0;
        void* occVirt = 0;
        void* occHostVirt = 0;

        TRACFCOMP( g_fapiTd,
                   ENTER_MRK"HBOCC:load()" );

        do{

            //Figure out OCC image offset for Target
            //OCC image offset = HOMER_SIZE*ProcPosition +
            //       OCC offset within HOMR (happens to be zero)
            uint8_t tmpPos = i_target->getAttr<ATTR_POSITION>();
            tmpOffset = tmpPos*VMM_HOMER_INSTANCE_SIZE +
              HOMER_OFFSET_TO_OCC_IMG;
            targHomer = VMM_HOMER_REGION_START_ADDR +
              tmpOffset;
            occVirt =
              reinterpret_cast<void *>
              (reinterpret_cast<uint64_t>(i_homerVirtAddrBase)
               + tmpOffset) ;

            //Figure out OCC Host Data offset for Target
            //OCC host data offset = HOMER_SIZE*ProcPosition +
            //                       OCC data within HOMR
            tmpOffset = tmpPos*VMM_HOMER_INSTANCE_SIZE +
              HOMER_OFFSET_TO_OCC_HOST_DATA;
            occHostVirt =
              reinterpret_cast<void *>
              (reinterpret_cast<uint64_t>(i_homerVirtAddrBase)
               + tmpOffset) ;


            // cast OUR type of target to a FAPI type of target.
            const fapi::Target
              l_fapiTarg(fapi::TARGET_TYPE_PROC_CHIP,
                         (const_cast<Target*>(i_target)));

            //==============================
            //Setup for OCC Load
            //==============================

            // BAR0 is the Entire HOMER (start of HOMER contains OCC base Image)
            // Bar size is in MB, obtained value of 4MB from Greg Still
            const uint64_t bar0_size_MB = VMM_HOMER_INSTANCE_SIZE_IN_MB;
            TRACUCOMP( g_fapiImpTd,
                       INFO_MRK"OCC Address: 0x%.8X, size=0x%.8X",
                       targHomer, bar0_size_MB  );

            FAPI_INVOKE_HWP( l_errl,
                             p8_pba_bar_config,
                             l_fapiTarg,
                             0, targHomer, bar0_size_MB,
                             PBA_CMD_SCOPE_NODAL );

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"Bar0 config failed!" );
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
                             1,  //i_index
                             centaur_addr,  //i_pba_bar_addr
                             OCC_IBSCOM_RANGE_IN_MB, //i_pba_bar_size
                             PBA_CMD_SCOPE_NODAL ); //i_pba_cmd_scope

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"Bar1 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

           // BAR3 is the OCC Common Area
            // Bar size is in MB, obtained value of 8MB from Tim Hallett
            const uint64_t bar3_size_MB = VMM_OCC_COMMON_SIZE_IN_MB;
            const uint64_t occ_common_addr = VMM_OCC_COMMON_START_ADDR;

            TRACUCOMP( g_fapiImpTd,
                       INFO_MRK"OCC Common Address: 0x%.8X, size=0x%.8X",
                       occ_common_addr, bar3_size_MB );

            FAPI_INVOKE_HWP( l_errl,
                             p8_pba_bar_config,
                             l_fapiTarg,
                             3, occ_common_addr,
                             bar3_size_MB,
                             PBA_CMD_SCOPE_NODAL );

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"Bar3 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            //==============================
            //Load the OCC HOMER image
            //==============================
            l_errl = loadOCCImageToHomer( occVirt );
            if( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd, ERR_MRK"loading image failed!" );
                break;
            }

            //==============================
            //Setup host data area of HOMER;
            //==============================
            l_errl = loadHostDataToHomer(occHostVirt);
            if( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd, ERR_MRK"loading Host Data Area failed!" );
                break;
            }

        }while(0);

        TRACFCOMP( g_fapiTd,
                   EXIT_MRK"HBOCC:load()" );

        return l_errl;

    }

    /**
     * @brief Load and Start OCC for specified DCM
     *        pair of processors.  If 2nd input target
     *        is NULL, OCC will be setup on just the
     *        one target.
     *
     * @param[in] i_target0  Target of first proc in
     *                       DCM pair
     * @param[in] i_target1  Target of second proc in
     *                       DCM pair
     * @param[in] i_homerVirtAddrBase Base Virtual
     *                       address of all HOMER
     *                       images
     *
     * @return errlHndl_t  Error log image load failed
     */
    errlHndl_t loadnStartOcc(Target* i_target0,
                             Target* i_target1,
                             void* i_homerVirtAddrBase)
    {
        errlHndl_t  l_errl  =   NULL;

        TRACUCOMP( g_fapiTd,
                   ENTER_MRK"loadnStartOcc" );


        do {
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

            //==============================
            //Setup and load oCC
            //==============================

            l_errl = load(i_target0,
                          i_homerVirtAddrBase);
            if(l_errl != NULL)
            {
                TRACFCOMP( g_fapiImpTd, ERR_MRK"loadnStartOcc: load failed for target 0" );
                break;
            }

            if(i_target1 != NULL)
            {
                l_errl = load(i_target1,
                              i_homerVirtAddrBase);
                if(l_errl != NULL)
                {
                    TRACFCOMP( g_fapiImpTd, ERR_MRK"loadnStartOcc: load failed for target 1" );
                    break;
                }
            }
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
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"p8_pm_init, config failed!" );
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
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"p8_pm_init, init failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }
            TRACFCOMP( g_fapiImpTd,
                       INFO_MRK"OCC Finished: p8_pm_init.C enum: PM_INIT" );


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
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"occ_control failed!" );
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
                    TRACFCOMP( g_fapiImpTd,
                               ERR_MRK"occ_control failed!" );
                    l_errl->collectTrace(FAPI_TRACE_NAME,256);
                    l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                    break;
                }
            }

        } while(0);

        TRACUCOMP( g_fapiTd,
                   EXIT_MRK"loadnStartOcc" );

        return l_errl;
    }


    ////////////////////////////////////////////////
    errlHndl_t loadnStartAllOccs()
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

            //Map entire homer region into virtual memory
            homerVirtAddrBase =
              mm_block_map(reinterpret_cast<void*>(VMM_HOMER_REGION_START_ADDR),
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
                for (TargetHandleList::iterator itr = procChips.begin();
                     itr != procChips.end();
                     ++itr)
                {
                    l_errl =  loadnStartOcc(*itr,
                                            NULL,
                                            homerVirtAddrBase);
                    if(l_errl)
                    {
                        TRACFCOMP( g_fapiImpTd, ERR_MRK"loadnStartAllOccs: loadnStartOcc failed!" );
                        break;
                    }
                }


            }
            else
            {
                TRACUCOMP( g_fapiTd,
                           INFO_MRK"loadnStartAllOccs: Following DCM Path");

                std::sort(procChips.begin(), procChips.end(), compareNodeId);

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
                    TRACUCOMP( g_fapiImpTd, INFO_MRK"loadnStartAllOccs: calling loadnStartOcc." );
                    l_errl =  loadnStartOcc(targ0,
                                            targ1,
                                            homerVirtAddrBase);
                    if(l_errl)
                    {
                        TRACFCOMP( g_fapiImpTd, ERR_MRK"loadnStartAllOccs: loadnStartOcc failed!" );
                        break;
                    }
                }
            }

        } while(0);

        errlHndl_t  l_tmpErrl  =   NULL;
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



}  //end OCC namespace
