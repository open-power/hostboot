/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_fwnotify.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_fwnotify.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <runtime/interface.h>             // firmware_notify
#include <runtime/runtime_reasoncodes.H>   // MOD_RT_FIRMWARE_NOTIFY, etc
#include <errl/errlentry.H>                // ErrlEntry
#include <errl/errlmanager.H>              // errlCommit
#include <targeting/common/target.H>       // TargetHandle_t, getTargetFromHuid

using namespace TARGETING;
using namespace RUNTIME;
using namespace ERRORLOG;
using namespace MBOX;
using namespace SBEIO;

trace_desc_t* g_trac_hwsv = nullptr;
TRAC_INIT(&g_trac_hwsv, "HWSV_TRACE", 4*KILOBYTE);

/**
  * @brief The lower and upper bounds for the sequence ID.
  **/
const uint16_t GFMM_SEQ_ID_MIN = 0x0000;
const uint16_t GFMM_SEQ_ID_MAX =  0x7FFF;

/**
  * @brief Set the sequence ID to the minimum value
  **/
uint16_t SeqId_t::GFMM_SEQ_ID = GFMM_SEQ_ID_MIN;

/**
 *  @brief Gets the next sequence ID.
 *  @return The next sequence ID value within it's lower and upper bound
 **/
uint16_t SeqId_t::getNextSeqId()
{
    if (SeqId_t::GFMM_SEQ_ID < GFMM_SEQ_ID_MAX)
    {
        ++SeqId_t::GFMM_SEQ_ID;
    }
    else
    {
        SeqId_t::GFMM_SEQ_ID = GFMM_SEQ_ID_MIN;
    }

    return SeqId_t::GFMM_SEQ_ID;
}

/**
 *  @brief Gets the current value of the sequence ID.
 *  @return The current value of the sequence ID.
 **/
uint16_t SeqId_t::getCurrentSeqId()
{
  return SeqId_t::GFMM_SEQ_ID;
}

/**
 *  @brief Attempt an SBE recovery after an SBE error
 *  @param[in] uint64_t i_data Contains a plid (in the first 4 bytes)
 *                             and a HUID (in the last 4 bytes)
 *  @platform FSP, OpenPOWER
 **/
void sbeAttemptRecovery(uint64_t i_data)
{
    errlHndl_t l_err = nullptr;

    do
    {
        // Create a useful structure to get to the data
        // The data is expected to be a plid (in the first 4 bytes)
        // followed by a HUID (in the last 4 bytes).
        struct sbeErrorData_t
        {
            uint32_t plid;
            uint32_t huid;
        } PACKED ;

        sbeErrorData_t *l_sbeErrorDataReq = (sbeErrorData_t*)(&i_data);

        // Extract the target from the given HUID
        TargetHandle_t l_target =
                        Target::getTargetFromHuid(l_sbeErrorDataReq->huid);

        // If HUID invalid, log error and quit
        if (nullptr == l_target)
        {
             TRACFCOMP( g_trac_hwsv, "firmware_notify: No target assoicated "
                       "with HUID:0x%.8X", l_sbeErrorDataReq->huid);
            /*@
             * @errortype    ERRL_SEV_PREDICTIVE
             * @moduleid     RUNTIME::MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode   RUNTIME::RC_SBE_RT_INVALID_HUID
             * @userdata1    HUID of target
             * @userdata2    HWSV error log id (plid)
             * @devdesc      SBE error recovery attempt failed
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_SBE_RT_INVALID_HUID,
                                   l_sbeErrorDataReq->huid,
                                   l_sbeErrorDataReq->plid,
                                   true);
            break;
        }

        // Make the call to SbeExtractDD to attempt SBE recovery
        // Get the SBE Retry Handler
        SbeRetryHandler l_SBEobj = SbeRetryHandler(SbeRetryHandler::
                        SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY);

        // Retry the recovery of the SBE
        l_SBEobj.main_sbe_handler(l_target);

        // Get the recovery results
        bool l_recoverySuccessful = l_SBEobj.getSbeRestart();

        if (nullptr == g_hostInterfaces ||
            nullptr == g_hostInterfaces->firmware_request)
        {
             TRACFCOMP( g_trac_hwsv, "firmware_notify: Hypervisor "
                       "firmware_request interface not linked");

            /*@
             * @errortype    ERRL_SEV_PREDICTIVE
             * @moduleid     RUNTIME::MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode   RUNTIME::RC_FW_REQUEST_RT_NULL_PTR
             * @userdata1    HUID of target
             * @userdata2    HWSV error log id (plid)
             * @devdesc      SBE error recovery attempt failed
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_FW_REQUEST_RT_NULL_PTR,
                                   l_sbeErrorDataReq->huid,
                                   l_sbeErrorDataReq->plid,
                                   true);


           break;
        }

        // Create the firmware_request request structure to send data
        hostInterfaces::hbrt_fw_msg l_req_fw_msg;
        memset(&l_req_fw_msg, 0, sizeof(l_req_fw_msg));

        // Set the data for the request
        l_req_fw_msg.io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg.generic_msg.initialize();
        l_req_fw_msg.generic_msg.msgq = GFMM_MSG_SBE_ERROR;
        l_req_fw_msg.generic_msg.__req = GFMM_REQUEST;
        l_req_fw_msg.generic_msg.__onlyError = GFMM_NOT_ERROR_ONLY;
        l_req_fw_msg.generic_msg.data = i_data;

        if (l_recoverySuccessful)
        {
            l_req_fw_msg.generic_msg.msgType= GFMM_MSG_SBE_RECOVERY_SUCCESS;
        }
        else
        {
            l_req_fw_msg.generic_msg.msgType = GFMM_MSG_SBE_RECOVERY_FAILED;
        }

        // Create the firmware_request response structure to receive data
        hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
        size_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
        memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

        size_t rc = g_hostInterfaces->firmware_request(sizeof(l_req_fw_msg),
                                                       &l_req_fw_msg,
                                                       &l_resp_fw_msg_size,
                                                       &l_resp_fw_msg);

        // Error log id
        uint32_t l_errPlid(0);

        sbeErrorData_t *l_sbeErrorDataResp =
                   (sbeErrorData_t*)&(l_resp_fw_msg.generic_msg.data);

        // Capture the error log ID if any
        // The return code (rc) may return OK, but there still may be an issue
        // with the HWSV code on the FSP.
        if ((hostInterfaces::HBRT_FW_MSG_HBRT_FSP_RESP
                                                  == l_resp_fw_msg.io_type) &&
            (GFMM_ERROR_ONLY == l_resp_fw_msg.generic_msg.__onlyError) &&
            (0 != l_sbeErrorDataResp->plid) )
        {
            l_errPlid = l_sbeErrorDataResp->plid;
        }

        // Gather up the error data and create an error log out of it
        if (rc || l_errPlid)
        {
            /*@
             * @errortype        ERRL_SEV_PREDICTIVE
             * @moduleid         RUNTIME::MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode       RUNTIME::RC_SBE_RT_RECOVERY_ERR
             * @userdata1[0:31]  Firmware Request return code
             * @userdata1[32:63] HWSV error log id (plid)
             * @userdata2[0:31]  MBOX message type
             * @userdata2[32:63] Message Tyepe
             * @devdesc          SBE error recovery attempt failed
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_SBE_RT_RECOVERY_ERR,
                                   TWO_UINT32_TO_UINT64(rc, l_errPlid),
                                   TWO_UINT32_TO_UINT64(
                                   l_resp_fw_msg.generic_msg.msgq,
                                   l_resp_fw_msg.generic_msg.msgType),
                                   true);

            l_err->addFFDC( RUNTIME_COMP_ID,
                            &l_resp_fw_msg,
                            l_resp_fw_msg_size,
                            0, 0, false );

            if (sizeof(l_req_fw_msg) > 0)
            {
                l_err->addFFDC( RUNTIME_COMP_ID,
                                &l_req_fw_msg,
                                sizeof(l_req_fw_msg),
                                0, 0, false );
            }

            l_err->collectTrace( "SBE", 256);

            if (l_errPlid)
            {
                l_err->plid(l_errPlid);
            }

            break;
        }
    } while(0);

    if (l_err)
    {
       //Commit the error if it exists
       errlCommit(l_err, RUNTIME_COMP_ID);
    }
}

/**
 * @brief Receive an async notification from firmware
 * @param[in] i_len   length of notification data
 * @param[in] i_data  notification data
 * @platform FSP, OpenPOWER
 */
void firmware_notify( uint64_t i_len, void *i_data )
{
    errlHndl_t l_err = nullptr;

    do
    {
        // make sure the length of the data is not less than the
        // structure we are expecting to receive
        if (i_len < sizeof(GenericFspMboxMessage_t))
        {
            TRACFCOMP( g_trac_hwsv,
               "firmware_notify: Received a non GenericFspMboxMessage "
               "data stream" );

            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode   RUNTIME::RC_FW_NOTIFY_RT_INVALID_MSG
             * @userdata1    Unused
             * @userdata2    Unused
             * @devdesc      Error with Firmware Notify request
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_FW_NOTIFY_RT_INVALID_MSG,
                                   0, 0, true);
            break;
        }

        // Cast the data to the structure we wish to parse
        GenericFspMboxMessage_t* genericMsg =
                       static_cast<GenericFspMboxMessage_t*>(i_data);

        // Do function based on message type (msgType)
        switch(genericMsg->msgType)
        {
           case GFMM_MSG_SBE_ERROR: sbeAttemptRecovery(genericMsg->data);
               break;

           default:
               {
                   TRACFCOMP( g_trac_hwsv, "firmware_notify: Unknown "
                              "message type:0x%.8X, message queue id:0x%.8X ",
                              genericMsg->msgq, genericMsg->msgType);

                   /*@
                    * @errortype
                    * @moduleid     RUNTIME::MOD_RT_FIRMWARE_NOTIFY
                    * @reasoncode   RUNTIME::RC_FW_NOTIFY_RT_INVALID_MSG_TYPE
                    * @userdata1    Message Queue ID
                    * @userdata2    Message Type
                    * @devdesc      Error with Firmware Notify request
                    */
                   l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                          MOD_RT_FIRMWARE_NOTIFY,
                                          RC_FW_NOTIFY_RT_INVALID_MSG_TYPE,
                                          genericMsg->msgq,
                                          genericMsg->msgType,
                                          true);
               }
               break;
        };

    } while(0);

    if (l_err)
    {
       //Commit the error if it exists
       errlCommit(l_err, RUNTIME_COMP_ID);
    }
};

struct registerFwNotify
{
    registerFwNotify()
    {
        getRuntimeInterfaces()->firmware_notify = &firmware_notify;
    }
};

registerFwNotify g_registerFwNotify;
