/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_fwnotify.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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

#include <sbeio/sbe_retry_handler.H>       // SbeRetryHandler
#include <util/runtime/rt_fwreq_helper.H>       // firmware_request_helper
#include <runtime/interface.h>             // g_hostInterfaces
#include <runtime/runtime_reasoncodes.H>   // MOD_RT_FIRMWARE_NOTIFY, etc
#include <errl/errlentry.H>                // ErrlEntry
#include <errl/errlmanager.H>              // errlCommit
#include <errl/hberrltypes.H>              // TWO_UINT32_TO_UINT64
#include <targeting/common/target.H>       // TargetHandle_t, getTargetFromHuid

using namespace TARGETING;
using namespace RUNTIME;
using namespace ERRORLOG;
using namespace MBOX;
using namespace SBEIO;

// Trace definition
extern trace_desc_t* g_trac_runtime;

/**
 * @brief The lower and upper bounds for the sequence ID.
 **/
const uint16_t SEQ_ID_MIN = 0x0000;
const uint16_t SEQ_ID_MAX =  0x7FFF;

/**
 * @brief Set the sequence ID to the minimum value
 **/
uint16_t SeqId_t::SEQ_ID = SEQ_ID_MIN;

/**
 * @brief Gets the next sequence ID.
 * @return The next sequence ID value within its lower and upper bound
 * @note This code is thread safe, no need for a mutex around this because
 *       HBRT never runs in multi-thread.
 *
 **/
uint16_t SeqId_t::getNextSeqId()
{
    if (SeqId_t::SEQ_ID < SEQ_ID_MAX)
    {
        ++SeqId_t::SEQ_ID;
    }
    else
    {
        SeqId_t::SEQ_ID = SEQ_ID_MIN;
    }

    return SeqId_t::SEQ_ID;
}

/**
 *  @brief Gets the current value of the sequence ID.
 *  @return The current value of the sequence ID.
 **/
uint16_t SeqId_t::getCurrentSeqId()
{
  return SeqId_t::SEQ_ID;
}

/**
 *  @brief Attempt an SBE recovery after an SBE error
 *  @param[in] uint64_t i_data Contains a plid (in the first 4 bytes)
 *                             and a HUID (in the last 4 bytes)
 *  @platform FSP, OpenPOWER
 **/
void sbeAttemptRecovery(uint64_t i_data)
{
   // Create a useful struct to get to the data
   // The data is expected to be a plid (in the first 4 bytes)
   // followed by a HUID (in the last 4 bytes).
   HbrtFspData_t *l_hbrtFspData = reinterpret_cast<HbrtFspData_t*>(&i_data);

   TRACFCOMP(g_trac_runtime, ENTER_MRK"sbeAttemptRecovery: plid:0x%X, "
             "HUID:0x%X", l_hbrtFspData->plid, l_hbrtFspData->userData);

    errlHndl_t l_err = nullptr;

    do
    {
        // Extract the target from the given HUID
        TargetHandle_t l_target =
                        Target::getTargetFromHuid(l_hbrtFspData->userData);

        // If HUID invalid, log error and quit
        if (nullptr == l_target)
        {
             TRACFCOMP(g_trac_runtime, ERR_MRK"sbeAttemptRecovery: "
                       "No target associated with HUID:0x%.8X",
                       l_hbrtFspData->userData);

            /*@
             * @errortype
             * @severity     ERRL_SEV_PREDICTIVE
             * @moduleid     MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode   RC_SBE_RT_INVALID_HUID
             * @userdata1    HUID of target
             * @userdata2    HWSV error log id (plid)
             * @devdesc      SBE error recovery attempt failed
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_SBE_RT_INVALID_HUID,
                                   l_hbrtFspData->userData,
                                   l_hbrtFspData->plid,
                                   true);
            break;
        }

        // Get the SBE Retry Handler, propagating the supplied PLID
        SbeRetryHandler l_SBEobj = SbeRetryHandler(SbeRetryHandler::
                        SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY,
                        l_hbrtFspData->plid);

        // Retry the recovery of the SBE
        l_SBEobj.main_sbe_handler(l_target);

        // Get the recovery results
        bool l_recoverySuccessful = l_SBEobj.getSbeRestart();

        if (nullptr == g_hostInterfaces ||
            nullptr == g_hostInterfaces->firmware_request)
        {
             TRACFCOMP(g_trac_runtime, ERR_MRK"sbeAttemptRecovery: "
                       "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity     ERRL_SEV_PREDICTIVE
             * @moduleid     MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode   RC_FW_REQUEST_RT_NULL_PTR
             * @userdata1    HUID of target
             * @userdata2    HWSV error log id (plid)
             * @devdesc      SBE error recovery attempt failed
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_FW_REQUEST_RT_NULL_PTR,
                                   l_hbrtFspData->userData,
                                   l_hbrtFspData->plid,
                                   true);

           break;
        }

        // Create the firmware_request request struct to send data
        hostInterfaces::hbrt_fw_msg l_req_fw_msg;
        uint64_t l_req_fw_msg_size = sizeof(l_req_fw_msg);

        // Initialize the firmware_request request struct
        l_req_fw_msg.generic_msg.initialize();

        // Populate the firmware_request request struct with given data
        l_req_fw_msg.io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg.generic_msg.msgq = GenericFspMboxMessage_t::MSG_SBE_ERROR;
        l_req_fw_msg.generic_msg.__req = GenericFspMboxMessage_t::REQUEST;
        l_req_fw_msg.generic_msg.data = i_data;

        // Set msgType based on recovery success or failure
        if (l_recoverySuccessful)
        {
            l_req_fw_msg.generic_msg.msgType =
                             GenericFspMboxMessage_t::MSG_SBE_RECOVERY_SUCCESS;
        }
        else
        {
            l_req_fw_msg.generic_msg.msgType =
                              GenericFspMboxMessage_t::MSG_SBE_RECOVERY_FAILED;
        }

        // Create the firmware_request response struct to receive data
        // NOTE: For messages to the FSP the response size must match
        // the request size
        // No need to check for expected response size > request
        // size because they use the same base structure
        hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
        uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
        memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Trace out the request structure
        TRACFBIN( g_trac_runtime, INFO_MRK"Sending firmware_request",
                  &l_req_fw_msg,
                  l_req_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        &l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        &l_resp_fw_msg);

        if (l_err)
        {
            break;
        }
    } while(0);

    if (l_err)
    {
       //Commit the error if it exists
       errlCommit(l_err, RUNTIME_COMP_ID);
    }

    TRACFCOMP(g_trac_runtime, EXIT_MRK"sbeAttemptRecovery");
}

/**
 * @see  src/include/runtime/interface.h for definition of call
 *
 */
void firmware_notify( uint64_t i_len, void *i_data )
{
   TRACFCOMP(g_trac_runtime, ENTER_MRK"firmware_notify: "
             "i_len:%d", i_len );

   TRACFBIN(g_trac_runtime, "firmware_notify: i_data", i_data, i_len);

    errlHndl_t l_err = nullptr;

    // Flag to detect an invlaid/unknown/not used message
    bool l_badMessage = false;

    // Capture the unique message data associated with errant message
    uint64_t l_userData1(0), l_userData2(0);

    do
    {
        // make sure the length of the data is not less than the
        // data necessary to determine type of message
        if (i_len < hostInterfaces::HBRT_FW_MSG_BASE_SIZE)
        {
           l_badMessage = true;

           TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: "
               "Received a non hostInterfaces::hbrt_fw_msg data stream" );

           break;
        }

        // Cast the data to an hbrt_fw_msg to extract the input type
        hostInterfaces::hbrt_fw_msg* l_hbrt_fw_msg =
                       static_cast<hostInterfaces::hbrt_fw_msg*>(i_data);
        switch (l_hbrt_fw_msg->io_type)
        {

           case hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ:
           {

              // Extract the message type
              switch(l_hbrt_fw_msg->generic_msg.msgType)
              {

                 case GenericFspMboxMessage_t::MSG_SBE_ERROR:
                      sbeAttemptRecovery(l_hbrt_fw_msg->generic_msg.data);

                 break;

                 default:
                    {
                       l_badMessage = true;

                       TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: "
                              "Unknown FSP message type:0x%.8X, "
                              "message queue id:0x%.8X, seqNum:%d ",
                              l_hbrt_fw_msg->generic_msg.msgq,
                              l_hbrt_fw_msg->generic_msg.msgType,
                              l_hbrt_fw_msg->generic_msg.seqnum);

                       // Pack user data 1 with message input type and
                       // firmware request message sequence number
                       l_userData1 = TWO_UINT32_TO_UINT64(
                                           l_hbrt_fw_msg->io_type,
                                           l_hbrt_fw_msg->generic_msg.seqnum);

                       // Pack user data 2 with message queue and message type
                       l_userData2 = TWO_UINT32_TO_UINT64(
                                            l_hbrt_fw_msg->generic_msg.msgq,
                                            l_hbrt_fw_msg->generic_msg.msgType);
                    }

                 break;  // END default

              }  // END switch(l_genericMsg->msgType)
           } // END case HBRT_FW_MSG_HBRT_FSP_REQ:

           break;

           default:
               {
                  l_badMessage = true;

                  TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: "
                            "Unknown firmware request input type:0x%.8X ",
                            l_hbrt_fw_msg->io_type);

                  l_userData1 = l_hbrt_fw_msg->io_type;
               }  // END default

               break;

        };  // END switch (l_hbrt_fw_msg->io_type)

    } while(0);

    if (l_badMessage)
    {
       /*@
        * @errortype
        * @severity     ERRL_SEV_PREDICTIVE
        * @moduleid     MOD_RT_FIRMWARE_NOTIFY
        * @reasoncode   RC_FW_NOTIFY_RT_INVALID_MSG
        * @userdata1[0:31]  Firmware Request type
        * @userdata1[32:63] Sequence number (FSP msg)
        * @userdata2[0:31]  MBOX message type (FSP msg)
        * @userdata2[32:63] Message Type (FSP msg)
        * @devdesc      Error with Firmware Notify request
        */
       l_err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_RT_FIRMWARE_NOTIFY,
                             RC_FW_NOTIFY_RT_INVALID_MSG,
                             l_userData1,
                             l_userData2,
                             true);

      if (i_len > 0)
      {
         l_err->addFFDC(RUNTIME_COMP_ID,
                        i_data,
                        i_len,
                        0, 0, false );
      }

      l_err->collectTrace( "FW_REQ", 256);
    }

    if (l_err)
    {
       //Commit the error if it exists
       errlCommit(l_err, RUNTIME_COMP_ID);
    }

   TRACFCOMP(g_trac_runtime, EXIT_MRK"firmware_notify");
};

struct registerFwNotify
{
    registerFwNotify()
    {
        getRuntimeInterfaces()->firmware_notify = &firmware_notify;
    }
};

registerFwNotify g_registerFwNotify;
