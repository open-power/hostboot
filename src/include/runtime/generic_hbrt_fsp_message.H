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
  * Values for the GenericFspMboxMessage_t::magic
  * and GenericFspMboxMessage_t::structVer data members
  */
const uint32_t GFMM_MAGIC_NUMBER = 0x4746464D;  // `GFFM`
const uint16_t GFMM_VERSION = 1;

/**
  * Values for the GenericFspMboxMessage_t::__req flag
  */
enum GENERIC_FSP_MBOX_MESSAGE_FLOW
{
    GFMM_RESPONSE = 0,
    GFMM_REQUEST  = 1,
};

/**
  * Values for the GenericFspMboxMessage_t::__onlyError flag
  */
enum GENERIC_FSP_MBOX_MESSAGE_ERROR_FLAG
{
    GFMM_NOT_ERROR_ONLY = 0,
    GFMM_ERROR_ONLY     = 1,
};

/**
  * The different message types for the GenericFspMboxMessage_t
  */
enum GENERIC_FSP_MBOX_MESSAGE_MSG_TYPE
{
    GFMM_MSG_TOD_BACKUP_RESET             = 0x0001,
    GFMM_MSG_TOD_BACKUP_RESET_INFORM_PHYP = 0x0002,
    GFMM_MSG_TOD_TOPOLOGY_DATA            = 0x0003,
    GFMM_MSG_SBE_ERROR                    = 0x000000E1,
    GFMM_MSG_SBE_RECOVERY_SUCCESS         = 0x000000E2,
    GFMM_MSG_SBE_RECOVERY_FAILED          = 0x000000E3,
};

/**
  * This generates a sequence ID that the GenericFspMboxMessage_t
  * consumes.
  */
struct SeqId_t
{
public:
  static uint16_t getNextSeqId();
  static uint16_t getCurrentSeqId();

private:
  static uint16_t GFMM_SEQ_ID;
};

/**
  * This struct sends/receives an MBox message to the FSP
  */
struct GenericFspMboxMessage_t
{
    uint32_t magic;     // ='GFMM'
    uint32_t dataSize;  // total number of bytes in the entire message,
                        // includes structure plus data buffer,
                        // minimum is sizeof(GenericFspMboxMessage_t)
    uint8_t structVer;  // =1, allow for future modifications
    uint8_t reserved;   // unused, just for alignment and expansion
    uint16_t seqnum;    // incremented for each new request, bit0=1 indicates
                        // the request came from the FSP, i.e. 0x0000->0x7FFF
                        // are from HBRT, 0x8000->0xFFFF are from HWSV.
    uint32_t msgq;      // Example: MBOX::FSP_VPD_MSGQ
    uint32_t msgType;   // Example: VPD_MSG_TYPE:VPD_WRITE_PROC
    struct  // flags
    {
        uint32_t __req:1;    // 1=this is a request, 0=this is a response
        uint32_t __async:1;  // =0 for now, future async req/resp support
        uint32_t __onlyError:1; // 1=this is a response that only contains a
                                // single 32-bit plid in the first 4 bytes of
                                // the data payload
        uint32_t __unused:29;   // reserved for future
    };
    uint64_t data;  // generic member that can be used
                    // to do casting to other types:
                    // MyDataType_t* mydatatype =
                    //              (MyDataType_t*)&(l_generic_msg.data);

    // A method to set the local vars to a default state
    void initialize()
    {
        magic = GFMM_MAGIC_NUMBER;
        dataSize = sizeof(GenericFspMboxMessage_t);
        structVer = GFMM_VERSION;
        reserved = 0;
        seqnum = SeqId_t::getNextSeqId();
        msgq = 0;
        msgType = 0;
        __req = GFMM_RESPONSE;
        __async = 0;
        __onlyError = GFMM_NOT_ERROR_ONLY;
        __unused = 0;
        data = 0;
    };
} PACKED ;

#endif // __RUNTIME__GENERIC_HBRT_FSP_MESSAGE_H
