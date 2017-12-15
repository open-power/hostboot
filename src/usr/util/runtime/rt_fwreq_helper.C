/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_fwreq_helper.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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

#include <util/runtime/rt_fwreq_helper.H>
#include <runtime/interface.h>            // hostInterfaces
#include <runtime/runtime_reasoncodes.H>  // MOD_RT_FIRMWARE_REQUEST, etc
#include <errl/errlmanager.H>             // errlCommit

using namespace ERRORLOG;
using namespace RUNTIME;
using namespace TRACE;

// Trace definition
trace_desc_t *g_trac_runtime = nullptr;
TRAC_INIT(&g_trac_runtime, RUNTIME_COMP_NAME, KILOBYTE);


/*****************************************************************************/
// firmware_request_helper
/*****************************************************************************/
errlHndl_t firmware_request_helper(uint64_t i_reqLen,   void *i_req,
                                   uint64_t* o_respLen, void *o_resp)
{
   errlHndl_t l_err = nullptr;

   // Cast incoming parameters to useful structs
   hostInterfaces::hbrt_fw_msg *l_req_fw_msg =
                    reinterpret_cast<hostInterfaces::hbrt_fw_msg *>(i_req);
   hostInterfaces::hbrt_fw_msg *l_resp_fw_msg =
                    reinterpret_cast<hostInterfaces::hbrt_fw_msg *>(o_resp);

   // Capture the Reset/Reload error log if it happens
   bool l_isResetReloadErr = false;

   // Retry the firmware_request call if the call is made while the
   // FSP is doing a reset/reload.
   // If there is a reset/reload error create an error log and try again.
   // If subsequent calls cause an error, commit the reset/reload error,
   // and return the latest error back to the user.
   // If there is an initial error that IS NOT a reset/reload error
   // then break out of the retry loop and return error to user.
   // If no error (a successful call) then delete any previous error
   // (don't want to confuse caller) and break out of retry loop
   for (int i = 0; i <= HBRT_FW_REQUEST_RETRIES; ++i)
   {
      // Make the firmware_request call
      int rc = g_hostInterfaces->firmware_request(i_reqLen,  i_req,
                                                  o_respLen, o_resp);

      // Not all request messages that fail require an error log, most do
      bool l_createErrorLog = true;

      // The error log user data 1 and user data 2 will change
      // based on response message type
      uint64_t l_userData1(0), l_userData2(0);

      // Error with FSP resetting and/or reloading? If so, then retry
      if (HBRT_RC_FSPDEAD == rc)
      {
         // This is a reset/reload err
         l_isResetReloadErr = true;

         // Commit any previous errors
         if (l_err)
         {
            // Commit any previous error log
            errlCommit(l_err, RUNTIME_COMP_ID);
         }

         // Print trace info based on request message and populate error
         // log user data 1 and user data 2 based on request message
         switch (l_req_fw_msg->io_type)
         {
            case hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE:
                 {
                    TRACFCOMP(g_trac_runtime,
                           ERR_MRK"FSP is doing a reset/reload, "
                           "HCODE update failed. "
                           "retry:%d/%d, rc:%d, io_type:%d, chipId:0x%llX, "
                           "section:0x%X, operation:0x%X, scomAddr:0x%llX, "
                           "scomData:0x%llX",
                           i,
                           HBRT_FW_REQUEST_RETRIES,
                           rc,
                           l_req_fw_msg->io_type,
                           l_req_fw_msg->req_hcode_update.i_chipId,
                           l_req_fw_msg->req_hcode_update.i_section,
                           l_req_fw_msg->req_hcode_update.i_operation,
                           l_req_fw_msg->req_hcode_update.i_scomAddr,
                           l_req_fw_msg->req_hcode_update.i_scomData);

                    // Pack user data 1 with Hypervisor return code and
                    // firmware request message type
                    l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                                       l_req_fw_msg->io_type);

                    // Pack user data 2 with HCODE scom address and
                    // HCODE scom data
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                  l_req_fw_msg->req_hcode_update.i_scomAddr,
                                  l_req_fw_msg->req_hcode_update.i_scomData);
                 }
            break;//END case hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE:

            case hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG:
                 {
                    TRACFCOMP(g_trac_runtime,
                              ERR_MRK"FSP is doing a reset/reload, "
                                     "sending error log to FSP failed. "
                                     "retry:%d/%d, rc:%d, plid:0x%08x",
                              i,
                              HBRT_FW_REQUEST_RETRIES,
                              rc,
                              l_req_fw_msg->error_log.i_plid);

                    // Don't create an error log for this request type
                    l_createErrorLog = false;
                 }
            break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG:

            case hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ:
                 {
                    TRACFCOMP(g_trac_runtime,
                             "FSP is doing a reset/reload, "
                             "doing a VPD write failed. "
                             "retry:%d/%d, rc:%d, io_type:%d, dataSize:%d, "
                             "seqnum:0x%X, msgq:0x%X, msgType:0x%X, __req:%d, "
                             "__onlyError:%d",
                             i,
                             HBRT_FW_REQUEST_RETRIES,
                             rc,
                             l_req_fw_msg->io_type,
                             l_req_fw_msg->generic_msg.dataSize,
                             l_req_fw_msg->generic_msg.seqnum,
                             l_req_fw_msg->generic_msg.msgq,
                             l_req_fw_msg->generic_msg.msgType,
                             l_req_fw_msg->generic_msg.__req,
                             l_req_fw_msg->generic_msg.__onlyError);

                    // Pack user data 1 with Hypervisor return code and
                    // firmware request message sequence number
                    l_userData1 = TWO_UINT32_TO_UINT64(
                                           rc,
                                           l_req_fw_msg->generic_msg.seqnum);

                    // Pack user data 2 with message queue and message type
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                            l_req_fw_msg->generic_msg.msgq,
                                            l_req_fw_msg->generic_msg.msgType);
                 }
            break; // END case hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ:

            case hostInterfaces::HBRT_FW_MSG_TYPE_I2C_LOCK:
                {
                    TRACFCOMP(g_trac_runtime,
                              ERR_MRK"FSP is doing a reset/reload, "
                                     "sending lock msg to FSP failed. "
                                     "retry:%d/%d, rc:%d",
                              i,
                              HBRT_FW_REQUEST_RETRIES,
                              rc);

                    l_userData1 = TWO_UINT32_TO_UINT64( rc,
                                    TWO_UINT8_TO_UINT16(
                                    l_req_fw_msg->req_i2c_lock.i_i2cMaster,
                                    l_req_fw_msg->req_i2c_lock.i_operation) );
                    l_userData2 = l_req_fw_msg->req_i2c_lock.i_chipId;
                }
            break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_I2C_LOCK:

            default:
            break;
         }  // END switch (l_req_fw_msg->io_type)

         if (l_createErrorLog)
         {
            /*@
             * @errortype
             * @severity         ERRL_SEV_INFORMATIONAL
             * @moduleid         MOD_RT_FIRMWARE_REQUEST
             * @reasoncode       RC_FW_REQUEST_RESET_RELOAD_ERR
             * @userdata1[0:31]  Hypervisor return code
             * @userdata1[32:63] Firmware Request type (HCODE Update) ||
                                 sequence number (FSP MSG) ||
                                 i2cMaster & lock operation
             * @userdata2[0:31]  SCOM address (HCODE Update) ||
                                 MBOX message type (FSP MSG) ||
                                 chipID
             * @userdata2[32:63] SCOM data (HCODE Update) ||
                                 Message Type (FSP MSG)
             * @devdesc          The Firmware Request call failed
             */
            l_err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                  MOD_RT_FIRMWARE_REQUEST,
                                  RC_FW_REQUEST_RESET_RELOAD_ERR,
                                  l_userData1,
                                  l_userData2,
                                  true);
         } // END if (l_createErrorLog)

         // Try the firmware_request call again
         continue;
      }  // END if (hbrt_rc_fspdead == rc)
      // Error is not with FSP resetting and/or reloading, so log the error
      else if (rc)
      {
         if (l_err)
         {
            // Commit any previous reset/reload error log
            errlCommit(l_err, RUNTIME_COMP_ID);
         }

         // This NOT a reset/reload error
         l_isResetReloadErr = false;

         // Print trace info based on request message type and populate
         // error log user data 1 & user data 2 based on response message
         switch (l_req_fw_msg->io_type)
         {
            case hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE:
                 {
                    // Default user data 1 wirh Hypervisor return code
                    // and firmware request message type
                    l_userData1 = TWO_UINT32_TO_UINT64(
                                               rc,
                                               l_req_fw_msg->io_type);

                    // Pack user data 1 with Hypervisor return code and
                    // generic response code if the response is of type
                    // "RESP_GENERIC" else leave as is
                    // 1st check if the response size is large enough
                    //      for the type needed
                    // 2nd make sure the message type is of
                    //     type HBRT_FW_MSG_TYPE_RESP_GENERIC
                    // 3rd make sure there is actaully a value in the status
                    // If all these conditions are correct,
                    //     then extract HWSV error
                    if ((*o_respLen >=
                                    (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                    sizeof(l_resp_fw_msg->resp_generic)))  &&
                         hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC ==
                                    l_resp_fw_msg->io_type &&
                         0 != l_resp_fw_msg->resp_generic.o_status )
                    {
                       l_userData1 = TWO_UINT32_TO_UINT64(
                                        rc,
                                        l_resp_fw_msg->resp_generic.o_status);
                    } // END if (*o_respLen >= ...

                    // Pack user data 2 with HCODE scom
                    // and HCODE scom data
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                  l_req_fw_msg->req_hcode_update.i_scomAddr,
                                  l_req_fw_msg->req_hcode_update.i_scomData);

                    TRACFCOMP(g_trac_runtime,
                           ERR_MRK"Failed doing an HCODE update. "
                           "rc:%d, io_type:%d, chipId:0x%llX, section:0x%X, "
                           "operation:0x%X, scomAddr:0x%llX, scomData:0x%llX",
                           rc,
                           l_req_fw_msg->io_type,
                           l_req_fw_msg->req_hcode_update.i_chipId,
                           l_req_fw_msg->req_hcode_update.i_section,
                           l_req_fw_msg->req_hcode_update.i_operation,
                           l_req_fw_msg->req_hcode_update.i_scomAddr,
                           l_req_fw_msg->req_hcode_update.i_scomData);

                 }
            break;//END case hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE:

            case hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG:
                 {
                    TRACFCOMP(g_trac_runtime,
                              ERR_MRK"Failed sending error log to FSP "
                              "via firmware_request. rc:%d, plid:0x%08X",
                              rc,
                              l_req_fw_msg->error_log.i_plid);

                    // Don't create an error log for this request type
                    l_createErrorLog = false;
                 }
            break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG:


            case hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ:
                 {
                    TRACFCOMP(g_trac_runtime,
                             ERR_MRK"Failed doing a VPD write. "
                             "rc:%d, io_type:%d, dataSize:%d, "
                             "seqnum:0x%X, msgq:0x%X, msgType:0x%X, __req:%d, "
                             "__onlyError:%d",
                             rc,
                             l_req_fw_msg->io_type,
                             l_req_fw_msg->generic_msg.dataSize,
                             l_req_fw_msg->generic_msg.seqnum,
                             l_req_fw_msg->generic_msg.msgq,
                             l_req_fw_msg->generic_msg.msgType,
                             l_req_fw_msg->generic_msg.__req,
                             l_req_fw_msg->generic_msg.__onlyError);

                    // Pack user data 1 with Hypervisor return code and
                    // firmware request message sequence number
                    l_userData1 = TWO_UINT32_TO_UINT64(
                                            rc,
                                            l_req_fw_msg->generic_msg.seqnum);

                    // Pack user data 2 with message queue and message type
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                            l_req_fw_msg->generic_msg.msgq,
                                            l_req_fw_msg->generic_msg.msgType);
                 }
            break; // END case hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ:

            case hostInterfaces::HBRT_FW_MSG_TYPE_I2C_LOCK:
                {
                    TRACFCOMP(g_trac_runtime, ERR_MRK"Failed sending FSP i2c "
                             "lock message rc 0x%X; i_chipId: 0x%llX, "
                             "i_i2cMaster: %d, i_operation: %d",
                             rc,
                             l_req_fw_msg->req_i2c_lock.i_chipId,
                             l_req_fw_msg->req_i2c_lock.i_i2cMaster,
                             l_req_fw_msg->req_i2c_lock.i_operation );

                    l_userData1 = TWO_UINT32_TO_UINT64( rc,
                            TWO_UINT8_TO_UINT16(
                                l_req_fw_msg->req_i2c_lock.i_i2cMaster,
                                l_req_fw_msg->req_i2c_lock.i_operation) );
                    l_userData2 = l_req_fw_msg->req_i2c_lock.i_chipId;
                }
            break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_I2C_LOCK:
            default:
               break;
         }  // END switch (l_req_fw_msg->io_type)

         if (l_createErrorLog)
         {
            /*@
             * @errortype
             * @severity         ERRL_SEV_PREDICTIVE
             * @moduleid         MOD_RT_FIRMWARE_REQUEST
             * @reasoncode       RC_FW_REQUEST_ERR
             * @userdata1[0:31]  Hypervisor return code
             * @userdata1[32:63] Firmware Request type (HCODE Update) ||
                                 sequence number (FSP MSG) ||
                                 i2cMaster & lock operation
             * @userdata2[0:31]  SCOM address (HCODE Update) ||
                                 MBOX message type (FSP MSG) ||
                                 chipId
             * @userdata2[32:63] SCOM data (HCODE Update) ||
                                 Message Type (FSP MSG)
             * @devdesc          The Firmware Request call failed
             */
            l_err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                  MOD_RT_FIRMWARE_REQUEST,
                                  RC_FW_REQUEST_ERR,
                                  l_userData1,
                                  l_userData2,
                                  true);
          } // END if (l_createErrorLog)

         // Break out of the retry loop
         break;
      } // END else if (rc) generic_msg
      // There was no RC returned from the FSP request, there could be an issue
      // with HWSV.  If so then a PLID will be returned in the first
      // 4 bytes of the 'data' member for an HBRT_FW_MSG_HBRT_FSP_RESP type.
      // 1st check if the response size is large enough for the type needed
      // 2nd make sure the message is of HBRT_FW_MSG_HBRT_FSP_RESP type.
      // 3rd check if the 'data' member will contain an error ID (PLID)
      // 4th make sure the PLID has a value
      // If all these conditions are correct, then pull out PLID
      else if ((*o_respLen >=
               (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                      sizeof(hostInterfaces::hbrt_fw_msg::generic_msg))) &&
               (hostInterfaces::HBRT_FW_MSG_HBRT_FSP_RESP ==
                      l_resp_fw_msg->io_type) &&
               (GenericFspMboxMessage_t::ERROR_ONLY ==
                      l_resp_fw_msg->generic_msg.__onlyError) &&
               (0 != (l_resp_fw_msg->generic_msg.data >> 32)))

      {
         if (l_err)
         {
            // Commit any previous reset/reload error log
            errlCommit(l_err, RUNTIME_COMP_ID);
         }

         // This NOT a reset/reload error
         l_isResetReloadErr = false;

         uint32_t l_errPlid = l_resp_fw_msg->generic_msg.data >> 32;

         TRACFCOMP(g_trac_runtime,
                   ERR_MRK"Failed doing a VPD write. "
                          "rc:%d, plid:0x%X, io_type:%d, dataSize:%d, "
                          "seqnum:0x%X, msgq:0x%X, msgType:0x%X, __req:%d, "
                          "__onlyError:%d",
                          rc,
                          l_errPlid,
                          l_req_fw_msg->io_type,
                          l_req_fw_msg->generic_msg.dataSize,
                          l_req_fw_msg->generic_msg.seqnum,
                          l_req_fw_msg->generic_msg.msgq,
                          l_req_fw_msg->generic_msg.msgType,
                          l_req_fw_msg->generic_msg.__req,
                          l_req_fw_msg->generic_msg.__onlyError);

         /*@
          * @errortype
          * @severity         ERRL_SEV_PREDICTIVE
          * @moduleid         MOD_RT_FIRMWARE_REQUEST
          * @reasoncode       RC_FW_REQUEST_HWSV_ERR
          * @userdata1[0:31]  HWSV error log id (PLID)
          * @userdata1[32:63] Sequence number
          * @userdata2[0:31]  MBOX message type
          * @userdata2[32:63] Message Type
          * @devdesc          The Firmware Request call failed
          */
         l_err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                               MOD_RT_FIRMWARE_REQUEST,
                               RC_FW_REQUEST_HWSV_ERR,
                               TWO_UINT32_TO_UINT64(
                                            l_errPlid,
                                            l_req_fw_msg->generic_msg.seqnum),
                               TWO_UINT32_TO_UINT64(
                                            l_req_fw_msg->generic_msg.msgq,
                                            l_req_fw_msg->generic_msg.msgType),
                               true);

         // Break out of the retry loop
         break;
      }
      else
      {
         // Break out of the retry loop, the call was successful
         // But first delete any previous errors.  It can be confusing
         // if an error is committed or returned on a successful call
         delete l_err, l_err = nullptr;
         break;
      }
   } // END for (int i = 0; i <= HBRT_FW_REQUEST_RETRIES; ++i)

   // If there is an error, then call addFFDC
   // with request/response sructs
   if (l_err)
   {
      // Hit the max attempts (currently should only one retry) and hitting
      // reset/reload error
      if (l_isResetReloadErr)
      {
         // Change the severity of a reset/reload error to predictive
         l_err->setSev(ERRL_SEV_PREDICTIVE);
      }

      l_err->addFFDC(RUNTIME_COMP_ID,
                     l_req_fw_msg,
                     i_reqLen,
                     0, 0, false );

      if (*o_respLen > 0)
      {
         l_err->addFFDC(RUNTIME_COMP_ID,
                        l_resp_fw_msg,
                        *o_respLen,
                        0, 0, false );
      }

      l_err->collectTrace( "FW_REQ", 256);
   }  // END if (l_err)

  return l_err;
};
