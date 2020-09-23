/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_host_runtime_setup.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <isteps/pm/pm_common_ext.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <vfs/vfs.H>
#include <htmgt/htmgt.H>
#include <runtime/runtime.H>
#include <runtime/customize_attrs_for_payload.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/targplatutil.H>
#include <util/utiltce.H>
#include <util/utilmclmgr.H>
#include <map>
#include <sys/internode.h>
#include <mbox/ipc_msg_types.H>
#include <arch/magic.H>

#include <secureboot/service.H>
#include <secureboot/containerheader.H>
#include <sys/mm.h>
//SBE interfacing
#include    <sbeio/sbeioif.H>
#include    <sys/misc.h>

#include <hbotcompid.H>
#include <util/misc.H>

#include "freqAttrData.H"

#ifdef CONFIG_UCD_FLASH_UPDATES
#include "call_update_ucd_flash.H"
#endif

#ifdef CONFIG_NVDIMM
#include "call_nvdimm_update.H"
#endif

#include <dump/dumpif.H>


using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_21
{


// Direct non-master nodes to close and disable their TCEs
errlHndl_t closeNonMasterTces(void)
{
    errlHndl_t l_err = nullptr;
    uint64_t nodeid = TARGETING::UTIL::getCurrentNodePhysId();

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"closeNonMasterTces(): nodeid=%d", nodeid);

    // keep track of the number of messages we send so we
    // know how many responses to expect
    uint64_t msg_count = 0;

    do{

        TARGETING::Target * sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != nullptr, "closeNonMasterTces() system target is nullptr");

        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
            sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();
        // This msgQ catches the node responses from the commands
        msg_q_t msgQ = msg_q_create();
        l_err = MBOX::msgq_register(MBOX::HB_CLOSE_TCES_MSGQ,msgQ);

        if(l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "closeNonMasterTces(): MBOX::msgq_register failed!" );
            break;
        }

        // loop thru rest all nodes -- sending msg to each
        TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
          ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "closeNonMasterTces(): HB_EXISTING_IMAGE (mask) = 0x%X, "
                   "(hb_images=0x%X)",
                   mask, hb_images);

        for (uint64_t l_node=0; (l_node < MAX_NODES_PER_SYS); l_node++ )
        {
            if (l_node == nodeid)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "closeNonMasterTces(): don't send IPC_CLOSE_TCES "
                           "message to master node %d",
                           nodeid );
                continue;
            }

            if( 0 != ((mask >> l_node) & hb_images ) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "closeNonMasterTces(): send IPC_CLOSE_TCES message "
                           "to node %d",
                           l_node );

                msg_t * msg = msg_allocate();
                msg->type = IPC::IPC_CLOSE_TCES;
                msg->data[0] = l_node;      // destination node
                msg->data[1] = nodeid;      // respond to this node

                // send the message to the slave hb instance
                l_err = MBOX::send(MBOX::HB_IPC_MSGQ, msg, l_node);

                if( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "closeNonMasterTces(): MBOX::send to node %d "
                               "failed",
                               l_node);
                    break;
                }

                ++msg_count;

            } // end of node to process
        } // end for loop on nodes

        // wait for a response to each message we sent
        if( l_err == nullptr )
        {
            //$TODO RTC:189356 - need timeout here
            while(msg_count)
            {
                msg_t * response = msg_wait(msgQ);
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "closeNonMasterTces(): IPC_CLOSE_TCES : node %d "
                           "completed",
                           response->data[0]);
                msg_free(response);
                --msg_count;
            }
        }

        MBOX::msgq_unregister(MBOX::HB_CLOSE_TCES_MSGQ);
        msg_q_destroy(msgQ);

    } while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"closeNonMasterTces(): l_err rc = 0x%X, msg_count=%d",
               ERRL_GETRC_SAFE(l_err), msg_count );

    return l_err;
}

void* call_host_runtime_setup (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_runtime_setup entry" );

    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    // Need to wait here until Fsp tells us go
    INITSERVICE::waitForSyncPoint();

    do
    {
        // Enable PM Complex Reset FFDC to HOMER
        TARGETING::Target * sys = nullptr;
        TARGETING::targetService().getTopLevelTarget (sys);
        assert (sys != nullptr,
                "call_host_runtime_setup() system target is nullptr");
        sys->trySetAttr <ATTR_PM_RESET_FFDC_ENABLE> (0x01);

        // Send the master node frequency attribute info
        // to slave nodes
        l_err = sendFreqAttrData();

        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_runtime_setup: ERROR: sendFreqAttrData Failed");

            // break from do loop if error occurred
            break;
        }

        // Close PAYLOAD TCEs
        if (TCE::utilUseTcesForDmas())
        {
            l_err = TCE::utilClosePayloadTces();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed TCE::utilClosePayloadTces" );
                // break from do loop if error occurred
                break;
            }

            // Close TCEs on non-master nodes
            l_err = closeNonMasterTces();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed closeNonMasterTces" );
                // break from do loop if error occurred
                break;
            }
        }

        // Need to load up the runtime module if it isn't already loaded
        if (  !VFS::module_is_loaded( "libruntime.so" ) )
        {
            l_err = VFS::module_load( "libruntime.so" );

            if ( l_err )
            {
                //  load module returned with errl set
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Could not load runtime module" );
                // break from do loop if error occured
                break;
            }
        }

        //Need to send System Configuration down to SBE for all HB
        //instances
        l_err = RUNTIME::sendSBESystemConfig();
        if(l_err)
        {
            break;
        }

        // On eBMC systems, the PHYP lids were loaded and verified earlier, so
        // need to re-verify/move here.
        if(INITSERVICE::spBaseServicesEnabled())
        {
            // Verify PAYLOAD and Move PAYLOAD+HDAT from Temporary TCE-related
            // memory region to the proper location
            l_err = RUNTIME::verifyAndMovePayload();
            if(l_err)
            {
                break;
            }
        }

        // Map the Host Data into the VMM if applicable
        l_err = RUNTIME::load_host_data();
        if( l_err )
        {
            break;
        }

#ifdef CONFIG_UCD_FLASH_UPDATES
        POWER_SEQUENCER::TI::UCD::call_update_ucd_flash();
#endif

        // Fill in Hostboot runtime data if there is a PAYLOAD
        if( !(TARGETING::is_no_load()) )
        {
            // API call to fix up the secureboot fields
            l_err = RUNTIME::populate_hbSecurebootData();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "Failed hbSecurebootData setup" );
                break;
            }

            // API call to populate the TPM Info fields
            l_err = RUNTIME::populate_hbTpmInfo();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "Failed hbTpmInfo setup" );
                break;
            }
        }

        l_err = RUNTIME::persistent_rwAttrRuntimeCheck();
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Failed persistent_rwAttrRuntimeCheck()" );
            break;
        }

#ifdef CONFIG_NVDIMM
        // Update the NVDIMM controller code, if necessary
        // Need to do this after LIDs are accessible
        NVDIMM_UPDATE::call_nvdimm_update();
#endif


#ifdef CONFIG_START_OCC_DURING_BOOT
        bool l_activatePM = !TARGETING::is_phyp_load();
#else
        bool l_activatePM = false;
#endif

        //@FIXME-CQ:SW493238
        if( l_activatePM && MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__SKIPOCC) )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Skipping OCC Enablement/Reset in multiproc config");
        }
        else // end FIXME
        if(l_activatePM)
        {
            TARGETING::Target* l_failTarget = nullptr;
            bool pmStartSuccess = true;

            l_err = loadAndStartPMAll(HBPM::PM_LOAD, l_failTarget);
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "loadAndStartPMAll failed");

                // Commit the error and continue with the istep
                errlCommit(l_err, ISTEP_COMP_ID);
                pmStartSuccess = false;
            }
#ifdef CONFIG_HTMGT
            // Report PM status to HTMGT
            HTMGT::processOccStartStatus(pmStartSuccess,l_failTarget);
#else
            // Verify all OCCs have reached the checkpoint
            if (pmStartSuccess)
            {
                l_err = HBPM::verifyOccChkptAll();
                if (l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "verifyOccCheckpointAll failed");

                    // Commit the error and continue with the istep
                    errlCommit(l_err, ISTEP_COMP_ID);
                }
            }
#endif

        }
        // No support for OCC
        else
        {
            //Shouldnt clear this ATTR_PM_FIRINIT_DONE_ONCE_FLAG
            //when we reset pm complex  from here.
            //Reason is this executes during istpe 21.3 then in runtime we do pm
            //reset again so to avoid saving cme fir mask value we shouldn't
            //reset the above attribute
            uint8_t l_skip_fir_attr_reset = 1;
            // Since we are not leaving the PM complex alive, we will
            //  explicitly put it into reset and clean up any memory
            l_err = HBPM::resetPMAll(HBPM::RESET_AND_CLEAR_ATTRIBUTES,
                                     l_skip_fir_attr_reset);
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "resetPMAll failed");

                // Commit the error and continue with the istep
                errlCommit(l_err, ISTEP_COMP_ID);

                // Force an attribute clear here even if the rest failed
                l_err = HBPM::resetPMAll(HBPM::CLEAR_ATTRIBUTES);
                if( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "Explicit attribute clear failed");
                    // no reason to keep this log around, most likely it
                    //  is the same fail we hit above
                    delete l_err;
                    l_err = nullptr;
                }
            }
        }

#if 0 //@TODO-RTC:164022-Support max pstate without OCC
#ifdef CONFIG_SET_NOMINAL_PSTATE
        // Speed up processors.
        l_err = setMaxPstate();
        if (l_err)
        {
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
        }
#endif
#endif

        // Update the MDRT Count and PDA Table Entries from Attribute
        TargetService& l_targetService = targetService();
        Target* l_sys = nullptr;
        l_targetService.getTopLevelTarget(l_sys);

        // Default captured data to 0s -- MPIPL if check fills in if
        // valid
        uint32_t threadRegSize = sizeof(DUMP::hostArchRegDataHdr)+
                                (DEF_ARCH_REG_COUNT_PER_THREAD *
                                 sizeof(DUMP::hostArchRegDataEntry));
        uint8_t threadRegFormat = REG_DUMP_SBE_HB_STRUCT_VER;
        uint64_t capThreadArrayAddr = 0;
        uint64_t capThreadArraySize = 0;

        if(l_sys->getAttr<ATTR_IS_MPIPL_HB>())
        {
            uint32_t l_mdrtCount =
                l_sys->getAttr<TARGETING::ATTR_MPIPL_HB_MDRT_COUNT>();
            //Update actual count in RUNTIME
            if(l_mdrtCount)
            {
                RUNTIME::saveActualCount( RUNTIME::MS_DUMP_RESULTS_TBL,
                                          l_mdrtCount);
            }


            threadRegSize =
              l_sys->getAttr<TARGETING::ATTR_PDA_THREAD_REG_ENTRY_SIZE>();
            threadRegFormat =
              l_sys->getAttr<TARGETING::ATTR_PDA_THREAD_REG_STATE_ENTRY_FORMAT>();
            capThreadArrayAddr =
              l_sys->getAttr<TARGETING::ATTR_PDA_CAPTURED_THREAD_REG_ARRAY_ADDR>();
            capThreadArraySize =
              l_sys->getAttr<TARGETING::ATTR_PDA_CAPTURED_THREAD_REG_ARRAY_SIZE>();
        }

        // Ignore return value
        RUNTIME::updateHostProcDumpActual( RUNTIME::PROC_DUMP_AREA_TBL,
                                           threadRegSize, threadRegFormat,
                                           capThreadArrayAddr, capThreadArraySize);


        //Update the MDRT value (for MS Dump)
        l_err = RUNTIME::writeActualCount(RUNTIME::MS_DUMP_RESULTS_TBL);
        if(l_err != NULL)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "write_MDRT_Count failed" );
            break;
        }

        // Fill in Hostboot runtime data for all nodes
        // (adjunct partition)
        // Write the HB runtime data into mainstore
        l_err = RUNTIME::populate_hbRuntimeData();
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Failed hbRuntimeData setup" );
            // break from do loop if error occurred
            break;
        }

        if (TCE::utilUseTcesForDmas())
        {
            // Disable all TCEs
            l_err = TCE::utilDisableTces();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed TCE::utilDisableTces" );
                // break from do loop if error occurred
                break;
            }
        }

    } while(0);

    if( l_err )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "istep host_runtime_setup failed see plid 0x%x", l_err->plid());

        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit(l_err, ISTEP_COMP_ID);

    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_runtime_setup exit" );

    return l_StepError.getErrorHandle();
}


};
