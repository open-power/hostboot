/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/runtime/hbrt_utilities.H $                        */
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
#ifndef __RUNTIME__UTILITIES_H
#define __RUNTIME__UTILITIES_H

#ifndef __HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY

#include "interface.h"

/** @file hbrt_utilities.H
 *  @brief A file to put HBRT Interface utilities
 *
 *  This file contains utilities that facilitate
 *  the usage of the HBRT Interface
 */

/**
 *  @brief  A handy utility to create the firmware request and response
 *          messages, for FSP, where the messages must be of equal size.
 *
 *  @par Detailed Description
 *          This method will take the size of the Generic FSP Message
 *          payload, the data to populate GenericFspMboxMessage_t::data,
 *          and calculate the size requirements for both request and
 *          response messages.
 *
 *  @pre    The input payload size is of reasonable length and the
 *          request/response messages are at most set to nullptr or at
 *          least do not point to valid objects (they will be assigned
 *          to newly created data.)
 *
 *  @post   The request/response messages point to a valid struct,
 *          the request/response message size are equal to each other
 *          and contain the size of the request/response messages
 *          respectively upon a successful call else all the output
 *          parameters will either be NULL or 0 based on type.
 *
 *  @note   Use this function iff hbrt_fw_msg::io_type is of type
 *          HBRT_FW_MSG_HBRT_FSP_REQ.
 *
 *  @note   Caller is responsible for deleting (use delete []) the
 *          allocated memory
 *
 *  @param[in] i_fspReqPayloadSize  The size of the payload that will
 *                                 populate GenericFspMboxMessage_t::data
 *  @param[out] o_fspMsgSize       Return the size of the
 *                                 GenericFspMboxMessage_t, adjusted to
 *                                 accommodate input payload
 *  @param[out] o_requestMsgSize   The size of the hbrt_fw_msg request msg
 *  @param[out] o_requestMsg       The allocated request message (not NULL)
 *  @param[out] o_responseMsgSize  The size of the hbrt_fw_msg respone msg,
 *                                 will be equal to the request msg size
 *  @param[out] o_responseMsg      The allocated response message (not
 *                                 NULL), zeroed out
 */
void createGenericFspMsg(uint32_t i_fspReqPayloadSize,
                       uint32_t &o_fspMsgSize,
                       uint64_t &o_requestMsgSize,
                       hostInterfaces::hbrt_fw_msg* &o_requestMsg,
                       uint64_t &o_responseMsgSize,
                       hostInterfaces::hbrt_fw_msg* &o_responseMsg)
{
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

   // If anyone of these two message's memory can't be allocated, then
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
}  // end createGenericFspMsg

#endif //__HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY
#endif // __RUNTIME__UTILITIES_H
