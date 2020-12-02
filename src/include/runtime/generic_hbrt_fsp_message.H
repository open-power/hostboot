/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/runtime/generic_hbrt_fsp_message.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
 *
 *  @brief A generic structure for passing data
 *
 *  This file has a generic struct to be used by the
 *  FSP/HWSV team to send and receive data.
 *
 *  @note  See README.md file on how to create an HBRT to FW
 *         request/notify message interface
 */

// Sentinel value for bad SCOM reads
#define DEADBEEF 0xDEADBEEF

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


// Latest attribute setter (struct AttributeSetter_t) version
enum ATTRIBUTE_SETTER_VERSION: uint8_t
{
    ATTRIBUTE_STRUCT_VERSION_FIRST = 0x01,
    ATTRIBUTE_STRUCT_VERSION_LATEST = ATTRIBUTE_STRUCT_VERSION_FIRST,
};

/**
  * A useful struct to serialize/deserialize the Attributes data
  * from GenericFspMboxMessage_t::data.
  */
struct AttributeSetter_t // a firmware_request call
{
    ATTRIBUTE_SETTER_VERSION iv_structVersion;// latest attribute setter version
    uint8_t  iv_reserved;
    uint16_t iv_numAttributes; // number of attributes being sent
    uint8_t  iv_attrData[];    // points to a stream of
                               // AttributeTank::Attribute structures
    // A method to set the local vars to a default state
    void initialize()
    {
        iv_structVersion = ATTRIBUTE_STRUCT_VERSION_LATEST;
        iv_reserved = 0;
        iv_numAttributes = 0;
    };
} PACKED ;

/**
  * A useful struct to pack/access the HUID and HWAS state
  * from the GenericFspMboxMessage_t.data.
  * The HUID will be in the first 4 bytes followed by the HWAS state.
  *
  * @note message queue = MBOX::FSP_TARG_DECONFIG_MSGQ;
  *       message type  = MSG_DECONFIG_TARGET
  */
struct TargetDeconfigHbrtFspData_t  // a firmware_request call
{
   uint32_t huid;
   TARGETING::HwasState hwasState;
} PACKED ;


/**
  * This struct contains the message-specific data for
  * MSG_SINGLE_SCOM_OP calls to the FSP.
  * It shows the format of GenericFspMboxMessage_t.data.
  *
  * @note message queue = MBOX::FSP_SCOM_OPS_MSGQ
  *       message type  = MSG_SINGLE_SCOM_OP
  */
struct SingleScomOpHbrtFspData_t // a firmware_request call
{
    uint8_t     scom_op;    // DeviceFW::READ, DeviceFW::WRITE
    uint32_t    huid;       // hardware target
    uint64_t    scom_addr;
    uint64_t    scom_data;  // SCOM value read by FSP, or
                            // SCOM value to be written by FSP
} PACKED;


/**
  * This struct contains the message-specific data for
  * MSG_MULTI_SCOM_OP calls to the FSP.
  * It shows the format of GenericFspMboxMessage_t.data.
  *
  * @note message queue = MBOX::FSP_SCOM_OPS_MSGQ
  *       message type  = MSG_MULTI_SCOM_OP
  */
struct MultiScomReadHbrtFspData_t  // a firmware_request call
{
    uint32_t    huid;       // hardware target
    uint8_t     scom_num;   // number of SCOMs to read
    uint64_t    scom_data;  // addresses of SCOMs to read, or
                            // values of SCOMs in FSP response
                            //
                            // ** if a SCOM cannot be read, its value **
                            // ** should be returned as DEADBEEF      **
                            //
                            // placeholder that can be cast to an array
                            // of SCOM addresses (or values)
                            // uint64_t* mydata =
                            //              (uint64_t*)&(l_generic_msg.data);
                            // more than 8 bytes of data is possible
} PACKED;


/**
  * A useful struct to access the PLID from GenericFspMboxMessage_t.data
  * in the case where the FSP is requesting Hostboot to restart a SBE
  *
  * @note message queue = MBOX::FSP_SCOM_OPS_MSGQ
  *       message type  = MSG_SBE_ERROR
  */
struct SbeRetryReqData_t  // a firmware_notify call
{
   uint32_t huid;
   uint32_t plid;
} PACKED ;


/**
  * A useful struct to access the HUID, attribute ID and attribute data
  * from the GenericFspMboxMessage_t.data
  *
  * The HUID will be the first 4 bytes followed by a 4-byte attribute ID,
  * then a 4-byte size of attribute data, and finally the attribute's data
  *
  * @note message queue = MBOX::HB_ATTR_SYNC_MSGQ
  *       message type  = MSG_ATTR_SYNC_REQUEST
  */
struct HbrtAttrSyncData_t  // a firmware_notify call
{
    // HUID of target on which we want to update the attribute
    uint32_t huid;

    // Attribute ID of attribute to update
    TARGETING::ATTRIBUTE_ID attrID;

    // size of attribute data in bytes
    uint32_t sizeOfAttrData;

    // first byte of <sizeOfAttrData> bytes of attribute data
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
    static constexpr uint32_t FSP_HBRT_MESSAGEQ = 0x8000000F;

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
        MSG_DECONFIG_TARGET              = 0x0004,  // for TargetDeconfigHbrtFspData_t
        MSG_SINGLE_SCOM_OP               = 0x0005,  // for SingleScomOpHbrtFspData_t
        MSG_MULTI_SCOM_OP                = 0x0006,  // for MultiScomReadHbrtFspData_t
        MSG_ATTR_WRITE_OP                = 0x0007,  // for AttributeSetter_t
        MSG_ATTR_SYNC_REQUEST            = 0x000000A5, // for HbrtAttrSyncData_t
        MSG_OCC_ACTIVE                   = 0x000000A6,
        MSG_SBE_ERROR                    = 0x000000D4, // for SbeRetryReqData_t
        MSG_SBE_RECOVERY_SUCCESS         = 0x000000D5, // associated with SbeRetryReqData_t
        MSG_SBE_RECOVERY_FAILED          = 0x000000D6, // associated with SbeRetryReqData_t
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
    uint32_t msgType;   // Example: VPD_MSG_TYPE:VPD_WRITE_CACHE
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
                    // more than 8 bytes of data is possible

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
