/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/runtime/generic_hbrt_fsp_message.H $              */
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
#ifndef __RUNTIME__GENERIC_HBRT_FSP_MESSAGE_H
#define __RUNTIME__GENERIC_HBRT_FSP_MESSAGE_H

#include <builtins.h>

/** @file generic_hbrt_fsp_message.H
 *  @brief A generic structure for passing data
 *
 *  This file has a generic struct to be used by the
 *  FSP/HWSV team to send and receive data.
 */

/**
  * This struct sends an MBox message to the FSP
  */
struct GenericFspMboxMessage_t
{
    uint32_t msgq;     // Example: MBOX::FSP_VPD_MSGQ
    uint32_t msgType;  // Example: VPD_MSG_TYPE:VPD_WRITE_PROC
    struct  // flags
    {
        uint32_t __reserved__async:1;
        uint32_t __reserved__pseudosync:1;
        uint32_t __reserved__unused:30;
    };
    uint64_t data;  // generic member that can be used
                    // to do casting to other types:
                    // MyDataType_t* mydatatype =
                    //              (MyDataType_t*)&(l_generic_msg.data);
} PACKED ;

/**
  * This struct receives the response message from the FSP
  */
struct GenericFspRspMessage_t
{
    uint32_t msgq;     // Example: MBOX::FSP_VPD_MSGQ
    uint32_t msgType;  // Example: VPD_MSG_TYPE:VPD_WRITE_PROC
    struct  // flags
    {
        uint32_t __reserved__async:1;
        uint32_t __reserved__pseudosync:1;
        uint32_t __reserved__unused:30;
    };
    uint32_t errPlid;  // error log id
} PACKED ;


#endif // __RUNTIME__GENERIC_HBRT_FSP_MESSAGE_H
