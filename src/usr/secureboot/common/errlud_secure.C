/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/common/errlud_secure.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
/**
 *  @file errlud_secure.C
 *
 *  @brief Implementation of classes to log SECUREBOOT FFDC
 */
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>
#include "errlud_secure.H"
#include <kernel/bltohbdatamgr.H>
#include <securerom/ROM.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <devicefw/driverif.H>
#include <secureboot/nodecommif.H>

namespace SECUREBOOT
{

//------------------------------------------------------------------------------
// Enum defining MAGIC NUMBERS used for checks below
//------------------------------------------------------------------------------
enum {
    PARSER_SIZEOF_SHA512_t           = 64,
    PARSER_SIZEOF_UINT64_t           =  8,
    PARSER_SIZEOF_UINT32_t           =  4,
    PARSER_SIZEOF_UINT8_t            =  1,
    PARSER_SIZEOF_TARGET_HKH_SECTION = 70,
};

//------------------------------------------------------------------------------
//  SECURE System HW Keys Hash User Details
//------------------------------------------------------------------------------
UdSystemHwKeyHash::UdSystemHwKeyHash(const SHA512_t i_hash)
{
    // Set up Ud instance variables
    iv_CompId = SECURE_COMP_ID;
    iv_Version = SECURE_UDT_VERSION_1;
    iv_SubSection = SECURE_UDT_SYSTEM_HW_KEY_HASH;

    //***** Memory Layout *****
    // 64 bytes : SHA512_t of Target HW Key Hash

    static_assert(sizeof(SHA512_t) == PARSER_SIZEOF_SHA512_t, "Expected SHA512_t size is 64 bytes");

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(SHA512_t)) );

    memcpy(l_pBuf, i_hash, sizeof(SHA512_t));
    l_pBuf += sizeof(SHA512_t);
}

//------------------------------------------------------------------------------
UdSystemHwKeyHash::~UdSystemHwKeyHash()
{

}

//------------------------------------------------------------------------------
//  SECURE Target HW Keys Hash User Details
//------------------------------------------------------------------------------
UdTargetHwKeyHash::UdTargetHwKeyHash(const TARGETING::Target * i_target,
                                     const uint8_t i_side,
                                     const SHA512_t i_hash,
                                     const uint8_t i_secure_version)
{
    // Set up Ud instance variables
    iv_CompId = SECURE_COMP_ID;
    iv_Version = SECURE_UDT_VERSION_2;
    iv_SubSection = SECURE_UDT_TARGET_HW_KEY_HASH;

    //***** Version SECURE_UDT_VERSION_1 Memory Layout *****
    // 4 bytes  : Target HUID
    // 1 byte   : SBE EEPROM (Primary or Backup)
    // 64 bytes : SHA512_t of Target HW Key Hash

    //***** Version SECURE_UDT_VERSION_2 Memory Layout *****
    // The following is appended onto VERSION_1 for VERSION_2:
    // 1 byte   : Minimum Secure Version

    static_assert(sizeof(uint32_t)==PARSER_SIZEOF_UINT32_t, "Expected sizeof(uint32_t) is 4");
    static_assert(sizeof(uint8_t)==PARSER_SIZEOF_UINT8_t, "Expected sizeof(uint8_t) is 1");
    static_assert(sizeof(SHA512_t) == PARSER_SIZEOF_SHA512_t, "Expected SHA512_t size is 64 bytes");
    static_assert((sizeof(uint32_t) + sizeof(uint8_t) + sizeof(SHA512_t)+sizeof(uint8_t))
                  == PARSER_SIZEOF_TARGET_HKH_SECTION, "Expected Buffer length is 70 bytes");

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint32_t)
                                        +sizeof(uint8_t)
                                        +sizeof(SHA512_t)
                                        +sizeof(uint8_t)));

    uint32_t tmp32 = 0;
    uint8_t tmp8 = 0;

    tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp8 = static_cast<uint8_t>(i_side);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    memcpy(l_pBuf, i_hash, sizeof(SHA512_t));
    l_pBuf += sizeof(SHA512_t);

    tmp8 = static_cast<uint8_t>(i_secure_version);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);
}

//------------------------------------------------------------------------------
UdTargetHwKeyHash::~UdTargetHwKeyHash()
{

}

//------------------------------------------------------------------------------
//  SECURE Security Settings User Details
//------------------------------------------------------------------------------
UdSecuritySettings::UdSecuritySettings()
{
    // Set up Ud instance variables
    iv_CompId = SECURE_COMP_ID;
    iv_Version = SECURE_UDT_VERSION_2;
    iv_SubSection = SECURE_UDT_SECURITY_SETTINGS;

    char * l_pBuf = reinterpret_cast<char *>(reallocUsrBuf(
                                                        sizeof(detailsLayout)));

    detailsLayout * l_pDetailsLayout = reinterpret_cast<detailsLayout *>(l_pBuf);

    //***** Version SECURE_UDT_VERSION_1 Memory Layout *****
    // 1 byte   : Secure Access Bit
    // 1 byte   : Security Override
    // 1 byte   : Allow Attribute Overrides

    //***** Version SECURE_UDT_VERSION_2 Memory Layout *****
    // The following is appended onto VERSION_1 for VERSION_2:
    // 1 byte   : Minimum Secure Version

    l_pDetailsLayout->secAccessBit = 0xFF;
    l_pDetailsLayout->secOverride = 0xFF;
    l_pDetailsLayout->allowAttrOverride = 0xFF;
    l_pDetailsLayout->minSecureVersion = 0xFF;

#ifndef __HOSTBOOT_RUNTIME
    // Only check BlToHbData if it is valid, otherwise fields defaulted to 0xFF
    if (g_BlToHbDataManager.isValid())
    {
        l_pDetailsLayout->secAccessBit = g_BlToHbDataManager.getSecureAccessBit();
        l_pDetailsLayout->secOverride = g_BlToHbDataManager.getSecurityOverride();
        l_pDetailsLayout->allowAttrOverride = g_BlToHbDataManager.getAllowAttrOverrides();
        l_pDetailsLayout->minSecureVersion = g_BlToHbDataManager.getMinimumSecureVersion();
    }
#endif

}

//------------------------------------------------------------------------------
UdSecuritySettings::~UdSecuritySettings()
{

}

//------------------------------------------------------------------------------
//  SECURE Verify Info User Details
//------------------------------------------------------------------------------
UdVerifyInfo::UdVerifyInfo(const char* i_compId,
                           const uint64_t i_protectedSize,
                           const RomVerifyIds& i_ids,
                           const SHA512_t& i_measuredHash,
                           const SHA512_t& i_expectedHash,
                           const uint8_t i_min_secure_version,
                           const uint8_t i_input_secure_version,
                           const uint8_t i_container_secure_version)
{
    // Set up Ud instance variables
    iv_CompId = SECURE_COMP_ID;
    iv_Version = SECURE_UDT_VERSION_2;
    iv_SubSection = SECURE_UDT_VERIFY_INFO;

    //***** Version SECURE_UDT_VERSION_1 Memory Layout *****
    // 9 bytes Max : Component ID (8 byte string + NULL) use strlen
    // 8 bytes     : Protected Payload Size
    // 4 bytes   : Number of IDs
    // 4*N bytes : IDs (PNOR id or LidID) multiplied by number of ids
    // 64 bytes  : Measured Hash
    // 64 bytes  : Expected Hash

    //***** Version SECURE_UDT_VERSION_2 Memory Layout *****
    // VERSION_2 appends the following:
    // 1 byte    : Minimum FW Secure Version
    // 1 byte    : Input Secure Version
    // 1 byte    : Container Secure Version

    const size_t compSize=strlen(i_compId)+1;
    uint64_t protectedSize=i_protectedSize;
    uint32_t ids=i_ids.size();
    uint32_t idType=0;
    const size_t totalSize=
          compSize
        + sizeof(protectedSize)
        + sizeof(ids)
        + sizeof(idType)*ids
        + PARSER_SIZEOF_SHA512_t
        + PARSER_SIZEOF_SHA512_t
        + 3 * sizeof(uint8_t); // For 3 Secure Versions

    auto l_pBuf = reinterpret_cast<char *>(reallocUsrBuf(totalSize));
    memcpy(l_pBuf,i_compId,compSize);
    l_pBuf+=compSize;
    *reinterpret_cast<decltype(protectedSize)*>(l_pBuf)=i_protectedSize;
    l_pBuf+=sizeof(protectedSize);
    *reinterpret_cast<decltype(ids)*>(l_pBuf)=ids;
    l_pBuf+=sizeof(ids);
    for(const auto id : i_ids)
    {
        *reinterpret_cast<decltype(idType)*>(l_pBuf)=id;
        l_pBuf+=sizeof(idType);
    }
    memcpy(l_pBuf,i_measuredHash, PARSER_SIZEOF_SHA512_t);
    l_pBuf+=PARSER_SIZEOF_SHA512_t;
    memcpy(l_pBuf,i_expectedHash, PARSER_SIZEOF_SHA512_t);
    l_pBuf+=PARSER_SIZEOF_SHA512_t;

    uint8_t tmp8 = static_cast<uint8_t>(i_min_secure_version);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = static_cast<uint8_t>(i_input_secure_version);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = static_cast<uint8_t>(i_container_secure_version);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);
}


//------------------------------------------------------------------------------
//  SECURE Node Communications Info User Details
//------------------------------------------------------------------------------
UdNodeCommInfo::UdNodeCommInfo(const uint8_t i_opType,
                   const uint64_t i_buflen,
                   const int64_t i_accessType,
                   const NODECOMM::node_comm_args_t i_args  )

{
    // Set up Ud instance variables
    iv_CompId = SECURE_COMP_ID;
    iv_Version = SECURE_UDT_VERSION_1;
    iv_SubSection = SECURE_UDT_NODECOMM_INFO;

    //***** Node Comm SECURE_UDT_VERSION_1 Memory Layout *****
    // 4 bytes  : Target HUID
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : Access Type (DeviceFW::AccessType)
    // 1 byte   : Op Type (DeviceFW::OperationType)
    // 1 byte   : Mode (XBUS or ABUS)
    // 1 byte   : LinkId
    // 1 byte   : MboxId

    static_assert(sizeof(uint64_t)==PARSER_SIZEOF_UINT64_t,
                  "Expected sizeof(uint64_t) is 8");

    // These are necessary to keep the parsing in errludP_secure.H correct
    static_assert(DeviceFW::READ==0, "Expected opType READ == 0");
    static_assert(DeviceFW::WRITE==1, "Expected opType WRITE == 1");
    static_assert(SECUREBOOT::NODECOMM::NCDD_MODE_XBUS==0,
                  "Expected NCDD_MODE_XBUS==0");
    static_assert(SECUREBOOT::NODECOMM::NCDD_MODE_ABUS==1,
                  "Expected NCDD_MODE_ABUS==1");

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint32_t)
                                        +sizeof(uint64_t)*2
                                        +sizeof(uint8_t)*4 ) );
    uint64_t tmp64 = 0;
    uint32_t tmp32 = 0;
    uint8_t tmp8 = 0;

    tmp32 = i_args.tgt_huid;
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_buflen;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_accessType;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = i_opType;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_args.mode;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_args.linkId;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_args.mboxId;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

};

} // end SECUREBOOT namespace

