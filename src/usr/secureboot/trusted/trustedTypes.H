/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedTypes.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __TRUSTEDTYPES_H
#define __TRUSTEDTYPES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <secureboot/trustedbootif.H>

namespace TRUSTEDBOOT
{



    /// TPM Algorithm defines
    enum TPM_Alg_Id
    {
        TPM_ALG_SHA1    = 0x0004,
        TPM_ALG_SHA256  = 0x000B,
    };

    /// Common static values
    enum
    {
        MAX_SYSTEM_TPMS = 2,
        TPM_MASTER_INDEX = 0,     ///< Index into tpm array for master chip
        TPM_BACKUP_INDEX = 1,     ///< Index for backup TPM
        MAX_TPM_LOG_MSG = 128,    ///< Maximum log message size

        HASH_COUNT            = 1,       ///< Maximum # of digests
        TPM_ALG_SHA1_SIZE     = 20,      ///< SHA1 digest byte size
        TPM_ALG_SHA256_SIZE   = 32,      ///< SHA256 digest byte size

        // Event types
        EV_NO_ACTION          = 0x3,     ///< Event field contains info
        EV_ACTION             = 0x5,     ///< Must extend a PCR

    };

    /// Class object to store system TPM information
    class SystemTpms
    {
        public:
            SystemTpms();

            TpmTarget tpm[MAX_SYSTEM_TPMS];
    };

    /**
     * @brief Get the digest size of the selected hash algorithm
     * @param[in] i_algId Algorith ID to query
     * @returns digest length in bytes, 0 on invalid algorithm
     */
    uint32_t getDigestSize(TPM_Alg_Id i_algId);


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
    struct TPMS_TAGGED_PROPERTY
    {
        uint32_t property;  ///< TPM_PT_xx identifier
        uint32_t value;     ///< value of the property
    } PACKED;

    struct TPML_TAGGED_TPM_PROPERTY
    {
        uint32_t count;   ///< Number of properties
        TPMS_TAGGED_PROPERTY tpmProperty[MAX_TPM_PROPERTIES];
        uint8_t* unmarshal(uint8_t* i_tpmBuf, size_t & io_tpmBufSize,
                           size_t i_outBufSize);
    } PACKED;

    union TPMU_CAPABILITIES
    {
        // Currently only TPM properties supported
        TPML_TAGGED_TPM_PROPERTY tpmProperties;
    } PACKED;

    struct TPMS_CAPABILITY_DATA
    {
        uint32_t capability;    ///< The capability type
        TPMU_CAPABILITIES data; ///< The capability data
        uint8_t* unmarshal(uint8_t* i_tpmBuf, size_t & io_tpmBufSize,
                           size_t i_outBufSize);
    } PACKED;


    /// SHA1 Event log entry format
    struct TCG_PCR_EVENT
    {
        uint32_t   pcrIndex;    ///< PCRIndex event extended to
        uint32_t   eventType;   ///< Type of event
        uint8_t    digest[20];  ///< Value extended into PCR index
        uint32_t   eventSize;   ///< Size of event data
        uint8_t    event[0];    ///< The event data

        inline size_t marshalSize() const
            { return (sizeof(TCG_PCR_EVENT) + eventSize); }

    } PACKED;

    /// Digest union
    union TPMU_HA
    {
        uint8_t sha1[TPM_ALG_SHA1_SIZE];
        uint8_t sha256[TPM_ALG_SHA256_SIZE];
    } PACKED;

    /// Crypto agile digest
    struct TPMT_HA
    {
        uint16_t   algorithmId; ///< ID of hashing algorithm
        TPMU_HA    digest;      ///< Digest, depends on algorithmid
        inline size_t marshalSize() const;
    } PACKED;

    inline size_t TPMT_HA::marshalSize() const
    {
        return (sizeof(TPMT_HA) - sizeof(TPMU_HA) +
                getDigestSize((TPM_Alg_Id)algorithmId));
    }

    /// Crypto agile digests list
    struct TPML_DIGEST_VALUES
    {
        uint32_t   count;                ///< Number of digests
        TPMT_HA    digests[HASH_COUNT];  ///< Digests
        size_t marshalSize() const;
    } PACKED;

    /// Event field structure
    struct TPM_EVENT_FIELD
    {
        uint32_t   eventSize;               ///< Size of event data
        uint8_t    event[MAX_TPM_LOG_MSG];  ///< The event data
        /**
         * @brief Return size of entire structure
         */
        inline size_t marshalSize() const;
    } PACKED;
    inline size_t TPM_EVENT_FIELD::marshalSize() const
    {
        return (sizeof(eventSize) + eventSize);
    }

    /// Crypto agile log entry format
    struct TCG_PCR_EVENT2
    {
        uint32_t   pcrIndex;    ///< PCRIndex event extended to
        uint32_t   eventType;   ///< Type of event
        TPML_DIGEST_VALUES digests; ///< List of digests extended to PCRIndex
        TPM_EVENT_FIELD event;      ///< Event information

    } PACKED;


    struct TPM2_BaseIn
    {
        uint16_t      tag;         ///< Type TPM_ST_xx
        uint32_t      commandSize; ///< Total # output bytes incl cmdSize & tag
        uint32_t      commandCode; ///< Type TPM_CC_xx
        uint8_t* marshal(uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                         size_t & io_cmdSize);
    } PACKED;

    /// Base of all outgoing messages
    struct TPM2_BaseOut
    {
        uint16_t      tag;          ///< Type TPM_ST_xx
        uint32_t      responseSize; ///< Total # out bytes incl paramSize & tag
        uint32_t      responseCode; ///< The return code of the operation
        uint8_t* unmarshal(uint8_t* i_tpmBuf, size_t & io_tpmBufSize,
                           size_t i_outBufSize);
    } PACKED;

    /// Generic TPM Input Command structure with a 2 byte param
    struct TPM2_2ByteIn
    {
        TPM2_BaseIn  base;
        uint16_t     param;
        uint8_t* marshal(uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                         size_t & io_cmdSize);
    } PACKED;


    /// Generic TPM Output Command structure with a 4 byte return data
    struct TPM2_4ByteOut
    {
        TPM2_BaseOut base;
        uint32_t     resp;
    } PACKED;

    /// Incoming TPM_GetCapability structure
    struct TPM2_GetCapabilityIn
    {
        TPM2_BaseIn  base;
        uint32_t    capability;      ///< group selection
        uint32_t    property;        ///< Further definition
        uint32_t    propertyCount;   ///< Number of properties to return
        uint8_t* marshal(uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                         size_t& io_cmdSize);
    } PACKED;

    /// Outgoing TPM_GetCapability structure
    struct TPM2_GetCapabilityOut
    {
        TPM2_BaseOut base;
        uint8_t     moreData;    ///< Flag to indicate if more values available
        TPMS_CAPABILITY_DATA capData; ///< The capability response
        uint8_t* unmarshal(uint8_t* i_tpmBuf, size_t & io_tpmBufSize,
                           size_t i_outBufSize);
    } PACKED;


    /// Incoming TPM_EXTEND structure
    struct TPM2_ExtendIn
    {
        TPM2_BaseIn  base;
        uint32_t     pcrHandle;     ///< PCR number to extend
        TPML_DIGEST_VALUES digests; ///< Values to be extended
    } PACKED;

} // end TRUSTEDBOOT namespace
#endif

