/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedTypes.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
 * @file trustedTypes.H
 *
 * @brief Trustedboot TPM Types
 *
 */

/////////////////////////////////////////////////////////////////
// NOTE: This file is exportable as TSS-Lite for skiboot/PHYP  //
/////////////////////////////////////////////////////////////////

#ifndef __TRUSTEDTYPES_H
#define __TRUSTEDTYPES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <stdint.h>
#ifdef __HOSTBOOT_MODULE
#include <builtins.h>
#else
#include "trustedboot.H"
#define PACKED __attribute__((__packed__))
#endif

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif


    /// TPM Algorithm defines
    typedef enum
    {
        TPM_ALG_SHA1    = 0x0004,   ///< SHA1 Id
        TPM_ALG_SHA256  = 0x000B,   ///< SHA256 Id
        TPM_ALG_INVALID_ID          ///< Used for error checking
    } TPM_Alg_Id;

    typedef enum
    {
        TPM_ALG_NUM_SUPPORTED = 1,       ///< Number of algorithms supported
        TPM_ALG_SHA1_SIZE     = 20,      ///< SHA1 digest byte size
        TPM_ALG_SHA256_SIZE   = 32,      ///< SHA256 digest byte size
        TPM_ALG_INVALID_SIZE             ///< Used for error checking
    } TPM_Alg_Sizes;

    /// Common static values
    enum
    {
        MAX_SYSTEM_TPMS = 2,
        TPM_MASTER_INDEX = 0,     ///< Index into tpm array for master chip
        TPM_BACKUP_INDEX = 1,     ///< Index for backup TPM
        MAX_TPM_LOG_MSG = 128,    ///< Maximum log message size

        HASH_COUNT            = 1,       ///< Maximum # of digests
    };

    typedef enum
    {
        EV_NO_ACTION    = 0x3,     ///< Event field contains info
        EV_SEPARATOR    = 0x4,     ///< Used to indicate an error
        EV_ACTION       = 0x5,     ///< Must extend a PCR
        EV_INVALID                 ///< Used for error checking
    } EventTypes;

    /**
     * @brief Get the digest size of the selected hash algorithm
     * @param[in] i_algId Algorith ID to query
     * @returns digest length in bytes, 0 on invalid algorithm
     */
    uint32_t getDigestSize(const TPM_Alg_Id i_algId)  __attribute__ ((const));


    /// Various static values
    enum
    {
        // TPM Spec supported
        TPM_SPEC_MAJOR        = 2,
        TPM_SPEC_MINOR        = 0,
        TPM_SPEC_ERRATA       = 0,
        TPM_PLATFORM_SERVER   = 1,

        // Command structure tags
        TPM_ST_NO_SESSIONS        = 0x8001,    ///< A command with no sess/auth
        TPM_ST_SESSIONS           = 0x8002,    ///< A command has sessions

        // Command Codes
        TPM_CC_Startup            = 0x00000144,
        TPM_CC_GetCapability      = 0x0000017A,
        TPM_CC_PCR_Read           = 0x0000017E,
        TPM_CC_PCR_Extend         = 0x00000182,


        // TPM Startup types
        TPM_SU_CLEAR              = 0x0000,///< TPM perform reset,restart
        TPM_SU_STATE              = 0x0001,///< TPM perform restore saved state

        // Capability
        MAX_TPM_PROPERTIES        = 2,
        TPM_CAP_TPM_PROPERTIES    = 0x00000006, ///< Pull TPM Properties

        // TPM Properties
        TPM_PT_MANUFACTURER       = 0x00000105,
        TPM_PT_FIRMWARE_VERSION_1 = 0x0000010B,
        TPM_PT_FIRMWARE_VERSION_2 = 0x0000010C,


        // TPM Return Codes
        TPM_SUCCESS               = 0x000,

        TPM_RC_INITIALIZE         = 0x100,

    };


    // Command structures taken from Trusted Platform Module Library Part 3:
    //    Commands Family "2.0"

    /// TPM capability response structure
    struct _TPMS_TAGGED_PROPERTY
    {
        uint32_t property;  ///< TPM_PT_xx identifier
        uint32_t value;     ///< value of the property
    } PACKED;
    typedef struct _TPMS_TAGGED_PROPERTY TPMS_TAGGED_PROPERTY;

    struct _TPML_TAGGED_TPM_PROPERTY
    {
        uint32_t count;   ///< Number of properties
        TPMS_TAGGED_PROPERTY tpmProperty[MAX_TPM_PROPERTIES];
    } PACKED;
    typedef struct _TPML_TAGGED_TPM_PROPERTY TPML_TAGGED_TPM_PROPERTY;
    uint8_t* TPML_TAGGED_TPM_PROPERTY_unmarshal(TPML_TAGGED_TPM_PROPERTY* val,
                       uint8_t* i_tpmBuf, size_t* io_tpmBufSize);

    union _TPMU_CAPABILITIES
    {
        // Currently only TPM properties supported
        TPML_TAGGED_TPM_PROPERTY tpmProperties;
    } PACKED;
    typedef union _TPMU_CAPABILITIES TPMU_CAPABILITIES;

    struct _TPMS_CAPABILITY_DATA
    {
        uint32_t capability;    ///< The capability type
        TPMU_CAPABILITIES data; ///< The capability data
    } PACKED;
    typedef struct _TPMS_CAPABILITY_DATA TPMS_CAPABILITY_DATA;
    uint8_t* TPMS_CAPABILITY_DATA_unmarshal(TPMS_CAPABILITY_DATA* val,
                                            uint8_t* i_tpmBuf,
                                            size_t * io_tpmBufSize);


    /// SHA1 Event log entry format
    struct _TCG_PCR_EVENT
    {
        uint32_t   pcrIndex;    ///< PCRIndex event extended to
        uint32_t   eventType;   ///< Type of event
        uint8_t    digest[20];  ///< Value extended into PCR index
        uint32_t   eventSize;   ///< Size of event data
        uint8_t    event[MAX_TPM_LOG_MSG]; ///< The event data
    } PACKED;
    typedef struct _TCG_PCR_EVENT TCG_PCR_EVENT;
    size_t TCG_PCR_EVENT_marshalSize(TCG_PCR_EVENT* val);
    uint8_t* TCG_PCR_EVENT_logUnmarshal(TCG_PCR_EVENT* val, uint8_t* i_tpmBuf,
                                        size_t i_bufSize, bool* o_err);
    uint8_t* TCG_PCR_EVENT_logMarshal(TCG_PCR_EVENT* val, uint8_t* i_logBuf);

    /// Digest union
    union _TPMU_HA
    {
        uint8_t bytes[0];
        uint8_t sha1[TPM_ALG_SHA1_SIZE];
        uint8_t sha256[TPM_ALG_SHA256_SIZE];
    } PACKED;
    typedef union _TPMU_HA TPMU_HA;

    /// Crypto agile digest
    struct _TPMT_HA
    {
        uint16_t   algorithmId; ///< ID of hashing algorithm
        TPMU_HA    digest;      ///< Digest, depends on algorithmid
    } PACKED;
    typedef struct _TPMT_HA TPMT_HA;
    size_t TPMT_HA_marshalSize(TPMT_HA* val);
    uint8_t* TPMT_HA_logMarshal(TPMT_HA* val, uint8_t* i_logBuf);


    /// Crypto agile digests list
    struct _TPML_DIGEST_VALUES
    {
        uint32_t   count;                ///< Number of digests
        TPMT_HA    digests[HASH_COUNT];  ///< Digests
    } PACKED;
    typedef struct _TPML_DIGEST_VALUES TPML_DIGEST_VALUES;
    size_t TPML_DIGEST_VALUES_marshalSize(TPML_DIGEST_VALUES* val);
    uint8_t* TPML_DIGEST_VALUES_logMarshal(TPML_DIGEST_VALUES* val,
                                           uint8_t* i_logBuf);

    /// Event field structure
    struct _TPM_EVENT_FIELD
    {
        uint32_t   eventSize;               ///< Size of event data
        uint8_t    event[MAX_TPM_LOG_MSG];  ///< The event data
    } PACKED;
    typedef struct _TPM_EVENT_FIELD TPM_EVENT_FIELD;
    size_t TPM_EVENT_FIELD_marshalSize(TPM_EVENT_FIELD* val);
    uint8_t* TPM_EVENT_FIELD_logMarshal(TPM_EVENT_FIELD* val,
                                        uint8_t* i_logBuf);

    /// Crypto agile log entry format
    struct _TCG_PCR_EVENT2
    {
        uint32_t   pcrIndex;    ///< PCRIndex event extended to
        uint32_t   eventType;   ///< Type of event
        TPML_DIGEST_VALUES digests; ///< List of digests extended to PCRIndex
        TPM_EVENT_FIELD event;      ///< Event information
    } PACKED;
    typedef struct _TCG_PCR_EVENT2 TCG_PCR_EVENT2;
    uint8_t* TCG_PCR_EVENT2_logMarshal(TCG_PCR_EVENT2* val,
                                       uint8_t* i_logBuf);
    size_t TCG_PCR_EVENT2_marshalSize(TCG_PCR_EVENT2* val);

    struct _TPM2_BaseIn
    {
        uint16_t      tag;         ///< Type TPM_ST_xx
        uint32_t      commandSize; ///< Total # output bytes incl cmdSize & tag
        uint32_t      commandCode; ///< Type TPM_CC_xx
    } PACKED;
    typedef struct _TPM2_BaseIn TPM2_BaseIn;
    uint8_t* TPM2_BaseIn_marshal(TPM2_BaseIn* val, uint8_t* o_tpmBuf,
                                 size_t i_tpmBufSize, size_t* io_cmdSize);

    /// Base of all outgoing messages
    struct _TPM2_BaseOut
    {
        uint16_t      tag;          ///< Type TPM_ST_xx
        uint32_t      responseSize; ///< Total # out bytes incl paramSize & tag
        uint32_t      responseCode; ///< The return code of the operation
    } PACKED;
    typedef struct _TPM2_BaseOut TPM2_BaseOut;
    uint8_t* TPM2_BaseOut_unmarshal(TPM2_BaseOut* val, uint8_t* i_tpmBuf,
                                    size_t* io_tpmBufSize, size_t i_outBufSize);

    /// Generic TPM Input Command structure with a 2 byte param
    struct _TPM2_2ByteIn
    {
        TPM2_BaseIn  base;
        uint16_t     param;
    } PACKED;
    typedef struct _TPM2_2ByteIn TPM2_2ByteIn;
    uint8_t* TPM2_2ByteIn_marshal(TPM2_2ByteIn* val, uint8_t* o_tpmBuf,
                                  size_t i_tpmBufSize, size_t* io_cmdSize);


    /// Generic TPM Output Command structure with a 4 byte return data
    struct _TPM2_4ByteOut
    {
        TPM2_BaseOut base;
        uint32_t     resp;
    } PACKED;
    typedef struct _TPM2_4ByteOut TPM2_4ByteOut;

    /// Incoming TPM_GetCapability structure
    struct _TPM2_GetCapabilityIn
    {
        TPM2_BaseIn  base;
        uint32_t    capability;      ///< group selection
        uint32_t    property;        ///< Further definition
        uint32_t    propertyCount;   ///< Number of properties to return
    } PACKED;
    typedef struct _TPM2_GetCapabilityIn TPM2_GetCapabilityIn;
    uint8_t* TPM2_GetCapabilityIn_marshal(TPM2_GetCapabilityIn* val,
                                          uint8_t* o_tpmBuf,
                                          size_t i_tpmBufSize,
                                          size_t* io_cmdSize);

    /// Outgoing TPM_GetCapability structure
    struct _TPM2_GetCapabilityOut
    {
        TPM2_BaseOut base;
        uint8_t     moreData;    ///< Flag to indicate if more values available
        TPMS_CAPABILITY_DATA capData; ///< The capability response
    } PACKED;
    typedef struct _TPM2_GetCapabilityOut TPM2_GetCapabilityOut;
    uint8_t* TPM2_GetCapabilityOut_unmarshal(TPM2_GetCapabilityOut* val,
                                             uint8_t* i_tpmBuf,
                                             size_t* io_tpmBufSize,
                                             size_t i_outBufSize);

    /// Incoming TPM_EXTEND structure
    struct _TPM2_ExtendIn
    {
        TPM2_BaseIn  base;
        uint32_t     pcrHandle;     ///< PCR number to extend
        TPML_DIGEST_VALUES digests; ///< Values to be extended
    } PACKED;
    typedef struct _TPM2_ExtendIn TPM2_ExtendIn;

#ifdef __cplusplus
} // end TRUSTEDBOOT namespace
#endif

#endif

