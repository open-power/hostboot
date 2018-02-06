/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/runtime/generic_hbrt_fsp_message.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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

#include <targeting/common/attributes.H>   // TARGETING::HwasState
#include <attributeenums.H>                // ATTRIBUTE_ID


/** @file generic_hbrt_fsp_message.H
 *  @brief A generic structure for passing data
 *
 *  This file has a generic struct to be used by the
 *  FSP/HWSV team to send and receive data.
 */

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
  static uint16_t SEQ_ID;
};


/**
  * A useful struct to pack/access the HUID and HWAS state
  * from the GenericFspMboxMessage_t.data.
  * The HUID will be in the first 4 bytes followed by the HWAS state.
  */
struct TargetDeconfigHbrtFspData_t
{
   uint32_t huid;
   TARGETING::HwasState hwasState;
} PACKED ;


/**
  * A useful struct to access the PLID from GenericFspMboxMessage_t.data
  * The PLID will be in the first 4 bytes followed by some other data.
  */
struct HbrtFspData_t
{
   uint32_t plid;
   uint32_t userData;
} PACKED ;


/**
  * A useful struct to access the HUID, attribute ID and attribute data
  * from the GenericFspMboxMessage_t.data
  *
  * The HUID will be the first 4 bytes followed by a 4-byte attribute ID,
  * then a 4-byte size of attribute data, and finally the attribute's data
  *
  */
struct HbrtAttrSyncData_t
{
    uint32_t huid;
    TARGETING::ATTRIBUTE_ID attrID;
    uint32_t sizeOfAttrData;
    uint8_t attrDataStart;
} PACKED ;

/**
  * This struct sends/receives an MBox message to the FSP
  */
struct GenericFspMboxMessage_t
{

    /**
      * Value for the GenericFspMboxMessage_t::magic
      */
    static constexpr uint32_t MAGIC_NUMBER = 0x4746464D;  // `GFFM`

   /**
    * GenericFspMboxMessage_t Version info
    *
    */
    enum GENERIC_FSP_MBOX_MESSAGE_VERSION
    {
       STRUCT_VERSION_FIRST = 0x1,
       STRUCT_VERSION_LATEST = STRUCT_VERSION_FIRST,
    };

    /**
      * Values for the GenericFspMboxMessage_t::__req flag
      */
    enum GENERIC_FSP_MBOX_MESSAGE_FLOW
    {
        RESPONSE = 0,
        REQUEST  = 1,
    };

    /**
      * Values for the GenericFspMboxMessage_t::__onlyError flag
      */
    enum GENERIC_FSP_MBOX_MESSAGE_ERROR_FLAG
    {
        NOT_ERROR_ONLY = 0,
        ERROR_ONLY     = 1,
    };

    /**
      * The different message types for the GenericFspMboxMessage_t
      */
    enum GENERIC_FSP_MBOX_MESSAGE_MSG_TYPE
    {
        MSG_TOD_BACKUP_RESET             = 0x0001,
        MSG_TOD_BACKUP_RESET_INFORM_PHYP = 0x0002,
        MSG_TOD_TOPOLOGY_DATA            = 0x0003,
        MSG_DECONFIG_TARGET              = 0x0004,
        MSG_ATTR_SYNC_REQUEST            = 0x000000A5,
        MSG_SBE_ERROR                    = 0x000000E1,
        MSG_SBE_RECOVERY_SUCCESS         = 0x000000E2,
        MSG_SBE_RECOVERY_FAILED          = 0x000000E3,
    };

    /**
      * GenericFspMboxMessage_t data members
      */
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
        magic = MAGIC_NUMBER;
        dataSize = sizeof(GenericFspMboxMessage_t);
        structVer = STRUCT_VERSION_LATEST;
        reserved = 0;
        seqnum = SeqId_t::getNextSeqId();
        msgq = 0;
        msgType = 0;
        __req = RESPONSE;
        __async = 0;
        __onlyError = NOT_ERROR_ONLY;
        __unused = 0;
        data = 0;
    };
} PACKED ;

// Handy macro that computes the size of the message minus the data portion
#define GENERIC_FSP_MBOX_MESSAGE_BASE_SIZE \
   (sizeof(GenericFspMboxMessage_t)-sizeof(GenericFspMboxMessage_t::data))

#endif // __RUNTIME__GENERIC_HBRT_FSP_MESSAGE_H
