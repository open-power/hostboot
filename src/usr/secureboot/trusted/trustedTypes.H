/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedTypes.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
#include <secureboot/trustedbootif.H>
#else
#include "trustedboot.H"
#define PACKED __attribute__((__packed__))
#endif

#include <limits.h>

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

    // TPM Command buffer sizes
    enum
    {
        BUFSIZE         = 256,
        MAX_TRANSMIT_SIZE = 1024, ///< Maximum send/receive transmit size
    };

    typedef enum
    {
        TPM_ALG_SHA256_SIZE   = 32,      ///< SHA256 digest byte size
        TPM_ALG_INVALID_SIZE             ///< Used for error checking
    } TPM_Alg_Sizes;

    /// Common static values
    enum
    {
        MAX_TPM_LOG_MSG = PAGESIZE * 2,  ///< Maximum log message size

        HASH_COUNT            = 1,       ///< Maximum # of digests

        PCR_SELECT_MAX = (IMPLEMENTATION_PCR+7)/8, ///< PCR selection octet max

        // Certificate NV indices
        NVIDX_RSAEKCERT = 0x01C00002,       ///< RSA EK certificate NV index
        NVIDX_ECC_P256_EKCERT = 0x01C0000A, ///< ECC NIST-P256 EK certificate NV index
        NVIDX_ECC_P384_EKCERT = 0x01C00016, ///< ECC NIST-P384 EK certificate NV index
        NVIDX_IBMPLATCERT0 = 0x01C10180,    ///< IBM Platform certificate 0 NV index
        NVIDX_IBMPLATCERT1 = 0x01C10181,    ///< IBM Platform certificate 1 NV index
        NVIDX_IBMPLATCERT2 = 0x01C10182,    ///< IBM Platform certificate 2 NV index
    };

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
        TPM_SPEC_ERRATA       = 2,
        TPM_PLATFORM_SERVER   = 1,

        // Command structure tags
        TPM_ST_NO_SESSIONS        = 0x8001,    ///< A command with no sess/auth
        TPM_ST_SESSIONS           = 0x8002,    ///< A command has sessions

        // Command Codes
        TPM_CC_CreatePrimary      = 0x00000131,
        TPM_CC_Startup            = 0x00000144,
        TPM_CC_NV_Read            = 0x0000014E,
        TPM_CC_Quote              = 0x00000158,
        TPM_CC_FlushContext       = 0x00000165,
        TPM_CC_GetCapability      = 0x0000017A,
        TPM_CC_GetRandom          = 0x0000017B,
        TPM_CC_PCR_Read           = 0x0000017E,
        TPM_CC_PCR_Extend         = 0x00000182,


        // TPM Startup types
        TPM_SU_CLEAR              = 0x0000,///< TPM perform reset,restart
        TPM_SU_STATE              = 0x0001,///< TPM perform restore saved state

        // Capability
        MAX_TPML_HANDLES          = 20,
        TPM_CAP_HANDLES           = 1,
        MAX_TPM_PROPERTIES        = 2,
        TPM_CAP_TPM_PROPERTIES    = 0x00000006, ///< Pull TPM Properties

        // TPM Handles
        TPM_HT_NV_INDEX           = 0x01000000,
        // TPM Properties
        TPM_PT_MANUFACTURER       = 0x00000105,
        TPM_PT_FIRMWARE_VERSION_1 = 0x0000010B,
        TPM_PT_FIRMWARE_VERSION_2 = 0x0000010C,


        // TPM Return Codes
        TPM_SUCCESS               = 0x000,
        TPM_RC_INITIALIZE         = 0x100,
        TPM_RC_HANDLE             = 0x18B,

        // TPM Authorization types
        TPM_RS_PW                 = 0x40000009,
        TPM_RH_PLATFORM           = 0x4000000C,

        // TPM Command Sizes
        TPM_CREATE_PRIMARY_SIZE   = 0x00000041,
        TPM_IN_SENSITIVE_SIZE     = 0x00000009,
        TPM_NV_READ_SIZE          = 0x00000023,
        TPM_QUOTE_SIZE            = 0x0000004B,
        TPM_FLUSH_CONTEXT_SIZE    = 0x0000000E,

        // Transient Objects handle
        TPM_HT_TRANSIENT          = 0x80000000,

    };


    // Command structures taken from Trusted Platform Module Library Part 3:
    //    Commands Family "2.0"

    /* TPM data structures naming conventions
    (taken from the TCG TPM spec v2)

    _TPM_   an indication/signal from the TPM’s system interface
    TPM_    a constant or an enumerated type
    TPM2_   a command defined by this specification
    TPM2B_  a structure that is a sized buffer where the size of the buffer is
            contained in a 16-bit, unsigned value. The first parameter is the
            size in octets of the second parameter. The second parameter may be
            any type.
    TPMA_   a structure where each of the fields defines an attribute and each
            field is usually a single bit. All the attributes in an attribute
            structure are packed with the overall size of the structure
            indicated in the heading of the attribute description
            (UINT8, UINT16, or UINT32).
    TPM_ALG_ an enumerated type that indicates an algorithm
    A TPM_ALG_ is often used as a selector for a union.
    TPMI_   an interface type. The value is specified for purposes of dynamic
            type checking when unmarshaled.
    TPML_   a list length followed by the indicated number of entries of the
            indicated type. This is an array with a length field.
    TPMS_   a structure that is not a size buffer or a tagged buffer or a
            list
    TPMT_   a structure with the first parameter being a structure tag,
            indicating the type of the structure that follows. A structure tag
            may be either a TPMT_ST_ or TPM_ALG_ depending on context.
    TPMU_   a union of structures, lists, or unions. If a union exists, there
            will normally be a companion TPMT_ that is the expression of the
            union in a tagged structure, where the tag is the selector
            indicating which member of the union is present.
    */


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
    const uint8_t* TPML_TAGGED_TPM_PROPERTY_unmarshal(
                                      TPML_TAGGED_TPM_PROPERTY* val,
                                      const uint8_t* i_tpmBuf,
                                      size_t* io_tpmBufSize);
    struct _TPML_HANDLE
    {
        uint32_t count;  ///< Number of handles
        uint32_t handles[MAX_TPML_HANDLES];
    } PACKED;
    typedef struct _TPML_HANDLE TPML_HANDLE;
    const uint8_t* TPML_HANDLE_unmarshal(TPML_HANDLE* val,
                                         const uint8_t* i_tpmBuf,
                                         size_t* io_tpmBufSize);

    union _TPMU_CAPABILITIES
    {
        TPML_HANDLE              tpmHandles;
        TPML_TAGGED_TPM_PROPERTY tpmProperties;
    } PACKED;
    typedef union _TPMU_CAPABILITIES TPMU_CAPABILITIES;

    struct _TPMS_CAPABILITY_DATA
    {
        uint32_t capability;    ///< The capability type
        TPMU_CAPABILITIES data; ///< The capability data
    } PACKED;
    typedef struct _TPMS_CAPABILITY_DATA TPMS_CAPABILITY_DATA;
    const uint8_t* TPMS_CAPABILITY_DATA_unmarshal(TPMS_CAPABILITY_DATA* val,
                                            const uint8_t* i_tpmBuf,
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
    size_t TCG_PCR_EVENT_marshalSize(const TCG_PCR_EVENT* val);
    const uint8_t* TCG_PCR_EVENT_logUnmarshal(TCG_PCR_EVENT* val,
                                              const uint8_t* i_tpmBuf,
                                              size_t i_bufSize, bool* o_err);
    uint8_t* TCG_PCR_EVENT_logMarshal(const TCG_PCR_EVENT* val,
                                      uint8_t* i_logBuf);

    /// Digest union
    union _TPMU_HA
    {
        uint8_t sha256[TPM_ALG_SHA256_SIZE];
    } PACKED;
    typedef union _TPMU_HA TPMU_HA;

    /// Crypto agile digest
    struct _TPMT_HA
    {
        uint16_t   algorithmId; ///< ID of hashing algorithm
        TPMU_HA    digest;      ///< Digest, depends on algorithmid
#ifdef __cplusplus
        bool operator==(const _TPMT_HA& i_rhs) const;
#endif
    } PACKED;
    typedef struct _TPMT_HA TPMT_HA;
    size_t TPMT_HA_marshalSize(const TPMT_HA* val);
    uint8_t* TPMT_HA_logMarshal(const TPMT_HA* val, uint8_t* i_logBuf);
    const uint8_t* TPMT_HA_logUnmarshal(TPMT_HA* val,
                                        const uint8_t* i_tpmBuf, bool* o_err);
    uint8_t* TPMT_HA_marshal(const TPMT_HA* val, uint8_t* o_tpmBuf,
                             size_t i_tpmBufSize, size_t * io_cmdSize);


    /// Crypto agile digests list
    struct _TPML_DIGEST_VALUES
    {
        uint32_t   count;                ///< Number of digests
        TPMT_HA    digests[HASH_COUNT];  ///< Digests
#ifdef __cplusplus
        bool operator==(const _TPML_DIGEST_VALUES& i_rhs) const;
#endif
    } PACKED;
    typedef struct _TPML_DIGEST_VALUES TPML_DIGEST_VALUES;
    size_t TPML_DIGEST_VALUES_marshalSize(const TPML_DIGEST_VALUES* val);
    uint8_t* TPML_DIGEST_VALUES_logMarshal(const TPML_DIGEST_VALUES* val,
                                           uint8_t* i_logBuf);
    const uint8_t* TPML_DIGEST_VALUES_logUnmarshal(TPML_DIGEST_VALUES* val,
                                                   const uint8_t* i_tpmBuf,
                                                   bool* o_err);
    uint8_t* TPML_DIGEST_VALUES_marshal(const TPML_DIGEST_VALUES* val,
                                        uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                                        size_t * io_cmdSize);

    /// Event field structure
    struct _TPM_EVENT_FIELD
    {
        uint32_t   eventSize;               ///< Size of event data
        uint8_t    event[MAX_TPM_LOG_MSG];  ///< The event data
#ifdef __cplusplus
        bool operator==(const _TPM_EVENT_FIELD& i_rhs) const;
#endif
    } PACKED;
    typedef struct _TPM_EVENT_FIELD TPM_EVENT_FIELD;
    size_t TPM_EVENT_FIELD_marshalSize(const TPM_EVENT_FIELD* val);
    uint8_t* TPM_EVENT_FIELD_logMarshal(const TPM_EVENT_FIELD* val,
                                        uint8_t* i_logBuf);
    const uint8_t* TPM_EVENT_FIELD_logUnmarshal(TPM_EVENT_FIELD* val,
                                                const uint8_t* i_tpmBuf,
                                                bool* o_err);

    /// Crypto agile log entry format
    struct _TCG_PCR_EVENT2
    {
        uint32_t   pcrIndex;    ///< PCRIndex event extended to
        uint32_t   eventType;   ///< Type of event
        TPML_DIGEST_VALUES digests; ///< List of digests extended to PCRIndex
        TPM_EVENT_FIELD event;      ///< Event information
#ifdef __cplusplus
        bool operator==(const _TCG_PCR_EVENT2& i_rhs) const;
#endif
    } PACKED;
    typedef struct _TCG_PCR_EVENT2 TCG_PCR_EVENT2;
    uint8_t* TCG_PCR_EVENT2_logMarshal(const TCG_PCR_EVENT2* val,
                                       uint8_t* i_logBuf);
    const uint8_t* TCG_PCR_EVENT2_logUnmarshal(TCG_PCR_EVENT2* val,
                                               const uint8_t* i_tpmBuf,
                                               size_t i_bufSize, bool* o_err);
    size_t TCG_PCR_EVENT2_marshalSize(const TCG_PCR_EVENT2* val);

    struct _TPM2_BaseIn
    {
        uint16_t      tag;         ///< Type TPM_ST_xx
        uint32_t      commandSize; ///< Total # output bytes incl cmdSize & tag
        uint32_t      commandCode; ///< Type TPM_CC_xx
    } PACKED;
    typedef struct _TPM2_BaseIn TPM2_BaseIn;
    uint8_t* TPM2_BaseIn_marshal(const TPM2_BaseIn* val, uint8_t* o_tpmBuf,
                                 size_t i_tpmBufSize, size_t* io_cmdSize);

    /// Base of all outgoing messages
    struct _TPM2_BaseOut
    {
        uint16_t      tag;          ///< Type TPM_ST_xx
        uint32_t      responseSize; ///< Total # out bytes incl paramSize & tag
        uint32_t      responseCode; ///< The return code of the operation
    } PACKED;
    typedef struct _TPM2_BaseOut TPM2_BaseOut;
    const uint8_t* TPM2_BaseOut_unmarshal(TPM2_BaseOut* val,
                                    const uint8_t* i_tpmBuf,
                                    size_t* io_tpmBufSize, size_t i_outBufSize);

    /// Generic TPM Input Command structure with a 2 byte param
    struct _TPM2_2ByteIn
    {
        TPM2_BaseIn  base;
        uint16_t     param;
    } PACKED;
    typedef struct _TPM2_2ByteIn TPM2_2ByteIn;
    uint8_t* TPM2_2ByteIn_marshal(const TPM2_2ByteIn* val, uint8_t* o_tpmBuf,
                                  size_t i_tpmBufSize, size_t* io_cmdSize);

    /// Generic TPM Input Command structure with a 4 byte param
    struct _TPM2_4ByteIn
    {
        TPM2_BaseIn  base;
        uint32_t     param;
    } PACKED;
    typedef struct _TPM2_4ByteIn TPM2_4ByteIn;
    uint8_t* TPM2_4ByteIn_marshal(const TPM2_4ByteIn* val, uint8_t* o_tpmBuf,
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
    uint8_t* TPM2_GetCapabilityIn_marshal(const TPM2_GetCapabilityIn* val,
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
    const uint8_t* TPM2_GetCapabilityOut_unmarshal(TPM2_GetCapabilityOut* val,
                                             const uint8_t* i_tpmBuf,
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
    uint8_t* TPM2_ExtendIn_marshalHandle(const TPM2_ExtendIn* val,
                                         uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                                         size_t* io_cmdSize);
    uint8_t* TPM2_ExtendIn_marshalParms(const TPM2_ExtendIn* val,
                                        uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                                        size_t* io_cmdSize);

    struct _TPMS_PCR_SELECTION
    {
        uint16_t   algorithmId; ///< ID of hashing algorithm
        uint8_t    sizeOfSelect; ///< Byte size of pcrSelect array
        uint8_t    pcrSelect[PCR_SELECT_MAX];
    } PACKED;
    typedef struct _TPMS_PCR_SELECTION TPMS_PCR_SELECTION;
    uint8_t* TPMS_PCR_SELECTION_marshal(const TPMS_PCR_SELECTION* val,
                                        uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                                        size_t* io_cmdSize);
    const uint8_t* TPMS_PCR_SELECTION_unmarshal(TPMS_PCR_SELECTION* val,
                                          const uint8_t* i_tpmBuf,
                                          size_t* io_tpmBufSize);


    struct _TPM2B_DIGEST
    {
        uint16_t size; // size in octets of the buffer field; may be 0
        uint8_t  buffer[sizeof(TPMU_HA)]; // the buffer area that can be no
                                          // larger than a digest
    } PACKED;
    typedef struct _TPM2B_DIGEST TPM2B_DIGEST;
    const uint8_t* TPM2B_DIGEST_unmarshal(TPM2B_DIGEST* val,
                                    const uint8_t* i_tpmBuf,
                                    size_t* io_tpmBufSize);

    struct _TPML_DIGEST
    {
        uint32_t  count;
        TPM2B_DIGEST digests[HASH_COUNT];
    } PACKED;
    typedef struct _TPML_DIGEST TPML_DIGEST;
    const uint8_t* TPML_DIGEST_unmarshal(TPML_DIGEST* val,
                                   const uint8_t* i_tpmBuf,
                                   size_t* io_tpmBufSize);

    struct _TPML_PCR_SELECTION
    {
        uint32_t     count; //number of selection structures;
                            // a value of zero is allowed.
        TPMS_PCR_SELECTION pcrSelections[HASH_COUNT]; // list of selections
    } PACKED;
    typedef struct _TPML_PCR_SELECTION TPML_PCR_SELECTION;
    uint8_t* TPML_PCR_SELECTION_marshal(const TPML_PCR_SELECTION* val,
                                        uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                                        size_t* io_cmdSize);
    const uint8_t* TPML_PCR_SELECTION_unmarshal(TPML_PCR_SELECTION* val,
                                          const uint8_t* i_tpmBuf,
                                          size_t* io_tpmBufSize);

    /// Incoming PCR_Read structure
    struct _TPM2_PcrReadIn
    {
        TPM2_BaseIn  base;
        TPML_PCR_SELECTION pcrSelectionIn;
    } PACKED;
    typedef struct _TPM2_PcrReadIn TPM2_PcrReadIn;
    uint8_t* TPM2_PcrReadIn_marshal(const TPM2_PcrReadIn* val,
                                    uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                                    size_t* io_cmdSize);

    /// Outgoing Pcr_Read structure
    struct _TPM2_PcrReadOut
    {
        TPM2_BaseOut base;
        uint32_t     pcrUpdateCounter;
        TPML_PCR_SELECTION pcrSelectionOut;
        TPML_DIGEST  pcrValues;
    } PACKED;
    typedef struct _TPM2_PcrReadOut TPM2_PcrReadOut;
    const uint8_t* TPM2_PcrReadOut_unmarshal(TPM2_PcrReadOut* val,
                                       const uint8_t* i_tpmBuf,
                                       size_t* io_tpmBufSize,
                                       size_t i_outBufSize);

    /// Incoming GetRandom structure
    struct _TPM2_GetRandomIn
    {
        TPM2_BaseIn  base;
        uint16_t bytesRequested;
    } PACKED;
    typedef struct _TPM2_GetRandomIn TPM2_GetRandomIn;

    /// Outgoing GetRandom structure
    struct _TPM2_GetRandomOut
    {
        TPM2_BaseOut  base;
        TPM2B_DIGEST  randomBytes;
    } PACKED;
    typedef struct _TPM2_GetRandomOut TPM2_GetRandomOut;

    /// TPM Authorization structure
    ///  This is not the full structure and only works for PW auth with NULL PW
    struct _TPMS_AUTH_COMMAND
    {
        uint32_t    sessionHandle;
        uint16_t    nonceSize;        ///< Size of nonce structure, currently 0
        uint8_t     sessionAttributes; ///< Session attributes
        uint16_t    hmacSize;         ///< Size of hmac structure, currently 0
    } PACKED;
    typedef struct _TPMS_AUTH_COMMAND TPMS_AUTH_COMMAND;
    uint8_t* TPMS_AUTH_COMMAND_marshal(const TPMS_AUTH_COMMAND* val,
                                       uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                                       size_t* io_cmdSize);

    struct _TPMS_SENSITIVE_CREATE
    {
        uint32_t userAuth;
        uint8_t data[43];
    } PACKED;
    typedef struct _TPMS_SENSITIVE_CREATE TPMS_SENSITIVE_CREATE;

    // Structure that contains the sensitive creation data
    struct _TPM2B_SENSITIVE_CREATE
    {
        uint32_t size;
        TPMS_SENSITIVE_CREATE sensitive;
    } PACKED;
    typedef struct _TPM2B_SENSITIVE_CREATE TPM2B_SENSITIVE_CREATE;

   // Incoming CreatePrimary structure
    struct _TPM2_CreatePrimaryIn
    {
        TPM2_BaseIn base;
        uint32_t    primaryHandle;
        TPM2B_SENSITIVE_CREATE inSensitive;
    } PACKED;
    typedef struct _TPM2_CreatePrimaryIn TPM2_CreatePrimaryIn;

    // Incoming NV Read structure
    struct _TPM2_NVReadIn
    {
        TPM2_BaseIn base;
        uint8_t data[25];
    } PACKED;
    typedef struct _TPM2_NVReadIn TPM2_NVReadIn;

    // Outgoing NV Read structure
    struct _TPM2_NVReadOut
    {
        TPM2_BaseOut base;
        uint32_t authSessionSize;
        TPM2B_MAX_NV_BUFFER data;
    } PACKED;
    typedef struct _TPM2_NVReadOut TPM2_NVReadOut;

    // Struct for the data portion of the Quote request
    struct _TPM2_QuoteData
    {
        uint8_t tpmiDhObject[19];
        TpmNonce_t nonce;
        uint16_t data;
        uint16_t inScheme;
        TPML_PCR_SELECTION pcrSelection;
    } PACKED;
    typedef struct _TPM2_QuoteData TPM2_QuoteData;

    // Incoming TPM Quote structure
    struct _TPM2_QuoteIn
    {
        TPM2_BaseIn base;
        TPM2_QuoteData quoteData;
    } PACKED;
    typedef struct _TPM2_QuoteIn TPM2_QuoteIn;

    // Outgoing Quote structure
    struct _TPM2_QuoteOut
    {
        TPM2_BaseOut base;
        uint32_t authSessionSize;
        uint8_t quoteData[MAX_TRANSMIT_SIZE];
    } PACKED;
    typedef struct _TPM2_QuoteOut TPM2_QuoteOut;

    // Incoming Context Flush structure
    struct _TPM2_FlushContextIn
    {
        TPM2_BaseIn base;
        uint32_t flushHandle;
    } PACKED;
    typedef struct _TPM2_FlushContextIn TPM2_FlushContextIn;

#ifdef __cplusplus
} // end TRUSTEDBOOT namespace
#endif

#endif

