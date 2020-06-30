/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/ROM.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <securerom/ecverify.H>
#include <string.h>
#include <array>
#include <vector>

/**
 *  @brief Indicates container header section versions
 */
enum CONTAINER_SECTION_VERSION : uint16_t
{
    CONTAINER_VERSION = 0x0001,
    HEADER_VERSION    = 0x0001,
};

/**
 *  @brief Indicates sizes of container header fields
 */
enum CONTAINER_FIELD_SIZE : size_t
{
    SW_HDR_COMP_ID_SIZE_BYTES = 8,
};

/**
 *  @brief Unique identifer for the hash algorithm to use
 */
enum ROM_HASH_ALGORITHM : uint8_t
{
    HASH_ALG_SHA512 = 0x01,
};

/**
 *  @brief Unique identifier for the signature algorithm to use
 */
enum ROM_SIGNATURE_ALGORITHM : uint8_t
{
    SIG_ALG_ECDSA521 = 0x01,
};

typedef struct
{
  uint16_t     version;     // (1: see versions above)
  uint8_t      hash_alg;    // (1: SHA-512)
  uint8_t      sig_alg;     // (1: SHA-512/ECDSA-521)
}__attribute__((packed)) ROM_version_raw;

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
  // followed by sw header (if not special prefix)
  // followed by optional unprotected payload data
}__attribute__((packed)) ROM_container_raw;

typedef struct
{
  ROM_version_raw ver_alg;
  uint64_t        code_start_offset;
  uint64_t        reserved;
  uint32_t        flags;
  uint8_t         sw_key_count;
  uint64_t        payload_size;
  SHA512_t        payload_hash;
  uint8_t         ecid_count;
  // optional ecid place holder ecid_count * ecid_size(128 bits)
  uint8_t         ecid[ECID_SIZE];
  // followed by prefix data (sig,keys) key raw
}__attribute__((packed)) ROM_prefix_header_raw;

#define PREFIX_HEADER_SIZE(_p) (sizeof(ROM_prefix_header_raw) \
            +((_p->ecid_count-1)*ECID_SIZE))

typedef struct
{
  ecc_signature_t  hw_sig_a;
  ecc_signature_t  hw_sig_b;
  ecc_signature_t  hw_sig_c;
  ecc_key_t        sw_pkey_p;
  ecc_key_t        sw_pkey_q;
  ecc_key_t        sw_pkey_r;
}__attribute__((packed)) ROM_prefix_data_raw;

typedef struct
{
  ROM_version_raw ver_alg;
  uint64_t        code_start_offset;
  char            component_id[SW_HDR_COMP_ID_SIZE_BYTES];
  uint32_t        flags;
  uint8_t         fw_secure_version;
  uint64_t        payload_size;
  SHA512_t        payload_hash;
  uint8_t         ecid_count;
  // optional ecid place holder ecid_count * ecid_size(128 bits)
  uint8_t         ecid[ECID_SIZE];
  // followed by sw sig raw
}__attribute__((packed)) ROM_sw_header_raw;

#define SW_HEADER_SIZE(_p) (sizeof(ROM_sw_header_raw) \
            +((_p->ecid_count-1)*ECID_SIZE))

typedef struct
{
  ecc_signature_t sw_sig_p;
  ecc_signature_t sw_sig_q;
  ecc_signature_t sw_sig_r;
  // followed by zero's padding to 4K
  // followed by protected sw payload_data
  // followed by unprotected sw payload_text
}__attribute__((packed)) ROM_sw_sig_raw;

typedef enum { ROM_DONE, ROM_FAILED } ROM_response;

typedef struct
{
  SHA512_t        hw_key_hash;
  uint8_t         my_ecid[ECID_SIZE];
  uint64_t        entry_point;
  uint64_t        log;
}__attribute__((packed)) ROM_hw_params;

extern void ROM_sreset (void);
extern "C" ROM_response ROM_verify (ROM_container_raw* container,
                                    ROM_hw_params* params);

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
    SECUREROM_INFO_ADDED = 0x0000000900000001
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
           (i_secureRomInfo->version >= SECUREROM_INFO_ADDED);
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
 * @return ROM_response ROM_DONE on sucess ROM_FAILURE otherwise
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

#ifdef __cplusplus
}
#endif

// Consts used for container header validation
const uint32_t ROM_MAGIC_NUMBER = 0x17082011;
const uint16_t ROM_VERSION = 1;
const uint8_t ROM_HASH_ALG = 1;
const uint8_t ROM_SIG_ALG = 1;
const uint8_t HW_KEY_COUNT = 3;
const uint8_t SW_KEY_COUNT_MIN = 1;
const uint8_t SW_KEY_COUNT_MAX = 3;
const size_t MAX_SECURE_HEADER_SIZE = 4096;

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

// SW Security Flags
enum SW_SB_FLAGS
{
    // placeholder
};

// Structure to store all hw and sw flag values in a container header
struct sb_flags_t
{
    sb_flags_t() :
        hw_hb_fw(false),
        hw_opal(false),
        hw_phyp(false),
        hw_lab_override(false),
        hw_key_transition(false)
    {
    }

    bool hw_hb_fw;          ///< Signed using HB keys
    bool hw_opal;           ///< Signed using OPAL keys
    bool hw_phyp;           ///< Signed using PHyp keys
    bool hw_lab_override;   ///< Whether to enable lab security override;
                            ///< Only applicable for SBE partition
    bool hw_key_transition; ///< Indicates this is a key transition container
};

/**
 *  @brief Type used to specify Secure Boot function types
 */
typedef uint32_t sbFuncType_t;
/**
 *  @brief Secure Boot function types
 */
enum SB_FUNC_TYPES : sbFuncType_t
{
    SHA512 = 0x0000,
    ECDSA521 = 0x0001,
    MAX_TYPES,
    SB_FUNC_TYPES_INVALID = 0xFFFF
};

/**
 *  @brief Type used to specify Secure Boot function type versions
 */
typedef uint32_t sbFuncVer_t;
/**
 *  @brief Secure Boot function type versions
 */
enum SB_FUNC_VERS : sbFuncVer_t
{
    // All external function definitions extern'd in ROM.H and implemented in
    // rom_entry.S

    // SHA512 Hash function definition(s) per version
    SHA512_INIT = 0x0001, // void call_rom_SHA512(void*, const sha2_byte *, size_t, SHA512_t*);

    // ECDSA521 function definition(s) per version
    ECDSA521_INIT = 0x0001, // ROM_response call_rom_verify(void*, const ROM_container_raw*, ROM_hw_params*);
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
