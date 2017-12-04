/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/runtime/rt_todintf.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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

#include <isteps/tod/runtime/rt_todintf.H>
#include <TodTrace.H>      // TOD_ENTER, TOD_EXIT
#include <TodUtils.H>      // GETHUID
#include <TodSvcUtil.H>    // getMaxProcsOnSystem

#include <runtime/interface.h>        // g_hostInterfaces
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <tod_init_reasoncodes.H>     // TOD_RT_TOPOLOGY_RESET_BACKUP, etc
#include <errlmanager_common.C>       // errlCommit


using namespace ERRORLOG;

namespace TOD
{

const size_t MSG_OSC_ORDINAL_ID_LOC = 0;
const size_t MSG_OSC_ORDINAL_NODE_HUID_LOC = 1;
const size_t MSG_OSC_HUIDS_LOC = 2;
const size_t MSG_OSC_SIZE_OF_DETAILS = 2;

//*****************************************************************************
// resetBackupTopology
//*****************************************************************************
errlHndl_t resetBackupTopology(
                              uint32_t i_oscPos,
                              const TARGETING::TargetHandle_t& i_procOscTgt,
                              const TARGETING::TargetHandleList& i_badChipList,
                              bool i_informPhyp)
{
    TOD_ENTER("resetBackupTopology");
    errlHndl_t l_err = nullptr;

    // Put the handle to the firmware_request request struct
    // out here so it is easier to free later
    hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;
    hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

    do
    {
        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            TOD_ERR("resetBackupTopology: "
                    "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity     ERRL_SEV_UNRECOVERABLE
             * @moduleid     TOD_RT_TOPOLOGY_RESET_BACKUP
             * @reasoncode   TOD_RT_NULL_FIRMWARE_REQUEST_PTR
             * @userdata1    None
             * @userdata2    None
             * @devdesc      Host interfaces are not initialized
             * @custdesc     An internal error occurred. This will
             *               force the Time of Day function to run
             *               with complete redundancy.
             */
            l_err = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                   TOD_RT_TOPOLOGY_RESET_BACKUP,
                                   TOD_RT_NULL_FIRMWARE_REQUEST_PTR,
                                   0, 0, true);

            break;
        }

        // The format of the data to be sent, according to the document
        // "Handle PRD Request for resetting backup TOD topology" is as follows
        // All data members below are 4 bytes long (32 bits)
        // Ordinal ID - 0xFFFFFFFF means no OSC to be avoided
        // HUID of the node - This field should be considered only if Ordinal
        //                    ID is NOT set to 0xFFFFFFFF otherwise it is set
        //                    to 0
        // HUID of the first processor
        // HUID of the second processor, etc

        // Check if we get conflicting data, if so send a Trace out
        if ((0xFFFFFFFF == i_oscPos) && (nullptr != i_procOscTgt))
        {
           TOD_ERR("Conflicting input data, input oscillator position "
                   "(i_oscPos) has value 0xFFFFFFFF, meaning no oscillator "
                   "to be avoided but input oscillator target (i_procOscTgt) "
                   "has a valid value" );
        }
        else if ((0xFFFFFFFF != i_oscPos) && (nullptr == i_procOscTgt))
        {
           TOD_ERR("Conflicting input data, input oscillator position "
                   "(i_oscPos) has value 0x%X, meaning avoid oscillator "
                   "but input oscillator target (i_procOscTgt) "
                   "has a NULL value", i_oscPos);
        }
        // Flag to determine if the OSC data will be added to the data
        bool l_addOscData = (0xFFFFFFFF != i_oscPos) &&
                            (nullptr != i_procOscTgt);

        // Default the request data size to the size of the
        // GenericFspMboxMessage_t minus the size of the
        // GenericFspMboxMessage_t's data.  The size of the
        // GenericFspMboxMessage_t's data will be added later
        uint32_t l_req_data_size = sizeof(GenericFspMboxMessage_t) -
                                   sizeof(GenericFspMboxMessage_t::data);

        // Add to the request data size iff there is data needing to be passed
        if (i_badChipList.size() > 0)
        {
            // if the bad chip list has any items then increase size to
            // accommodate for an ordinal ID and a HUID, regardless if
            // they have relevant data or not, because they are expected
            // before the HUID list.
            l_req_data_size += (MSG_OSC_SIZE_OF_DETAILS * sizeof(uint32_t)) +
                               (i_badChipList.size() * sizeof(uint32_t));
        }
        else if (l_addOscData)
        {
            // if there is a valid OSC then accommodate for an ordinal ID
            // and HUID of node, but don't need space for HUID list because,
            // if we are here, the list is empty
            l_req_data_size += (MSG_OSC_SIZE_OF_DETAILS * sizeof(uint32_t));
        }

        // The request data size must be at a minimum the size of the
        // FSP generic message (sizeof(GenericFspMboxMessage_t))
        if (l_req_data_size < sizeof(GenericFspMboxMessage_t))
        {
            l_req_data_size = sizeof(GenericFspMboxMessage_t);
        }

        // Calculate the TOTAL size of hostInterfaces::hbrt_fw_msg which
        // means only adding hostInterfaces::HBRT_FW_MSG_BASE_SIZE to
        // the previous calculated request data size
        uint64_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                     l_req_data_size;

        // Create the firmware_request request struct to send data
        l_req_fw_msg =
                   (hostInterfaces::hbrt_fw_msg *)malloc(l_req_fw_msg_size);

        // Initialize the firmware_request request struct
        l_req_fw_msg->generic_msg.initialize();

        // Populate the firmware_request request struct with given data
        l_req_fw_msg->io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg->generic_msg.dataSize = l_req_data_size;
        l_req_fw_msg->generic_msg.msgq = MBOX::FSP_TOD_MSGQ;
        l_req_fw_msg->generic_msg.msgType = (false == i_informPhyp ?
                   GenericFspMboxMessage_t::MSG_TOD_BACKUP_RESET:
                   GenericFspMboxMessage_t::MSG_TOD_BACKUP_RESET_INFORM_PHYP);
        l_req_fw_msg->generic_msg.__req = GenericFspMboxMessage_t::REQUEST;

        // A convenient way to populate the data
        uint32_t* l_dataPtr =
                reinterpret_cast<uint32_t*>(&(l_req_fw_msg->generic_msg.data));

        if (i_badChipList.size() > 0)
        {
            // set the ordinal ID
            l_dataPtr[MSG_OSC_ORDINAL_ID_LOC] = i_oscPos;

            // attach the HUIDs from bad chip list to end of struct
            size_t i = MSG_OSC_HUIDS_LOC;
            for (auto l_target : i_badChipList)
            {
                l_dataPtr[i++] = GETHUID(l_target);
            }
        }

        // Set the HUID of the ordinal node if need be
        if (l_addOscData)
        {
            // set the ordinal ID
            l_dataPtr[MSG_OSC_ORDINAL_ID_LOC] = i_oscPos;

            // Get the parent node target
            TARGETING::TargetHandleList l_list;
            TARGETING::targetService().getAssociated(l_list,
                                           i_procOscTgt,
                                           TARGETING::TargetService::PARENT,
                                           TARGETING::TargetService::IMMEDIATE);

            if (l_list.size() == 1)
            {
               l_dataPtr[MSG_OSC_ORDINAL_NODE_HUID_LOC] = GETHUID(l_list[0]);
            }
            else
            {
                /*@
                 * @errortype
                 * @severity     ERRL_SEV_UNRECOVERABLE
                 * @moduleid     TOD_RT_TOPOLOGY_RESET_BACKUP
                 * @reasoncode   TOD_INVALID_TARGET
                 * @userdata1    The number of parents found osc target
                 * @userdata2    None
                 * @devdesc      No/Multiple parent(s) found for
                 *               processor osc target
                 * @custdesc     An internal error occurred. This will
                 *               force the Time of Day function to run
                 *               with complete redundancy.
                 */
                l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                      TOD_RT_TOPOLOGY_RESET_BACKUP,
                                      TOD_INVALID_TARGET,
                                      l_list.size(), 0, true);

                break;
            }
        }

        // Create the firmware_request response struct to receive data
        // NOTE: For messages to the FSP the response size must match
        // the request size
        uint64_t l_resp_fw_msg_size = l_req_fw_msg_size;
        l_resp_fw_msg =
                    (hostInterfaces::hbrt_fw_msg *)malloc(l_resp_fw_msg_size);
        memset(l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Trace out the request structure
        TRACFBIN(ISTEPS_TRACE::g_trac_isteps_trace,
                 INFO_MRK"TOD::Sending firmware_request",
                 l_req_fw_msg,
                 l_req_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        l_resp_fw_msg);

        if (l_err)
        {
            break;
        }
    } while (0);

    // Release the firmware messages
    free(l_req_fw_msg);
    free(l_resp_fw_msg);
    l_req_fw_msg = l_resp_fw_msg = nullptr;

    TOD_EXIT("resetBackupTopology");
    return l_err;
} // end resetBackupTopology


//*****************************************************************************
// readTodProcDataFromFile
//*****************************************************************************
errlHndl_t readTodProcDataFromFile(TodChipDataContainer& o_todChipData)
{
    TOD_ENTER("readTodProcDataFromFile");
    errlHndl_t l_err = nullptr;

    // Put the handle to the firmware messages out here
    // so it is easier to free later
    hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;
    hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

    // clear the out data, regardless of the code to follow
    o_todChipData.clear();

    do
    {
        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            TOD_ERR("readTodProcDataFromFile: "
                    "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity     ERRL_SEV_UNRECOVERABLE
             * @moduleid     TOD_RT_TOPOLOGY_DATA
             * @reasoncode   TOD_RT_NULL_FIRMWARE_REQUEST_PTR
             * @devdesc      Host interfaces are not initialized
             * @custdesc     An internal error occurred. This will
             *               force the Time of Day function to run
             *               with complete redundancy.
             */
            l_err = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                   TOD_RT_TOPOLOGY_DATA,
                                   TOD_RT_NULL_FIRMWARE_REQUEST_PTR,
                                   0, 0, true);

            break;
        }

        // Default the response data size to the size of the
        // GenericFspMboxMessage_t minus the size of the
        // GenericFspMboxMessage_t's data.  The size of the
        // GenericFspMboxMessage_t's data will be added later
        uint32_t l_resp_data_size = sizeof(GenericFspMboxMessage_t) -
                                    sizeof(GenericFspMboxMessage_t::data);

        // Get the number of TodChipData items that will be returned.
        uint32_t l_nTodChips = TodSvcUtil::getMaxProcsOnSystem();

        // Add to the response data size iff there is data needing to be passed
        l_resp_data_size += (l_nTodChips * sizeof(TodChipData));

        // The response data size must be at a minimum the size of the
        // FSP generic message (sizeof(GenericFspMboxMessage_t))
        if (l_resp_data_size < sizeof(GenericFspMboxMessage_t))
        {
            l_resp_data_size = sizeof(GenericFspMboxMessage_t);
        }

        // Calculate the TOTAL size of hostInterfaces::hbrt_fw_msg which
        // means only adding hostInterfaces::HBRT_FW_MSG_BASE_SIZE to
        // the previous calculated response data size
        uint64_t l_resp_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                      l_resp_data_size;

        // Create the firmware_request response struct to receive data
        l_resp_fw_msg =
                     (hostInterfaces::hbrt_fw_msg *)malloc(l_resp_fw_msg_size);
        memset(l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Create the firmware_request request struct to send data
        uint64_t l_req_fw_msg_size = l_resp_fw_msg_size;
        l_req_fw_msg =
                   (hostInterfaces::hbrt_fw_msg *)malloc(l_req_fw_msg_size);

        // Initialize the firmware_request request struct
        l_req_fw_msg->generic_msg.initialize();

        // Populate the firmware_request request struct with given data
        l_req_fw_msg->io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg->generic_msg.msgq = MBOX::FSP_TOD_MSGQ;
        l_req_fw_msg->generic_msg.msgType =
                           GenericFspMboxMessage_t::MSG_TOD_TOPOLOGY_DATA;
        l_req_fw_msg->generic_msg.__req = GenericFspMboxMessage_t::REQUEST;

        // Trace out the request structure
        TRACFBIN(ISTEPS_TRACE::g_trac_isteps_trace,
                 INFO_MRK"TOD::Sending firmware_request",
                 l_req_fw_msg,
                 l_req_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        l_resp_fw_msg);

        if (l_err)
        {
            break;
        }

        // If we are here, then this was no error retrieving the data. Now,
        // just get the data from the returned struct and pass back to caller
        // Get a pointer to the data
        TodChipData* l_todChipData =
                   (TodChipData*)(&(l_resp_fw_msg->generic_msg.data));

        // Gather the data into the container provided
        for (size_t i = 0; i < l_nTodChips; ++i)
        {
            o_todChipData.push_back(l_todChipData[i]);
        }
    }
    while (0);

    // Release the firmware messages
    free(l_req_fw_msg);
    free(l_resp_fw_msg);
    l_req_fw_msg = l_resp_fw_msg = nullptr;

    TOD_EXIT("readTodProcDataFromFile");
    return l_err;
} // end readTodProcDataFromFile

// This code was ported over from the FIPS code -
//     fips910/Builds/b1005a_1742.910/
//                           src/hwsv/server/services/todservice/hwsvTodSvc.C
// It was decided that a port of the code is not needed but to hold onto
// the code since the majority of it has been ported.
// There are few places below that do not have a direct port from the FIPS code
// that need to be resolved.  I did not resolve them, because the port was
// abandoned and I did not want to waste any more time on it.
// In particular the call to mboxControlTodTopology() and the use of
// util::ScopeLock

#if 0
errlHndl_t resetBackupTopologyPortedCoded(
                            const TARGETING::TargetHandleList& i_badChipList,
                            bool i_informPhyp)
{
    TOD_ENTER("resetBackupTopology");

    errlHndl_t l_err = nullptr;
    bool l_deleteOnFailure = false;

    // l_backupConfig  will be set again after determining the non-active
    // topology from register values
    p9_tod_setup_tod_sel l_backupConfig = TOD_SECONDARY;

// NOTE:  Not sure if this is needed - no direct port
//    util::ScopeLock l_lock(iv_mutexTodAccess);
    do
    {
        p9_tod_setup_tod_sel l_activeConfig = TOD_PRIMARY;
        bool l_isTodRunning = false;
        TARGETING::Target*  l_mdmtOnActiveTopology = NULL;
        bool l_getTodRunningStatus =  true;

        // Get the currently active TOD configuration
        l_err = TOD::queryActiveConfig(l_activeConfig,
                                       l_isTodRunning,
                                       l_mdmtOnActiveTopology,
                                       l_getTodRunningStatus);

        if ( l_err )
        {
            TOD_ERR("Call to queryActiveConfig failed ");
            break;
        }

        if ( !l_isTodRunning )
        {
            TOD_ERR("TOD HW logic is not running,only use case of "
                    " resetBackup is when TOD is already running ");
            /*@
             * @errortype
             * @moduleid     TOD::TOD_RESET_BACKUP
             * @reasoncode   TOD::TOD_INVALID_ACTION
             * @userdata1    ChipTOD logic HW state, 1 means running, zero
             *               otherwise
             * @devdesc      Error: TOD HW logic is not running, only use case
             *               of resetBackup is when TOD is already running
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            TOD_RESET_BACKUP,
                                            TOD_INVALID_ACTION,
                                            l_isTodRunning);
            break;
        }

        l_backupConfig = (( l_activeConfig == TOD_PRIMARY) ?
                TOD_SECONDARY : TOD_PRIMARY );

        TOD_INF("Currently active topology ==> %s, and inactive ==> %s",
                TodSvcUtil::topologyTypeToString(l_activeConfig),
                TodSvcUtil::topologyTypeToString(l_backupConfig) );

        // PHYP needs to be informed that it won't have a
        // backup available for failover while we are reconfiguring it.
        // Not all the cases will require HWSV to inform PHYP because in some
        // of the case PHYP would have already initiated a failover before
        // PRD asks HWSV to reconfigure backup.
        // This indication is sent by PRD after the analysis of TOD error
        // If this method is initiated by PHYP's message to MBOX to reset the
        // backup topology this parameter will be always false.
        if ( i_informPhyp )
        {
            TOD_INF("Sending request to PHYP to disable the %s",
                    TodSvcUtil::topologyTypeToString(l_backupConfig));

// NOTE:  Not sure if this is needed - no direct port
//            l_err = mboxControlTodTopology(MBOX_DISABLE_TOPOLOGY,
//                    (( l_backupConfig == TOD_PRIMARY)?
//                     MBOX_PRIMARY_TOPOLOGY : MBOX_SECONDARY_TOPOLOGY));

            if ( l_err )
            {
                TOD_ERR("Request to PHYP for disabling the %s,that is "
                         "currently inactive failed",
                         TodSvcUtil::topologyTypeToString(l_backupConfig));
                break;
            }

            TOD_INF("Got response from PHYP, for the request to disable"
                    "inactive topology ");
        }


        // Mark configured state to false
        TOD::setConfigStatus(l_backupConfig,false);

        // Destroy the backup topology in case it exists, this is copy of
        // topology in volatile memory so it won't matter even if we fail
        // somewhere
        TOD::destroy(l_backupConfig);

        // Build blacklist information
        l_err = TOD::buildBlackList(i_badChipList);
        if ( l_err )
        {
            TOD_ERR("Call to buildBlackList failed ");
            break;
        }

        //Build the list of garded TOD targets
        l_err = TOD::buildGardedTargetsList();
        if ( l_err )
        {
            TOD_ERR("Call to buildGardedTargetsList failed");
            break;
        }

        // Build a set of datastructures to setup creation of the TOD topology
        l_err = TOD::buildTodDrawers(l_backupConfig);
        if ( l_err )
        {
            TOD_ERR("TOD setup failure: failed to build TOD drawers "
                    "for %s",
                    TodSvcUtil::topologyTypeToString(l_backupConfig));
            break;
        }

        // From here on if resetBackup failed, we will do the cleanup at the end
        l_deleteOnFailure = true;

        //Before we ask HwsvTodTopologyManager to create a new backup
        //topology let us make sure that we have MDMT set in TOD Controls for
        //the active topology, if there was RR then the copy of
        //topology in main memory would have got erased
        //MDMT of the active topology should be avoided while choosing MDMT for
        //backup
        if ( !(TOD::getConfigStatus(l_activeConfig)) &&
               TOD::getMDMT(l_activeConfig) )
        {
            l_err = Singleton<TodSvc>::instance().
                                  setActiveMdmtForResetBackup(l_activeConfig);

            if ( l_err )
            {
                TOD_ERR("setActiveMdmtForResetBackup failed for "
                        " %s",
                        TodSvcUtil::topologyTypeToString(l_activeConfig));
                break;
            }
        }


        // Ask the topology manager to setup the backup topology
        TodTopologyManager l_backupTopology(l_backupConfig);
        l_err = l_backupTopology.create();

        if ( l_err )
        {
            TOD_ERR("TOD setup failure: failed to create %s",
                    TodSvcUtil::topologyTypeToString(l_backupConfig));
            break;
        }

        l_backupTopology.dumpTopology();

        //Call hardware procedures to configure the TOD hardware logic for
        //the backup topology and to fill up the TOD regs.
        l_err = TOD::todSetupHwp(l_backupConfig);
        if ( l_err )
        {
            TOD_ERR("TOD setup failure: secondary topology setup HWP.");
            break;
        }

        // Save the TOD registers into the local data structures
        l_err = todSaveRegsHwp(l_backupConfig);
        if ( l_err )
        {
            TOD_ERR("todSaveRegsHwp failed for the %s",
                    TodSvcUtil::topologyTypeToString(l_backupConfig));
            break;
        }
        l_backupTopology.dumpTodRegs();

        // Sending request to PHYP to enable the inactive
        TOD_INF("Sending request to PHYP to enable the inactive %s",
                TodSvcUtil::topologyTypeToString(l_backupConfig));

        // Inform PHYP about the availability of backup topology
// NOTE:  Not sure if this is needed - no direct port
//        l_err = mboxControlTodTopology(MBOX_ENABLE_TOPOLOGY,
//             ( l_backupConfig == TOD_PRIMARY)? MBOX_PRIMARY_TOPOLOGY
//                : MBOX_SECONDARY_TOPOLOGY );
        if ( l_err )
        {
            TOD_ERR("Request to PHYP for disabling the %s,that is curently"
                    "backup, failed ",
                    TodSvcUtil::topologyTypeToString(l_backupConfig));
            break;

        }
        TOD_INF("Got response from PHYP, for the request to enable"
                "inactive topology ");

        // Write this information to the persistant file
        l_err = TOD::writeTodProcData(l_backupConfig);
        if( l_err )
        {
            TOD_ERR("TOD setup failure:Failed to write topology register data"
                    " to the file.");
            break;
        }

        // Backup successfully configured
        TOD::setConfigStatus(l_backupConfig, true);
    }
    while (0);

    if ( l_err && l_deleteOnFailure )
    {
        TOD::destroy(l_backupConfig);
    }
    TOD::clearGardedTargetsList();

    TOD_EXIT("resetBackupTopology");

    return l_err;
}  // end resetBackupTopologyPortedCoded
#endif

}  // end namespace TOD
