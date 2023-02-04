/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsiscom/runtime/rt_fsiscom.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <fsiscom/fsiscom_reasoncodes.H>
#include "../fsiscom.H"
#include <scom/scomif.H>
#include <scom/runtime/rt_scomif.H>
#include <targeting/common/utilFilter.H>

#include <runtime/hbrt_utilities.H>        // createGenericFspMsg
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper

#include <map>

// Trace definition
trace_desc_t* g_trac_fsiscom = NULL;
TRAC_INIT(&g_trac_fsiscom, FSISCOM_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace FSISCOM
{

/**
 * @brief This function sends the scom op to the FSP
 *
 * @param[in]     i_opType    Scom operation type, see driverif.H
 * @param[in]     i_target    Scom target
 * @param[in]     i_scomAddr  Scom address
 * @param[in/out] io_buffer   Read: Pointer to output data storage
 *                            Write: Pointer to input data storage
 * @return  errlHndl_t
 */
errlHndl_t sendScomOpToFsp(DeviceFW::OperationType i_opType,
                           TARGETING::TargetHandle_t i_target,
                           uint64_t i_scomAddr,
                           void * io_buffer)
{
   errlHndl_t l_err = nullptr;

   // Handles to the firmware messages
   hostInterfaces::hbrt_fw_msg *l_req_fw_msg  = nullptr;
   hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

   do
   {
      if ((nullptr == g_hostInterfaces) ||
          (nullptr == g_hostInterfaces->firmware_request))
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "Hypervisor firmware_request interface not linked");

         /*@
          * @errortype
          * @severity         ERRL_SEV_UNRECOVERABLE
          * @moduleid         MOD_FSISCOM_RT_SEND_SCOM_TO_FSP
          * @reasoncode       RC_RT_INTERFACE_ERR
          * @userdata1        target's HUID
          * @userdata2        SCOM address
          * @devdesc          Hypervisor firmware request interface not linked
          * @custdesc         An internal firmware error occurred
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FSISCOM_RT_SEND_SCOM_TO_FSP,
                                         RC_RT_INTERFACE_ERR,
                                         get_huid(i_target),
                                         i_scomAddr,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Create and initialize to zero a few needed variables
      uint32_t l_fsp_data_size(0);
      uint64_t l_req_fw_msg_size(0), l_resp_fw_msg_size(0);

      // Create the dynamic firmware messages
      createGenericFspMsg(sizeof(SingleScomOpHbrtFspData_t),
                          l_fsp_data_size,
                          l_req_fw_msg_size,
                          l_req_fw_msg,
                          l_resp_fw_msg_size,
                          l_resp_fw_msg);

      // If there was an issue with creating the messages,
      // create an Error Log entry and exit
      if (!l_req_fw_msg || !l_resp_fw_msg)
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "Unable to allocate firmware request messages");

         /*@
          * @errortype
          * @severity         ERRL_SEV_UNRECOVERABLE
          * @moduleid         MOD_FSISCOM_RT_SEND_SCOM_TO_FSP
          * @reasoncode       RC_RT_NULL_FW_MSG_PTR
          * @userdata1        target's HUID
          * @userdata2        SCOM address
          * @devdesc          Unable to allocate firmware request messages
          * @custdesc         An internal firmware error occurred
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FSISCOM_RT_SEND_SCOM_TO_FSP,
                                         RC_RT_NULL_FW_MSG_PTR,
                                         get_huid(i_target),
                                         i_scomAddr,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Populate the request message with given data
      l_req_fw_msg->generic_msg.msgq = MBOX::FSP_SCOM_OPS_MSGQ;
      l_req_fw_msg->generic_msg.msgType =
                                GenericFspMboxMessage_t::MSG_SINGLE_SCOM_OP;

      // Create a useful struct to populate the generic_msg::data field
      // Set the command-specific portion of the FSP message
      SingleScomOpHbrtFspData_t* l_fspData =
                  reinterpret_cast<SingleScomOpHbrtFspData_t*>
                                 (&(l_req_fw_msg->generic_msg.data));
      l_fspData->scom_op   = i_opType;
      l_fspData->huid      = get_huid(i_target);
      l_fspData->scom_addr = i_scomAddr;
      l_fspData->scom_data = *((uint64_t *)io_buffer);

      // Make the firmware_request call
      // Ask the FSP to perform this SCOM operation
      TRACFCOMP(g_trac_fsiscom, "Sending SINGLE_SCOM_OP firmware_request, "
                                "op=%c, huid=0x%X, addr=%llX",
                                (i_opType == DeviceFW::READ) ? 'r' : 'w',
                                l_fspData->huid, l_fspData->scom_addr);
      l_err = firmware_request_helper(l_req_fw_msg_size,
                                      l_req_fw_msg,
                                      &l_resp_fw_msg_size,
                                      l_resp_fw_msg);

      if (l_err)
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "FSP scom read/write failed. "
                   "target 0x%llX addr 0x%llX r/w %d",
                   get_huid(i_target), i_scomAddr, i_opType);
         break;
      }

      // Create a useful struct to populate the generic_msg::data field
      // Get the command-specific portion of the returned FSP message
      l_fspData =
                  reinterpret_cast<SingleScomOpHbrtFspData_t*>
                                 (&(l_resp_fw_msg->generic_msg.data));
      *((uint64_t *)io_buffer) = l_fspData->scom_data;
   } while(0);

   // Release the firmware messages and set to NULL
   delete [] l_req_fw_msg;
   delete [] l_resp_fw_msg;
   l_req_fw_msg = l_resp_fw_msg = nullptr;

   if (l_err)
   {
       l_err->collectTrace(FSISCOM_COMP_NAME,512);
   }

  return l_err;
}


/**
 * @brief Ask FSP to read list of SCOMs
 *
 * @param[in]     i_target    Scom target
 * @param[in]     i_scomAddr  Scom addresses to read
 * @param[in/out] o_scomValue Scom values read (0xDEADBEEF for errors)
 * @return  errlHndl_t
 */
errlHndl_t sendMultiScomReadToFsp(TARGETING::TargetHandle_t i_target,
                                  std::vector<uint64_t> &i_scomAddr,
                                  std::vector<uint64_t> &o_scomValue)
{
   errlHndl_t l_err = nullptr;

   // Handles to the firmware messages
   hostInterfaces::hbrt_fw_msg *l_req_fw_msg  = nullptr;
   hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

   do
   {
      if ((nullptr == g_hostInterfaces) ||
          (nullptr == g_hostInterfaces->firmware_request))
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "Hypervisor firmware_request interface not linked");

         /*@
          * @errortype
          * @severity         ERRL_SEV_UNRECOVERABLE
          * @moduleid         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP
          * @reasoncode       RC_RT_INTERFACE_ERR
          * @userdata1        target's HUID
          * @userdata2        # of SCOMs to read
          * @devdesc          Hypervisor firmware request interface not linked
          * @custdesc         An internal firmware error occurred
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP,
                                         RC_RT_INTERFACE_ERR,
                                         get_huid(i_target),
                                         i_scomAddr.size(),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Create and initialize to zero a few needed variables
      uint32_t l_fsp_data_size(0);
      uint64_t l_req_fw_msg_size(0), l_resp_fw_msg_size(0);

      // Need to add the array of addresses/values
      size_t   l_numScoms = i_scomAddr.size();
      uint64_t l_msg_size = sizeof(MultiScomReadHbrtFspData_t);

      // Default MultiScomRead message size is for only one SCOM, need to
      // add any additional SCOMs to the message size in order to have the
      // additional space at the end of the struct.
      if (l_numScoms > 1)
      {
          l_msg_size += (l_numScoms - 1) * sizeof(uint64_t);
      }

      // Create the dynamic firmware messages
      createGenericFspMsg(l_msg_size,
                          l_fsp_data_size,
                          l_req_fw_msg_size,
                          l_req_fw_msg,
                          l_resp_fw_msg_size,
                          l_resp_fw_msg);

      // If there was an issue with creating the messages,
      // create an Error Log entry and exit
      if (!l_req_fw_msg || !l_resp_fw_msg)
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "Unable to allocate firmware request messages");

         /*@
          * @errortype
          * @severity         ERRL_SEV_UNRECOVERABLE
          * @moduleid         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP
          * @reasoncode       RC_RT_NULL_FW_MSG_PTR
          * @userdata1        target's HUID
          * @userdata2        # of SCOMs to read
          * @devdesc          Unable to allocate firmware request messages
          * @custdesc         An internal firmware error occurred
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP,
                                         RC_RT_NULL_FW_MSG_PTR,
                                         get_huid(i_target),
                                         i_scomAddr.size(),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Populate the request message with given data
      l_req_fw_msg->generic_msg.msgq = MBOX::FSP_SCOM_OPS_MSGQ;
      l_req_fw_msg->generic_msg.msgType =
                                GenericFspMboxMessage_t::MSG_MULTI_SCOM_OP;

      // Create a useful struct to populate the generic_msg::data field
      // Set the command-specific portion of the FSP message
      MultiScomReadHbrtFspData_t* l_fspData =
                  reinterpret_cast<MultiScomReadHbrtFspData_t*>
                                 (&(l_req_fw_msg->generic_msg.data));
      l_fspData->huid      = get_huid(i_target);
      l_fspData->scom_num  = l_numScoms;
      // copy SCOM addresses into scom_data
      std::copy(i_scomAddr.begin(), i_scomAddr.end(), &(l_fspData->scom_data));

      // Make the firmware_request call
      // Ask the FSP to perform this SCOM operation
      TRACFCOMP(g_trac_fsiscom, "Sending MULTI_SCOM_OP firmware_request");
      l_err = firmware_request_helper(l_req_fw_msg_size,
                                      l_req_fw_msg,
                                      &l_resp_fw_msg_size,
                                      l_resp_fw_msg);

      if (l_err)
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "FSP multi-scom read failed. target 0x%llX",
                   get_huid(i_target));
         break;
      }

      // Create a useful struct to populate the generic_msg::data field
      // Get the command-specific portion of the returned FSP message
      l_fspData =
                  reinterpret_cast<MultiScomReadHbrtFspData_t*>
                                 (&(l_resp_fw_msg->generic_msg.data));
      if (l_fspData->scom_num != l_numScoms)
      {
         // Can't continue because we don't know how the returned SCOM values
         // match with the requested SCOM addresses.

         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "FSP multi-scom read failed. target 0x%llX, "
                   "SCOMs requested(%d) != SCOMs read(%d)",
                   get_huid(i_target), l_numScoms, l_fspData->scom_num);

         /*@
          * @errortype
          * @severity         ERRL_SEV_PREDICTIVE
          * @moduleid         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP
          * @reasoncode       RC_INVALID_LENGTH
          * @userdata1        target's HUID
          * @userdata2[00:31] # of SCOMs requested
          * @userdata2[32:63] # of SCOMs returned
          * @devdesc          Multi-SCOM read did not return correct SCOMs
          * @custdesc         An internal firmware error occurred
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP,
                                         RC_INVALID_LENGTH,
                                         get_huid(i_target),
                                         TWO_UINT32_TO_UINT64(
                                                         l_numScoms,
                                                         l_fspData->scom_num),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

         break;
      }
      o_scomValue.insert(o_scomValue.end(),
                         &(l_fspData->scom_data),
                         &(l_fspData->scom_data) + l_numScoms);
   } while(0);

   // Release the firmware messages and set to NULL
   delete [] l_req_fw_msg;
   delete [] l_resp_fw_msg;
   l_req_fw_msg = l_resp_fw_msg = nullptr;

   if (l_err)
   {
       l_err->collectTrace(FSISCOM_COMP_NAME,512);
   }

   return l_err;
}


}; // end namespace FSISCOM
