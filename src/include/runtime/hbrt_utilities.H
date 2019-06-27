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
                         hostInterfaces::hbrt_fw_msg* &o_responseMsg);



/**
 *  @brief  Serializes a list of Attributes to be sent to FSP
 *
 *  @param[in] i_attributeList  List of attributes to send to FSP
 *
 *  @return - error, NULL if no error
 */
errlHndl_t sendAttributes(const std::vector<TARGETING::AttributeTank::Attribute>&
                          i_attributeList);

#endif //__HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY
#endif // __RUNTIME__UTILITIES_H
