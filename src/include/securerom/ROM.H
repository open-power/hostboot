/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/ROM.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2026                        */
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

#ifndef ROM_H
#define ROM_H

#include <securerom/hw_utils.H>
#include <securerom/sha512.H>
#include <securerom/sha3.H>
#include <securerom/ecverify.H>
#include <securerom/mlca.H>
#include <string.h>
#include <array>
#include <vector>


/// V3 Secure Header Signature verify
/// ML-DSA public key size (bytes)
#define MLDSA_PUBLIC_KEY_SIZE     2592

/// ML-DSA signature size (bytes)
#define MLDSA_SIG_SIZE            4627

typedef uint8_t mldsa_pub_key_t[MLDSA_PUBLIC_KEY_SIZE];
typedef uint8_t mldsa_signature_t[MLDSA_SIG_SIZE];

/**
 *  @brief Indicates container header section versions
 */
enum CONTAINER_SECTION_VERSION : uint16_t
{
    CONTAINER_VERSION = 0x0001, // V1
    HEADER_VERSION    = 0x0001, // V1
    V3_CONTAINER_VERSION = 0x0003,
    V3_HEADER_VERSION    = 0x0003
};

/**
 *  @brief Indicates sizes of container header fields
 */
enum CONTAINER_FIELD_SIZE : size_t
{
    FW_HDR_COMP_ID_SIZE_BYTES = 8,
};

/**
 *  @brief Unique identifer for the hash algorithm to use
 */
enum ROM_HASH_ALGORITHM : uint8_t
{
    HASH_ALG_SHA512 = 0x01,   // V1
    HASH_ALG_SHA3_512 = 0x02, // V3
};

/**
 *  @brief Unique identifier for the signature algorithm to use
 */
enum ROM_SIGNATURE_ALGORITHM : uint8_t
{
    SIG_ALG_ECDSA521            = 0x01, // V1
    SIG_ALG_ECDSA521_DILITHIUM  = 0x02, // V2 - not supported
    SIG_ALG_ECDSA521_MLDSA      = 0x03, // V3
};

typedef struct
{
  uint16_t     version;     // (1: see versions above)
  uint8_t      hash_alg;    // (1: SHA-512,
                            //  2: SHA3-512)
  uint8_t      sig_alg;     // (1: SHA-512/ECDSA-521,
                            //  2: SHA3-512,ECDSA 521/Dilithium,
                            //  3: SHA3-512,ECDSA 521/ML-DSA)
}__attribute__((packed)) ROM_version_raw;

/**
 * @brief Secure Header V1 Hardware Header format
 */
typedef struct
{
  uint32_t        magic_number;    // (17082011)
  uint16_t        version;         // (1: see versions above)
  uint64_t        container_size;  // filled by caller
  uint64_t        target_hrmor;    // filled by caller
  //bottom of stack -> 128k added by rom code to get real stack pointer
  uint64_t        stack_pointer;   // filled by caller
  ecc_key_t       hw_pkey_a;
  ecc_key_t       hw_pkey_b;
  ecc_key_t       hw_pkey_c;
  uint64_t        prefix; // prefix header place holder
  // followed by fw header (if not special prefix)
  // followed by optional unprotected payload data
}__attribute__((packed)) ROM_container_raw;

/**
 * @brief Secure Header V3 Hardware Header format
 *
 */
typedef struct
{
  uint32_t        magic_number;    // (17082011)
  uint16_t        version;         // (3: see versions above)
  uint64_t        container_size;  // filled by caller
  uint8_t         reserved[6];
  ecc_key_t       hw_pkey_a;
  mldsa_pub_key_t hw_pkey_d;
  uint64_t        prefix; // prefix header place holder
  // followed by fw header (if not special prefix)
  // followed by optional unprotected payload data
}__attribute__((packed)) ROM_v3_container_raw;


/**
 * @brief Common Secure Header Fields for first 3 fields
 *        of the V1 and V3 Security headers
 */
typedef struct
{
  uint32_t        magic_number;    // (17082011)
  uint16_t        version;         // (1 or 3: see versions above)
  uint64_t        container_size;  // filled by caller
}__attribute__((packed)) ROM_common_container_fields;

// static asserts to ensure that ROM_common_container_fields
// is insync with both ROM_container_raw (V1) and
// ROM_v3_container_raw
static_assert(offsetof(ROM_container_raw, magic_number) ==
              offsetof(ROM_common_container_fields, magic_number),
              "ROM_container_raw and ROM_common_container_fields "
              "have different magic_number offsets");

static_assert(offsetof(ROM_v3_container_raw, magic_number) ==
              offsetof(ROM_common_container_fields, magic_number),
              "ROM_v3_container_raw and ROM_common_container_fields "
              "have different magic_number offsets");

static_assert(offsetof(ROM_container_raw, version) ==
              offsetof(ROM_common_container_fields, version),
              "ROM_container_raw and ROM_common_container_fields "
              "have different version offsets");

static_assert(offsetof(ROM_v3_container_raw, version) ==
              offsetof(ROM_common_container_fields, version),
              "ROM_v3_container_raw and ROM_common_container_fields "
              "have different version offsets");

static_assert(offsetof(ROM_container_raw, container_size) ==
              offsetof(ROM_common_container_fields, container_size),
              "ROM_container_raw and ROM_common_container_fields "
              "have different container_size offsets");

static_assert(offsetof(ROM_v3_container_raw, container_size) ==
              offsetof(ROM_common_container_fields, container_size),
              "ROM_v3_container_raw and ROM_common_container_fields "
              "have different container_size offsets");


/**
 * @brief Secure header V1 Prefix Header Format
 *
 */
typedef struct
{
  ROM_version_raw ver_alg;
  uint64_t        code_start_offset;
  uint64_t        reserved;
  uint32_t        flags;
  uint8_t         fw_key_count;
  uint64_t        payload_size;
  SHA512_t        payload_hash;
  uint8_t         ecid_count;
  // optional ecid place holder ecid_count * ecid_size(128 bits)
  uint8_t         ecid[ECID_SIZE];
  // followed by prefix data (sig,keys) key raw
}__attribute__((packed)) ROM_prefix_header_raw;

#define PREFIX_HEADER_SIZE(_p) (sizeof(ROM_prefix_header_raw) \
            +((_p->ecid_count-1)*ECID_SIZE))



/**
 * @brief Secure header V3 Prefix Header Format
 *
 */
typedef struct
{
  ROM_version_raw ver_alg;
  uint64_t        reserved;
  uint32_t        flags;
  uint8_t         fw_key_count;
  uint64_t        payload_size;
  sha3_t          payload_hash;
  uint8_t         ecid[ECID_SIZE];
  uint8_t         reserved1[3];
  // followed by prefix data (sig,keys) key raw
}__attribute__((packed)) ROM_v3_prefix_header_raw;

#define V3_PREFIX_HEADER_SIZE(_p) (sizeof(ROM_v3_prefix_header_raw))


/**
 * @brief Secure header V1 Prefix Header HW Signatures and SW/FW PUB Keys
 *
 */
typedef struct
{
  ecc_signature_t  hw_sig_a;
  ecc_signature_t  hw_sig_b;
  ecc_signature_t  hw_sig_c;
  ecc_key_t        fw_pkey_p;
  ecc_key_t        fw_pkey_q;
  ecc_key_t        fw_pkey_r;
}__attribute__((packed)) ROM_prefix_data_raw;


/**
 * @brief Secure Header V3 Prefix Header HW Signatures and SW/FW PUB Keys
 *
 */
typedef struct
{
  ecc_signature_t                       hw_sig_a;
  mldsa_signature_t                     hw_sig_d;
  ecc_key_t                             fw_pkey_p;
  mldsa_pub_key_t                       fw_pkey_s;
}__attribute__((packed)) ROM_v3_prefix_data_raw;


typedef struct
{
  ROM_version_raw ver_alg;
  uint64_t        code_start_offset;
  char            component_id[FW_HDR_COMP_ID_SIZE_BYTES];
  uint32_t        flags;
  uint8_t         fw_secure_version;
  uint64_t        payload_size;
  SHA512_t        payload_hash;
  uint8_t         ecid_count;
  // optional ecid place holder ecid_count * ecid_size(128 bits)
  uint8_t         ecid[ECID_SIZE];
  // followed by fw sig raw
}__attribute__((packed)) ROM_fw_header_raw;

#define FW_HEADER_SIZE(_p) (sizeof(ROM_fw_header_raw) \
            +((_p->ecid_count-1)*ECID_SIZE))


/**
 * @brief  Secure header V3 SW/FW Header format
 *
 */
typedef struct
{
  ROM_version_raw ver_alg;
  uint64_t        reserved;
  char            component_id[FW_HDR_COMP_ID_SIZE_BYTES];
  uint32_t        flags;
  uint8_t         fw_secure_version;
  uint64_t        payload_size_protected;
  uint64_t        payload_size_unprotected;
  sha3_t          payload_hash_protected;
  uint8_t         ecid[ECID_SIZE];
  uint8_t         reserved1[7];
  // followed by fw sig raw
}__attribute__((packed)) ROM_v3_fw_header_raw;

#define V3_FW_HEADER_SIZE(_p) (sizeof(ROM_v3_fw_header_raw))


/**
 * @brief Secure Header V1 SW/FW Header Signatures
 *
 */
typedef struct
{
  ecc_signature_t fw_sig_p;
  ecc_signature_t fw_sig_q;
  ecc_signature_t fw_sig_r;
  // followed by zero's padding to 4K
  // followed by protected fw payload_data
  // followed by unprotected fw payload_text
}__attribute__((packed)) ROM_fw_sig_raw;

/**
 * @brief Secure Header V3 SW/FW Header Signatures
 *
 */
typedef struct
{
  ecc_signature_t                   fw_sig_p;
  mldsa_signature_t                 fw_sig_s;
  // followed by zero's padding to 10K
  // followed by protected fw payload_data
  // followed by unprotected fw payload_text
}__attribute__((packed)) ROM_v3_fw_sig_raw;

// @V3_FW_SIGNATURES_OFFSET@ static_assert added here to make sure that the
// fw signatures offset from the start of the V3 header is the value of 10463,
// which is used in genPnorImages.pl
static_assert(10463 == offsetof(ROM_v3_container_raw, prefix)
                       + sizeof(ROM_v3_prefix_header_raw)
                       + sizeof(ROM_v3_prefix_data_raw)
                       + sizeof(ROM_v3_fw_header_raw),
              "FW Signatures offset does not equal 10463");

// Similar static_assert as above for this size used in genPnorImages.pl:
static_assert(4759 == sizeof(ecc_signature_t) // fw_sig_p (132 bytes)
                      + sizeof(mldsa_signature_t)); // fw_sig_s (4627 bytes)

typedef enum { ROM_DONE, ROM_FAILED } ROM_response;

typedef struct
{
  SHA512_t        hw_key_hash;
  uint8_t         my_ecid[ECID_SIZE];
  uint64_t        entry_point;
  uint64_t        log;              // MSV (minimum secure version)
  uint8_t         sbMode;           // Secure Boot Mode
}__attribute__((packed)) ROM_hw_params;

extern void ROM_sreset (void);
extern "C" ROM_response ROM_verify (ROM_container_raw* container,
                                    ROM_hw_params* params);

/**
 * @brief Call rom V3 verify code against system hash keys
 *
 * @param[in] ROM_v3_container_raw* Pointer to effective address of container
 * @param[in/out] ROM_hw_params*  HW params to pass in (including HW keys' hash)
 *                               Additionally, the secure version used to check
 *                               against the container's fw secure version is
 *                               passed in via the HW params log; and then the
 *                               error information is written to
 *                               the HW params log.
 * @param[in] void* i_data          Pointer to effective address of data;
 *                                  default is nullptr.
 *                                  If nullptr is entered then the data is
 *                                  expected to start V3_SECURE_HEADER_SIZE past
 *                                  the effective address of ROM_v3_container_raw
 *
 * @return ROM_response ROM_DONE on success ROM_FAILURE otherwise
 */
extern "C" ROM_response ROM_v3_verify (ROM_v3_container_raw* container,
                                       ROM_hw_params* params,
                                       void* i_data = nullptr);


/************************* END OF ORIGINAL ROM CODE ***************************/

/* Offsets relative to branchtable start to call functions in SecureROM code.
   See img/securerom.list.bz2 and search for SHA512_Hash and ROM_verify, then
        subtract the branch table offset
   E.g.
    0000000000000040 <_SHA512_Hash>:
    0000000000000050 <_ROM_verify>:

    Search for branchtableoffset
    0000000000000010 <branchtableoffset>:
      10    00000010:   00 00 00 00     .long 0x0
      14    00000014:   00 00 00 28     .long 0x28

    Subtraction (0x28) results in relative offset from branch table start
    0000000000000018 <_SHA512_Hash>:
    0000000000000028 <_ROM_verify>:


   Note: If the SecureRomInfo change size, these will be affected.
         See src/securerom/secureromasm.S for more info.
*/
#define SHA512_HASH_FUNCTION_OFFSET 0x18
#define ROM_VERIFY_FUNCTION_OFFSET 0x28
#define SHA3_HASH_FUNCTION_OFFSET 0x30
#define ROM_V3_VERIFY_FUNCTION_OFFSET 0x38


// Version info at SECUREROM_VERSION_STRUCTURE_OFFSET
// - [8 bytes] - eyeCatch
// - [8 bytes] - version
// - [8 bytes] - branchtable offset
// - [16 bytes] - reserved
struct SecureRomInfo
{
    uint64_t eyeCatch;
    uint64_t version;
    uint64_t branchtableOffset;
    std::array<uint64_t,2> reserved;
}__attribute__((packed));

// Expected securerom eye catch
const uint64_t SECROM_EYECATCHER = 0x23534543524F4D00; // #SECROM\0

// Used for version checking as the SecureRomInfo structure changes
enum SecureRomInfoVersion
{
    // [release:4][version:4]
    SECUREROM_INFO_ADDED  = 0x0000000900000001, // original value
    // moving release to 0xB for P11 V3 support
    SECUREROM_INFO_VER3   = 0x0000000B00000001, // v3 algorithms NOT available in securerom
    SECUREROM_INFO_VER3_2 = 0x0000000B00000002  // v3 algorithms available in securerom
};

/**
 * @brief Checks if secureROM is valid by checking the eyeCatch and version
 *
 * @param[in] SecureRomInfo*    Pointer to SecureRomInfo - Must not be NULL
 *
 * @return bool true if valid; false otherwise
 */
inline bool secureRomInfoValid (const SecureRomInfo * i_secureRomInfo)
{
    // Ensure EyeCatch and Version are valid
    return (i_secureRomInfo->eyeCatch == SECROM_EYECATCHER) &&
           (i_secureRomInfo->version >= SECUREROM_INFO_VER3);
}

// Need this for the following definition
#ifdef __cplusplus
extern "C"
{
#endif

// Interfaces for Assembly Functions to call into Secure ROM
// - 1st parameter is address of function offset into Secure ROM,
//   followed by additional parameters as necssary

/**
 * @brief Call rom verify code against system hash keys
 *
 * @param[in] void*              Address of function offset into Secure ROM
 * @param[in] ROM_container_raw* Pointer to effective address of container
 * @param[in/out] ROM_hw_params* HW params to pass in (including HW keys' hash)
 *                               Additionally, the secure version used to check
 *                               against the container's fw secure version is
 *                               passed in via the HW params log; and then the
 *                               error information is written to
 *                               the HW params log.
 *
 * @return ROM_response ROM_DONE on success ROM_FAILURE otherwise
 */
ROM_response call_rom_verify(void*, const ROM_container_raw*, ROM_hw_params*);

/**
 * @brief Call rom SHA512 code
 *
 * @param[in] void*            Address of function offset into Secure ROM
 * @param[in] sha2_byte*       Pointer to effective address of blob to hash
 * @param[in] size_t           Size of blob to hash
 * @param[in/out] SHA512_t*    Pointer to resulting hash value
 *
 * @return N/A
 */
void call_rom_SHA512(void*, const sha2_byte *, size_t, SHA512_t*);


/**
 * @brief Call rom V3 verify code against system hash keys
 *
 * @param[in] void*                 Address of function offset into Secure ROM
 * @param[in] ROM_v3_container_raw* Pointer to effective address of container
 * @param[in/out] ROM_hw_params*  HW params to pass in (including HW keys' hash)
 *                               Additionally, the secure version used to check
 *                               against the container's fw secure version is
 *                               passed in via the HW params log; and then the
 *                               error information is written to
 *                               the HW params log.
 * @param[in] void*                 Pointer to effective address of data;
 *                                  If nullptr is entered then the data is
 *                                  expected to start V3_SECURE_HEADER_SIZE past
 *                                  the effective address of ROM_v3_container_raw
 *
 * @return ROM_response ROM_DONE on success ROM_FAILURE otherwise
 */
ROM_response call_rom_v3_verify(void*,
                                const ROM_v3_container_raw*,
                                ROM_hw_params*,
                                void*);

/**
 * @brief Call rom SHA3 code
 *
 * @param[in] void*            Address of function offset into Secure ROM
 * @param[in] sha2_byte*       Pointer to effective address of blob to hash
 * @param[in] size_t           Size of blob to hash
 * @param[in/out] SHA512_t*    Pointer to resulting hash value
 *
 * @return N/A
 */
void call_rom_SHA3(void*, const void *, size_t, sha3_t*);


#ifdef __cplusplus
}
#endif

/**
 * Secure Header V1 macro
 *
 */
// Consts used for container header validation
constexpr uint32_t ROM_MAGIC_NUMBER = 0x17082011;
constexpr uint16_t ROM_VERSION = 1;
constexpr uint8_t ROM_HASH_ALG = 1;
constexpr uint8_t ROM_SIG_ALG = 1;
constexpr uint8_t HW_KEY_COUNT = 3;
constexpr uint8_t FW_KEY_COUNT_MIN = 1;
constexpr uint8_t FW_KEY_COUNT_MAX = 3;
constexpr size_t MAX_SECURE_HEADER_SIZE = 4096;
constexpr size_t V1_MAX_SECURE_HEADER_SIZE = MAX_SECURE_HEADER_SIZE;
constexpr size_t V1_SECURE_HEADER_SIZE = 1288; // Truncated V1 Size
// There is a lot of code that assumes that the V1 container header size
// is PAGESIZE so do a static_assert here to keep things insync
static_assert(V1_MAX_SECURE_HEADER_SIZE == PAGESIZE,
              "V1_MAX_SECURE_HEADER_SIZE != PAGESIZE");

/**
 * Secure Header V3 macro
 *
 */
constexpr uint16_t ROM_V3_VERSION = 3;
constexpr uint8_t  ROM_V3_HASH_ALG = 2;
constexpr uint8_t  ROM_V3_SIG_ALG = 3;
constexpr uint8_t  V3_HW_KEY_COUNT = 2;
constexpr uint8_t  V3_FW_KEY_COUNT = 2;
constexpr size_t   V3_SECURE_HEADER_SIZE = 15360;
// Sum of Secure header size V1 + V3, using truncated V1 Size
constexpr size_t COMBINED_V1_V3_SECURE_HEADER_SIZE =
               (V1_SECURE_HEADER_SIZE + V3_SECURE_HEADER_SIZE);


// Security Flags

// HW Security Flags
enum HW_SB_FLAGS
{
    HB_FW_FLAG = 0x80000000,
    OPAL_FLAG = 0x40000000,
    PHYP_FLAG = 0x20000000,
    LAB_OVERRIDE_FLAG = 0x00080000,
    KEY_TRANSITION_FLAG = 0x00000001
};

// FW Security Flags
enum FW_SB_FLAGS
{
    HASH_PAGE_TABLE_FLAG = 0x80000000
};

// Structure to store all hw and fw flag values in a container header
struct sb_flags_t
{
    sb_flags_t() :
        hw_hb_fw(false),
        hw_opal(false),
        hw_phyp(false),
        hw_lab_override(false),
        hw_key_transition(false),
        fw_hash(false)
    {
    }

    bool hw_hb_fw;          ///< Signed using HB keys
    bool hw_opal;           ///< Signed using OPAL keys
    bool hw_phyp;           ///< Signed using PHyp keys
    bool hw_lab_override;   ///< Whether to enable lab security override;
                            ///< Only applicable for SBE partition
    bool hw_key_transition; ///< Indicates this is a key transition container
    bool fw_hash;           ///< Indicates presence of hash page table
};

/**
 *  @brief Type used to specify Secure Boot function types
 */
typedef uint32_t sbFuncType_t;
/**
 *  @brief Secure Boot function types
 *         These values are defined in the Hypervisor Interface Data
 *         Specifications (aka HDAT spec)
 *         v11.00 added the values for SHA3 and MLDSA
 */
enum SB_FUNC_TYPES : sbFuncType_t
{
    SHA512 = 0x0000,    // SHA512 hash function
    ECDSA521 = 0x0001,  // ECDSA 521 verification function
    SHA3 = 0x0002,      // SHA3 hash function
    MLDSA = 0x0003,     // Quantum safe v3 verification function
    MAX_TYPES,
    SB_FUNC_TYPES_INVALID = 0xFFFF
};

/**
 *  @brief Type used to specify Secure Boot function type versions
 */
typedef uint32_t sbFuncVer_t;
/**
 *  @brief Secure Boot function type versions as defined in the
 *         Hypervisor Interface Data Specifications (aka HDAT spec)
 *         Currently all versions are set to 1.  They will only be incremented
 *         if there is a need to track an update to one of the functions.
 */
enum SB_FUNC_VERS : sbFuncVer_t
{
    // All external function definitions extern'd in ROM.H and implemented in
    // rom_entry.S

    // SHA512 Hash function definition(s) per version
    SHA512_INIT = 0x0001, // void call_rom_SHA512(void*, const sha2_byte *, size_t, SHA512_t*);

    // ECDSA521 function definition(s) per version
    ECDSA521_INIT = 0x0001, // ROM_response call_rom_verify(void*, const ROM_container_raw*, ROM_hw_params*);

    // SHA3 Hash function definition(s) per version
    SHA3_INIT = 0x0001, // void call_rom_SHA3(void*, const void *, size_t, SHA3_t*);

    // MLDSA function definition(s) per version
    MLDSA_INIT = 0x0001, // ROM_response call_rom_v3_verify(void*, const ROM_container_raw*, ROM_hw_params*);
};

/**
 * @brief Array of current secure rom function types used
 */
extern const std::array<sbFuncType_t, SB_FUNC_TYPES::MAX_TYPES> SecRomFuncTypes;

/**
 * @brief Vector of IDds (PNOR or Lid Id(s)) associated with the blob that is
 *        being verified.
 */
typedef std::vector<uint32_t> RomVerifyIds;

#endif
