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

#include <runtime/interface.h>     // g_hostInterfaces
#include <tod_init_reasoncodes.H>  // TOD_RT_TOPOLOGY_RESET_BACKUP, etc

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

    // Put the handle to the firmware request out here
    // so it is easier to free later
    hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;

    do
    {
        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            /*@
             * @errortype
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid     TOD::TOD_RT_TOPOLOGY_RESET_BACKUP
             * @reasoncode   TOD::TOD_RT_NULL_FIRMWARE_REQUEST_PTR
             * @devdesc      Host interfaces are not initialized
             * @custdesc     An internal error occurred. This will force the
             *               Time of Day function to run with complete
             *               redundancy.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   TOD::TOD_RT_TOPOLOGY_RESET_BACKUP,
                                   TOD::TOD_RT_NULL_FIRMWARE_REQUEST_PTR,
                                   0, 0, true);

            break;
        }

        // First, I'll present the format of the data
        // to help with the understanding of the code that follows
        // The format of the data to be sent, according to the document
        // "Handle PRD Request for resetting backup TOD topology" is as follows
        // Ordinal ID - 0xFFFFFFFF means no OSC to be avoided
        // HUID of the node - This field should be considered only if Ordinal
        //                    ID is NOT set to 0xFFFFFFFF otherwise it is set
        //                    to 0
        // HUID of the first processor
        // HUID of the second processor, etc

        // Flag to determine if the OSC data will be added to the data
        bool l_addOscData = (0xFFFFFFFF != i_oscPos) &&
                            (nullptr != i_procOscTgt);

        // Calculate the size of the data that is being added to the
        // generic struct
        size_t l_data_size = 0;

        // Add to the size iff there is data needing to be passed
        if (i_badChipList.size() > 0)
        {
            // if the bad chip list has any items then increase size to
            // accommodate for an ordinal ID and a HUID, regardless if
            // they have relevant data or not, because they are expected
            // before the HUID list.
            l_data_size += (MSG_OSC_SIZE_OF_DETAILS * sizeof(uint32_t)) +
                           (i_badChipList.size() * sizeof(uint32_t));
        }
        else if (l_addOscData)
        {
            // if there is a valid OSC then accommodate for an ordinal ID
            // and HUID of node, but don't need space for HUID list because,
            // if we are here, the list is empty
            l_data_size += (MSG_OSC_SIZE_OF_DETAILS * sizeof(uint32_t));
        }

        // Update the data size with the size of the generic msg struct
        if (l_data_size < sizeof(hostInterfaces::hbrt_fw_msg::generic_msg.data))
        {
            // If the current size of the data is less than the size of the
            // data within the generic message (GenericFspMboxMessage_t.data),
            // then default the data size to just the generic message because
            // the size of the data to be passed in
            // GenericFspMboxMessage_t.dataSize has be at the minimum - the
            // size of the generic message (sizeof(GenericFspMboxMessage_t)).
            l_data_size = sizeof(hostInterfaces::hbrt_fw_msg::generic_msg);
        }
        else
        {
            // If the current size of the data is greater than the size of the
            // data within the generic message (GenericFspMboxMessage_t.data),
            // then add the size of the generic message minus the size of
            // generic message's data.
            l_data_size += sizeof(hostInterfaces::hbrt_fw_msg::generic_msg) -
                         sizeof(hostInterfaces::hbrt_fw_msg::generic_msg.data);
        }

        // At last.  Calculate the TOTAL size of hostInterfaces::hbrt_fw_msg
        // which means only adding hostInterfaces::HBRT_FW_MSG_BASE_SIZE to
        // the previous calculated data size
        size_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                   l_data_size;

        // Create the firmware request structure to carry the TOD data
        l_req_fw_msg =(hostInterfaces::hbrt_fw_msg *)malloc(l_req_fw_msg_size);

        // Set the data for the request
        l_req_fw_msg->io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg->generic_msg.initialize();
        l_req_fw_msg->generic_msg.dataSize = l_data_size;
        l_req_fw_msg->generic_msg.msgq = MBOX::FSP_TOD_MSGQ;
        l_req_fw_msg->generic_msg.msgType = (false == i_informPhyp ?
                           GFMM_MSG_TOD_BACKUP_RESET:
                           GFMM_MSG_TOD_BACKUP_RESET_INFORM_PHYP);
        l_req_fw_msg->generic_msg.__req = GFMM_REQUEST;
        l_req_fw_msg->generic_msg.__onlyError = GFMM_NOT_ERROR_ONLY;

        // A convenient way to populate the data
        uint32_t* l_dataPtr = (uint32_t*)&(l_req_fw_msg->generic_msg.data);

        if (i_badChipList.size() > 0)
        {
            // set the ordinal ID
            l_dataPtr[MSG_OSC_ORDINAL_ID_LOC] = i_oscPos;

            // attach the HUIDs from bad chip list to end of structure
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
                 * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid     TOD::TOD_RT_TOPOLOGY_RESET_BACKUP
                 * @reasoncode   TOD::TOD_INVALID_TARGET
                 * @devdesc      No parent for processor osc target
                 * @custdesc     An internal error occurred. This will force
                 *               the Time of Day function to run with complete
                 *               redundancy.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   TOD::TOD_RT_TOPOLOGY_RESET_BACKUP,
                                   TOD::TOD_INVALID_TARGET,
                                   0, 0, true);

                break;
            }
        }

        // No data is returning from the call, just capture any errors
        hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
        size_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);

        // Clear the response structure
        memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Send the data via a firmware request
        size_t rc = g_hostInterfaces->firmware_request(
                                      l_req_fw_msg_size, l_req_fw_msg,
                                      &l_resp_fw_msg_size, &l_resp_fw_msg);

        // Error log id
        uint32_t l_errPlid(0);

        // Create a useful structure to get to the PLID
        // The PLID is expected to be in the first 4 bytes of the data
        // if it exists
        struct hbrtFspRespData_t
        {
            uint32_t plid;
            uint32_t otherData;
        } PACKED ;

        hbrtFspRespData_t *l_hbrtFspRespData =
                   (hbrtFspRespData_t*)&(l_resp_fw_msg.generic_msg.data);

        // Capture the error log ID if any
        // The return code (rc) may return OK, but there still may be an issue
        // with the HWSV code on the FSP.
        if ((hostInterfaces::HBRT_FW_MSG_HBRT_FSP_RESP
                                                  == l_resp_fw_msg.io_type) &&
           (GFMM_ERROR_ONLY == l_resp_fw_msg.generic_msg.__onlyError) &&
           (0 != l_hbrtFspRespData->plid) )
        {
            l_errPlid = l_hbrtFspRespData->plid;
        }

        // Gather up the error data and create an error log out of it
        if (rc || l_errPlid)
        {
            /*@
             * @errortype
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         TOD::TOD_RT_TOPOLOGY_RESET_BACKUP
             * @reasoncode       TOD::TOD_RT_TOPOLOGY_RESET_BACKUP_ERR
             * @userdata1[0..31] Hypervisor return code
             * @userdata1[32:63] HWSV error log id (if any)
             * @userdata2[0:31]  MBOX message type
             * @userdata2[32:63] TOD message type
             * @devdesc          TOD reset backup topology failed
             * @custdesc         An internal error occurred. This will force
             *                   the Time of Day function to run with complete
             *                   redundancy.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   TOD::TOD_RT_TOPOLOGY_RESET_BACKUP,
                                   TOD::TOD_RT_TOPOLOGY_RESET_BACKUP_ERR,
                                   TWO_UINT32_TO_UINT64(rc, l_errPlid),
                                   TWO_UINT32_TO_UINT64(
                                   l_req_fw_msg->generic_msg.msgq,
                                   l_req_fw_msg->generic_msg.msgType),
                                   true);

            l_err->addFFDC( ISTEP_COMP_ID,
                            &l_resp_fw_msg,
                            l_resp_fw_msg_size,
                            0, 0, false );

            if (sizeof(l_req_fw_msg) > 0)
            {
                l_err->addFFDC( ISTEP_COMP_ID,
                                l_req_fw_msg,
                                sizeof(l_req_fw_msg),
                                0, 0, false );
            }

            l_err->collectTrace( "TOD", 256);

            if (l_errPlid)
            {
                l_err->plid(l_errPlid);
            }

            break;
        }
    }
    while (0);

    // The firmware request message is no longer needed - free the data
    free(l_req_fw_msg);

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

    // Put the handle to the firmware response out here
    // so it is easier to free later
    hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

    do
    {
        // clear the out data, regardless of the code to follow
        o_todChipData.clear();

        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            /*@
             * @errortype
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid     TOD::TOD_RT_TOPOLOGY_DATA
             * @reasoncode   TOD::TOD_RT_NULL_FIRMWARE_REQUEST_PTR
             * @devdesc      Host interfaces are not initialized
             * @custdesc     An internal error occurred. This will force the
             *               Time of Day function to run with complete
             *               redundancy.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   TOD::TOD_RT_TOPOLOGY_DATA,
                                   TOD::TOD_RT_NULL_FIRMWARE_REQUEST_PTR,
                                   0, 0, true);

            break;
        }

        // Create the firmware request structure.  No data is being
        // passed via this structure so this step may be moot.
        // Maybe just passing size of 0 and a null pointer would be better?
        hostInterfaces::hbrt_fw_msg l_req_fw_msg;
        size_t l_req_fw_msg_size = sizeof(l_req_fw_msg);

        // Set the data for the request
        l_req_fw_msg.io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg.generic_msg.initialize();
        l_req_fw_msg.generic_msg.msgq = MBOX::FSP_TOD_MSGQ;
        l_req_fw_msg.generic_msg.msgType = GFMM_MSG_TOD_TOPOLOGY_DATA;
        l_req_fw_msg.generic_msg.__req = GFMM_REQUEST;
        l_req_fw_msg.generic_msg.__onlyError = GFMM_NOT_ERROR_ONLY;

        // Calculate the size of the response - the number
        // of TodChipData items that will be returned.
        uint32_t l_nTodChips = TodSvcUtil::getMaxProcsOnSystem();

        // Calculate the size of the data that is being added to the
        // generic struct
        size_t l_data_size = (l_nTodChips * sizeof(TodChipData));

        // Update the data size with the size of the generic msg struct
        if (l_data_size < sizeof(hostInterfaces::hbrt_fw_msg::generic_msg.data))
        {
            // If the current size of the data is less than the size of the
            // data within the generic message (GenericFspMboxMessage_t.data),
            // then default the data size to just the generic message because
            // the size of the data to be passed in
            // GenericFspMboxMessage_t.dataSize has be at the minimum - the
            // size of the generic message (sizeof(GenericFspMboxMessage_t)).
            l_data_size = sizeof(hostInterfaces::hbrt_fw_msg::generic_msg);
        }
        else
        {
            // If the current size of the data is greater than the size of the
            // data within the generic message (GenericFspMboxMessage_t.data),
            // then add the size of the generic message minus the size of
            // generic message's data.
            l_data_size += sizeof(hostInterfaces::hbrt_fw_msg::generic_msg) -
                         sizeof(hostInterfaces::hbrt_fw_msg::generic_msg.data);
        }

        // At last.  Calculate the TOTAL size of hostInterfaces::hbrt_fw_msg
        // which means only adding hostInterfaces::HBRT_FW_MSG_BASE_SIZE to
        // the previous calculated data size
        size_t l_resp_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                   l_data_size;

        // Create the firmware response structure to return the data
        l_resp_fw_msg =
                     (hostInterfaces::hbrt_fw_msg *)malloc(l_resp_fw_msg_size);

        // Clear the response structure
        memset(l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Send the data via a firmware request
        size_t rc = g_hostInterfaces->firmware_request(
                                     l_req_fw_msg_size, &l_req_fw_msg,
                                     &l_resp_fw_msg_size, l_resp_fw_msg);

        // Error log id
        uint32_t l_errPlid(0);

        // Create a useful structure to get to the PLID
        // The PLID is expected to be in the first 4 bytes of the data
        struct hbrtFspRespData_t
        {
            uint32_t plid;
            uint32_t otherData;
        } PACKED ;

        hbrtFspRespData_t *l_hbrtFspRespData =
                   (hbrtFspRespData_t*)&(l_resp_fw_msg->generic_msg.data);

        // Capture the error log ID if any
        // The return code (rc) may return OK, but there still may be an issue
        // with the HWSV code on the FSP.
        if ((hostInterfaces::HBRT_FW_MSG_HBRT_FSP_RESP
                                                  == l_resp_fw_msg->io_type) &&
            (GFMM_ERROR_ONLY == l_resp_fw_msg->generic_msg.__onlyError) &&
            (0 != l_hbrtFspRespData->plid) )
        {
            l_errPlid = l_hbrtFspRespData->plid;
        }

        // Gather up the error data and create an error log out of it
        if (rc || l_errPlid)
        {
            /*@
             * @errortype
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         TOD::TOD_RT_TOPOLOGY_DATA
             * @reasoncode       TOD::TOD_RT_TOPOLOGY_DATA_ERR
             * @userdata1[0..31] Hypervisor return code
             * @userdata1[32:63] HWSV error log id (if any)
             * @userdata2[0:31]  MBOX message type
             * @userdata2[32:63] TOD message type
             * @devdesc          TOD read proc data failed
             * @custdesc         An internal error occurred. This will force
             *                   the Time of Day function to run with complete
             *                   redundancy.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   TOD::TOD_RT_TOPOLOGY_DATA,
                                   TOD::TOD_RT_TOPOLOGY_DATA_ERR,
                                   TWO_UINT32_TO_UINT64(rc, l_errPlid),
                                   TWO_UINT32_TO_UINT64(
                                   l_req_fw_msg.generic_msg.msgq,
                                   l_req_fw_msg.generic_msg.msgType),
                                   true);

            if (l_resp_fw_msg_size > 0)
            {
                l_err->addFFDC( ISTEP_COMP_ID,
                                l_resp_fw_msg,
                                l_resp_fw_msg_size,
                                0, 0, false );
            }

            l_err->addFFDC( ISTEP_COMP_ID,
                            &l_req_fw_msg,
                            sizeof(l_req_fw_msg),
                            0, 0, false );

            l_err->collectTrace( "TOD", 256);

            if (l_errPlid)
            {
                l_err->plid(l_errPlid);
            }

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

    // Free the memory associated with the response
    free(l_resp_fw_msg);

    TOD_EXIT("readTodProcDataFromFile");
    return l_err;
} // end readTodProcDataFromFile

// This code was ported over from the FIPS code -
//     /esw/fips910/Builds/b1005a_1742.910/
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
