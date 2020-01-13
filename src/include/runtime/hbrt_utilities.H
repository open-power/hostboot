/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/runtime/hbrt_utilities.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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

#define HBRT_TRACE_NAME "HBRT"

extern trace_desc_t *g_trac_runtime;

#include <vector>

#include "interface.h"                      // hostInterfaces
#include "generic_hbrt_fsp_message.H"       // GenericFspMboxMessage_t, AttributeSetter_t
#include "targeting/common/attributeTank.H" // TARGETING::AttributeTank::Attribute
#include <initservice/initserviceif.H>      // INITSERVICE
#include "util/runtime/rt_fwreq_helper.H"   // firmware_request_helper
#include "runtime/runtime_reasoncodes.H"    // MOD_XXX and RC_XXX

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
 *          the request/response messages' size are equal to each other, request
 *          message is initalized (data size is set) and response message is
 *          zeroed out, upon a successful call else all the output
 *          parameters will either be NULL or 0 based on type.
 *
 *  @note   Use this function iff hbrt_fw_msg::io_type is of type
 *          HBRT_FW_MSG_HBRT_FSP_REQ.
 *
 *  @note   Caller is responsible for deleting (use delete []) the
 *          allocated memory
 *
 *  @param[in] i_fspReqPayloadSize The size of the payload that will
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
 *  @return true if NO issue allocating memory for request/response messages,
 *          else false
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
 *
 *  @param[in] i_attributeList  List of attributes to send to FSP
 *
 *  @return - error, NULL if no error
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

        // Make sure mbox is available
        assert(INITSERVICE::spBaseServicesEnabled(),
               "ERROR: Cannot perform request 'sendAttributes', mbox is not available");

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
                                  GenericFspMboxMessage_t::MSG_DECONFIG_TARGET;

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

#endif //__HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY
#endif // __RUNTIME__UTILITIES_H
