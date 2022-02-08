/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_fwreq_helper.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include <targeting/common/targetUtil.H>  // makeAttribute

using namespace ERRORLOG;
using namespace RUNTIME;
using namespace TRACE;

// Trace definition
trace_desc_t *g_trac_runtime = nullptr;
TRAC_INIT(&g_trac_runtime, RUNTIME_COMP_NAME, KILOBYTE);


/**
 * @brief Add some FFDC to the error log
 *
 * @param i_request  Pointer to request buffer
 * @param i_reqLen  Size of request buffer in bytes
 * @param i_response  Pointer to response buffer
 * @param i_respLen  Size of response buffer in bytes
 */
void add_ffdc( errlHndl_t i_err,
               void* i_request,
               size_t i_reqLen,
               void* i_response,
               size_t i_respLen )
{
    i_err->addFFDC(RUNTIME_COMP_ID,
                   i_request,
                   i_reqLen,
                   0, 0, false );

    if (i_respLen > 0)
    {
        i_err->addFFDC(RUNTIME_COMP_ID,
                       i_response,
                       i_respLen,
                       0, 0, false );
    }

    i_err->collectTrace( RUNTIME_COMP_NAME, 256);
}

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
             add_ffdc( l_err,
                       l_req_fw_msg, i_reqLen,
                       l_resp_fw_msg, *o_respLen );

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
                             "sending a message to the FSP failed. "
                             "retry:%d/%d, rc:%d, io_type:%d, dataSize:%d, ",
                             i,
                             HBRT_FW_REQUEST_RETRIES,
                             rc,
                             l_req_fw_msg->io_type,
                             l_req_fw_msg->generic_msg.dataSize);
                    TRACFCOMP(g_trac_runtime,
                             "seqnum:0x%X, msgq:0x%X, msgType:0x%X, __req:%d, "
                             "__onlyError:%d",
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

            case hostInterfaces::HBRT_FW_MSG_TYPE_SBE_STATE:
                {
                    TRACFCOMP(g_trac_runtime,
                              ERR_MRK"FSP is doing a reset/reload, "
                                     "sending SBE vital attn to OPAL failed. "
                                     "retry:%d/%d, rc:%d, procId:0x%08x, "
                                     "state(0=disabled, 1=enable):%d",
                              i,
                              HBRT_FW_REQUEST_RETRIES,
                              rc,
                              l_req_fw_msg->sbe_state.i_procId,
                              l_req_fw_msg->sbe_state.i_state);

                    // Pack user data 1 with Hypervisor return code and
                    // firmware request message type
                    l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                                       l_req_fw_msg->io_type);

                    // Pack user data 2 with processor ID of SBE
                    // and state of the SBE
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                      l_req_fw_msg->sbe_state.i_procId,
                                      l_req_fw_msg->sbe_state.i_state);
                }
            break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_SBE_STATE:

            case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_PROTECTION:
                {
                    TRACFCOMP(g_trac_runtime,
                              ERR_MRK"FSP is doing a reset/reload, "
                                     "Send NVDIMM state to PHYP failed. "
                                     "retry:%d/%d, rc:%d, procId:0x%.8X, "
                                     "state:%d - %s",
                              i,
                              HBRT_FW_REQUEST_RETRIES,
                              rc,
                              l_req_fw_msg->sbe_state.i_procId,
                              l_req_fw_msg->sbe_state.i_state,
                              l_req_fw_msg->sbe_state.i_state?
                              "protected":"not protected");

                    // Pack user data 1 with Hypervisor return code and
                    // firmware request message type
                    l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                                       l_req_fw_msg->io_type);

                    // Pack user data 2 with processor ID of NVDIMM
                    // and state of the NVDIMM
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                l_req_fw_msg->nvdimm_protection_state.i_procId,
                                l_req_fw_msg->nvdimm_protection_state.i_state);
                }
                break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_PROTECTION:

         case hostInterfaces::HBRT_FW_MSG_TYPE_INITIATE_GARD:
             {
                 TRACFCOMP(g_trac_runtime,
                           ERR_MRK"FSP is doing a reset/reload, INITIATE_GARD request "
                           "failed for errorType=%d, resourceType=%d, resourceId=%d",
                           l_req_fw_msg->initiate_gard.errorType,
                           l_req_fw_msg->initiate_gard.resourceType,
                           l_req_fw_msg->initiate_gard.resourceId);

                 // Pack user data 1 with Hypervisor return code and
                 // firmware request message type
                 l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                                    l_req_fw_msg->io_type);



                 // Pack user data 2 with error type, resource type, and resource ID of target
                 l_userData2 = TWO_UINT16_ONE_UINT32_TO_UINT64(l_req_fw_msg->initiate_gard.errorType,
                                                               l_req_fw_msg->initiate_gard.resourceType,
                                                               l_req_fw_msg->initiate_gard.resourceId);
             }
             break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_INITIATE_GARD:

                // There is no need for reset-reload handling for these message
                // types.  They are either hyp-only, or they are responses.
            case hostInterfaces::HBRT_FW_MSG_TYPE_REQ_NOP:
            case hostInterfaces::HBRT_FW_MSG_TYPE_RESP_NOP:
            case hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC:
            case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_OPERATION:
            case hostInterfaces::HBRT_FW_MSG_TYPE_GARD_EVENT:
            case hostInterfaces::HBRT_FW_MSG_TYPE_GET_ELOG_TIME:
            case hostInterfaces::HBRT_FW_MSG_TYPE_SPILOCK:
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
             * @userdata1[32:63] Firmware Request type (HCODE Update, Initiate gard) ||
                                 sequence number (FSP MSG) ||
                                 i2cMaster & lock operation
             * @userdata2[0:31]  SCOM address (HCODE Update) ||
                                 MBOX message type (FSP MSG) ||
                                 chipID ||
                                 error type + resource type (Initiate gard)
             * @userdata2[32:63] SCOM data (HCODE Update) ||
                                 Message Type (FSP MSG) ||
                                 SBE state ||
                                 NVDIMM protection ||
                                 resource ID (Initiate gard)
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
          TRACFCOMP(g_trac_runtime,
                    ERR_MRK"Error from firmware_request with io_type=%d. rc=%d",
                    l_req_fw_msg->io_type,
                    rc);
          // Default user data 1 wirh Hypervisor return code
          // and firmware request message type
          l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                             l_req_fw_msg->io_type);

         if (l_err)
         {
             add_ffdc( l_err,
                       l_req_fw_msg, i_reqLen,
                       l_resp_fw_msg, *o_respLen );

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
                             ERR_MRK"Failed sending a message to the FSP. "
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

            case hostInterfaces::HBRT_FW_MSG_TYPE_SBE_STATE:
                 {
                    TRACFCOMP(g_trac_runtime,
                              ERR_MRK"Failed sending SBE vital attn to OPAL. "
                                     "rc:0x%X, procId:0x%08x, "
                                     "state(0=disabled, 1=enable):%d",
                              rc,
                              l_req_fw_msg->sbe_state.i_procId,
                              l_req_fw_msg->sbe_state.i_state);

                    // Pack user data 1 with Hypervisor return code and
                    // firmware request message type
                    l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                                       l_req_fw_msg->io_type);

                    // Pack user data 2 with processor ID of SBE
                    // and state of the SBE
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                      l_req_fw_msg->sbe_state.i_procId,
                                      l_req_fw_msg->sbe_state.i_state);
                 }
            break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_SBE_STATE:

            case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_PROTECTION:
                {
                    TRACFCOMP(g_trac_runtime,
                        ERR_MRK"Failed sending NVDIMM protection state to PHYP."
                        " rc:0x%X, procId:0x%.8X, state:%d - %s",
                        rc,
                        l_req_fw_msg->sbe_state.i_procId,
                        l_req_fw_msg->sbe_state.i_state,
                        l_req_fw_msg->sbe_state.i_state?
                        "protected":"not protected");

                    // Pack user data 1 with Hypervisor return code and
                    // firmware request message type
                    l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                                       l_req_fw_msg->io_type);

                    // Pack user data 2 with processor ID of NVDIMM
                    // and state of the NVDIMM
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                l_req_fw_msg->nvdimm_protection_state.i_procId,
                                l_req_fw_msg->nvdimm_protection_state.i_state);
                }
                break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_PROTECTION:

             case hostInterfaces::HBRT_FW_MSG_TYPE_INITIATE_GARD:
                 {
                     TRACFCOMP(g_trac_runtime,
                               ERR_MRK"INITIATE_GARD request failed for errorType=%d, "
                               "resourceType=%d, resourceId=%d",
                               l_req_fw_msg->initiate_gard.errorType,
                               l_req_fw_msg->initiate_gard.resourceType,
                               l_req_fw_msg->initiate_gard.resourceId);

                     // Pack user data 1 with Hypervisor return code and
                     // firmware request message type
                     l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                                        l_req_fw_msg->io_type);

                     // Pack user data 2 with error type, resource type, and resource ID of target
                     l_userData2 = TWO_UINT16_ONE_UINT32_TO_UINT64(l_req_fw_msg->initiate_gard.errorType,
                                                                   l_req_fw_msg->initiate_gard.resourceType,
                                                                   l_req_fw_msg->initiate_gard.resourceId);
                 }
                 break; // END case hostInterfaces::HBRT_FW_MSG_TYPE_INITIATE_GARD:

         case hostInterfaces::HBRT_FW_MSG_TYPE_SPILOCK:
                {
                    TRACFCOMP(g_trac_runtime,
                        ERR_MRK"Failed sending SPI Lock message to PHYP."
                        " rc:0x%X, procChipId:0x%.8X, blockHyp:%d",
                        rc,
                        l_req_fw_msg->spi_lock.procChipId,
                        l_req_fw_msg->spi_lock.blockHyp);

                    // Pack user data 1 with Hypervisor return code and
                    // firmware request message type
                    l_userData1 = TWO_UINT32_TO_UINT64(rc,
                                                       l_req_fw_msg->io_type);

                    // Pack user data 2 with parameters
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                l_req_fw_msg->spi_lock.procChipId,
                                l_req_fw_msg->spi_lock.blockHyp);
                }
                break; // END case HBRT_FW_MSG_TYPE_SPILOCK

            case hostInterfaces::HBRT_FW_MSG_TYPE_GET_ELOG_TIME: //TBD

                // There is no need for reset-reload handling for these response
                // types..
            case hostInterfaces::HBRT_FW_MSG_TYPE_REQ_NOP:
            case hostInterfaces::HBRT_FW_MSG_TYPE_RESP_NOP:
            case hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC:
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
                                 Message Type (FSP MSG)  ||
                                 SBE state ||
                                 NVDIMM protection state
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
             add_ffdc( l_err,
                       l_req_fw_msg, i_reqLen,
                       l_resp_fw_msg, *o_respLen );

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

      add_ffdc( l_err,
                l_req_fw_msg, i_reqLen,
                l_resp_fw_msg, *o_respLen );
   }  // END if (l_err)

  return l_err;
};

/**
 *  @brief  A handy utility to create the firmware request and response
 *          messages, for FSP, where the messages must be of equal size.
 */
bool createGenericFspMsg(uint32_t i_fspReqPayloadSize,
                         uint32_t &o_fspMsgSize,
                         uint64_t &o_requestMsgSize,
                         hostInterfaces::hbrt_fw_msg* &o_requestMsg,
                         uint64_t &o_responseMsgSize,
                         hostInterfaces::hbrt_fw_msg* &o_responseMsg)
{
   // Default the return value to true, assume things will go right
   bool l_retVal(true);

   // Do some quick initialization of the output data
   o_fspMsgSize = o_requestMsgSize = o_responseMsgSize = 0;
   o_requestMsg = o_responseMsg = nullptr;

   // Calculate the total size of the Generic FSP Message.
   o_fspMsgSize = GENERIC_FSP_MBOX_MESSAGE_BASE_SIZE +
                      i_fspReqPayloadSize;

   // The total Generic FSP Message size must be at a minimum the
   // size of the FSP generic message (sizeof(GenericFspMboxMessage_t))
   if (o_fspMsgSize < sizeof(GenericFspMboxMessage_t))
   {
      o_fspMsgSize = sizeof(GenericFspMboxMessage_t);
   }

   // Calculate the total size of the hbrt_fw_msgs which
   // means only adding hostInterfaces::HBRT_FW_MSG_BASE_SIZE to
   // the previous calculated Generic FSP Message size.
   o_requestMsgSize = o_responseMsgSize =
                   hostInterfaces::HBRT_FW_MSG_BASE_SIZE + o_fspMsgSize;

   // Create the hbrt_fw_msgs
   o_responseMsg = reinterpret_cast<hostInterfaces::hbrt_fw_msg *>
                     (new uint8_t[o_responseMsgSize]);
   o_requestMsg = reinterpret_cast<hostInterfaces::hbrt_fw_msg *>
                     (new uint8_t[o_requestMsgSize]);

   // If any one of these two message's memory can't be allocated, then
   // delete both messages (in case one did allocate memory), set both
   // messages to NULL pointers and set their respective sizes to zero.
   if (!o_responseMsg || !o_requestMsg)
   {
      // OK to delete a NULL pointer if it happens
      delete []o_responseMsg;
      delete []o_requestMsg;

      // Return output data zeroed out
      o_responseMsg = o_requestMsg = nullptr;
      o_fspMsgSize = o_requestMsgSize = o_responseMsgSize = 0;

      // Return false, indicating that this function had an issue creating
      // the request and/or response message
      l_retVal = false;
   }
   else
   {
      // Initialize/zero out hbrt_fw_msgs
      o_requestMsg->generic_msg.initialize();
      memset(o_responseMsg, 0, o_responseMsgSize);

      // We can at least set these parameters based on current usage
      o_requestMsg->io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
      o_requestMsg->generic_msg.dataSize = o_fspMsgSize;
      o_requestMsg->generic_msg.__req = GenericFspMboxMessage_t::REQUEST;
   }

   return l_retVal;
}  // end createGenericFspMsg


/**
 *  @brief  Serializes a list of Attributes to be sent to FSP
 */
errlHndl_t sendAttributes(const std::vector<TARGETING::AttributeTank::Attribute>&
                          i_attributeList)
{
    TRACFCOMP(g_trac_runtime,
              ENTER_MRK"sendAttributes - number of attributes to send %d",
              i_attributeList.size());

    // Handle to error log
    errlHndl_t l_err{nullptr};

    // Handles to the firmware messages
    hostInterfaces::hbrt_fw_msg *l_fwRequestMsg{nullptr};   // request message
    hostInterfaces::hbrt_fw_msg *l_fwResponseMsg{nullptr};  // response message

    do
    {
        // If caller passes in an empty list, then nothing to do
        if (!i_attributeList.size())
        {
            TRACFCOMP(g_trac_runtime, "sendAttributes: attribute list is "
                      "empty,nothing to do ...");
            break;
        }

        // Make sure we have all of our function pointers setup right
        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            TRACFCOMP(g_trac_runtime, ERR_MRK"sendAttributes: "
                      "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity     ERRL_SEV_UNRECOVERABLE
             * @moduleid     MOD_RT_FIRMWARE_REQUEST
             * @reasoncode   RC_FW_REQUEST_RT_NULL_PTR
             * @userdata1    Number of Attributes to serialize and send
             * @devdesc      Hypervisor firmware request interface not linked
             * @custdesc     Internal firmware error
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           RUNTIME::MOD_RT_FIRMWARE_REQUEST,
                                           RUNTIME::RC_FW_REQUEST_RT_NULL_PTR,
                                           i_attributeList.size(),
                                           0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        /// Calculate the size requirements needed to serialize
        /// the Attribute info
        // Aggregate the size of the incoming Attributes
        uint32_t l_aggregatedAttributeSize(0);
        for (auto l_attribute: i_attributeList)
        {
            l_aggregatedAttributeSize += l_attribute.getSize();
        }

        // Combine the size of the AttributeSetter_t itself to the size of
        // incoming Attributes to get the full size requirement needed
        uint32_t l_dataSize(sizeof(AttributeSetter_t) +
                            l_aggregatedAttributeSize);

        // Create and initialize to zero a few needed variables
        uint32_t l_fullFspDataSize(0);
        uint64_t l_fwRequestMsgSize(0), l_fwResponseMsgSize(0);

        // Create the dynamic firmware messages
        if (!createGenericFspMsg(l_dataSize,
                                 l_fullFspDataSize,
                                 l_fwRequestMsgSize,
                                 l_fwRequestMsg,
                                 l_fwResponseMsgSize,
                                 l_fwResponseMsg) )
        {
            TRACFCOMP(g_trac_runtime, ERR_MRK"sendAttributes: "
                      "Unable to allocate firmware request messages");

            /*@
             * @errortype
             * @severity     ERRL_SEV_UNRECOVERABLE
             * @moduleid     MOD_SEND_ATTRIBUTES_TO_FSP
             * @reasoncode   RC_NULL_FIRMWARE_MSG_PTR
             * @userdata1    Number of Attributes to serialize and send
             * @devdesc      Unable to allocate firmware request messages
             * @custdesc     Internal firmware error
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          RUNTIME::MOD_SEND_ATTRIBUTES_TO_FSP,
                                          RUNTIME::RC_NULL_FIRMWARE_MSG_PTR,
                                          i_attributeList.size(),
                                          0,
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        // Populate the 'message queue' and 'message type' for this message
        l_fwRequestMsg->generic_msg.msgq = MBOX::FSP_NVDIMM_KEYS_MSGQ_ID;
        l_fwRequestMsg->generic_msg.msgType =
                                  GenericFspMboxMessage_t::MSG_ATTR_WRITE_OP;

        // Create a useful struct to populate the generic_msg::data field
        AttributeSetter_t* l_attributeSetter =
                                reinterpret_cast<AttributeSetter_t*>
                                        (&(l_fwRequestMsg->generic_msg.data));

        // Initialize the AttributeSetter to default values
        l_attributeSetter->initialize();

        // The number of attributes being copied can be obtained from
        // size of the attrbute input list
        l_attributeSetter->iv_numAttributes = i_attributeList.size();

        // Retrieve the individual attributes (header and value)
        // Create a useful struct to poulate attribute data
        uint8_t* l_attributeData = l_attributeSetter->iv_attrData;
        uint32_t l_sizeOfDataCopied(0);

        // Iterate thru the attribute list and serialize the attributes
        for (const auto & l_attribute: i_attributeList)
        {
            if (l_aggregatedAttributeSize >= l_attribute.getSize())
            {
                l_sizeOfDataCopied = l_attribute.serialize(
                                   l_attributeData, l_aggregatedAttributeSize);

                if (!l_sizeOfDataCopied)
                {
                    TRACFCOMP(g_trac_runtime, ERR_MRK"sendAttributes: "
                      "Serialization of an Attribute failed, "
                      "should never happen")

                    /*@
                     * @errortype
                     * @severity     ERRL_SEV_UNRECOVERABLE
                     * @moduleid     MOD_SEND_ATTRIBUTES_TO_FSP
                     * @reasoncode   RC_SERIALIZE_ATTRIBUTE_FAILED
                     * @userdata1    Number of Attributes to serialize and send
                     * @devdesc      Serialization of an Attribute Failed
                     * @custdesc     Internal firmware error
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        RUNTIME::MOD_SEND_ATTRIBUTES_TO_FSP,
                                        RUNTIME::RC_SERIALIZE_ATTRIBUTE_FAILED,
                                        i_attributeList.size(),
                                        0,
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                    break;
                } // end if (!l_sizeOfDataCopied)
            }
            else
            {
                TRACFCOMP(g_trac_runtime, ERR_MRK"sendAttributes: "
                       "Miscalculation of aggregated size of attributes, "
                       "should never happen")

                /*@
                 * @errortype
                 * @severity     ERRL_SEV_UNRECOVERABLE
                 * @moduleid     MOD_SEND_ATTRIBUTES_TO_FSP
                 * @reasoncode   RC_NO_SPACE_FOR_ATTRIBUTE_SERIALIZATION
                 * @userdata1    Number of Attributes to serialize and send
                 * @devdesc      Serialization data of Attribute to large
                 *               for given buffer
                 * @custdesc     Internal firmware error
                 */
                l_err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              RUNTIME::MOD_SEND_ATTRIBUTES_TO_FSP,
                              RUNTIME::RC_NO_SPACE_FOR_ATTRIBUTE_SERIALIZATION,
                              i_attributeList.size(),
                              0,
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                break;
            }

            // Decrement/increment our counters/pointers
            l_aggregatedAttributeSize -= l_sizeOfDataCopied;
            l_attributeData += l_sizeOfDataCopied;
        }  // end for (const auto & l_attribute: i_attributeList)

        // Make the firmware_request call
        l_err = firmware_request_helper(l_fwRequestMsgSize,
                                        l_fwRequestMsg,
                                        &l_fwResponseMsgSize,
                                        l_fwResponseMsg);
    } while (0);

    // Release the firmware messages and set to NULL
    delete []l_fwRequestMsg;
    delete []l_fwResponseMsg;
    l_fwRequestMsg = l_fwResponseMsg = nullptr;

    TRACFCOMP(g_trac_runtime, EXIT_MRK"sendAttributes - exit with %s",
              (nullptr == l_err ? "no error" : "error"));


    return l_err;
}
