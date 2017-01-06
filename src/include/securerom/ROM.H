/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/ROM.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#define CONTAINER_VERSION   1
#define HEADER_VERSION      1
#define HASH_ALG_SHA512     1
#define SIG_ALG_ECDSA521    1

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
  sha2_hash_t     payload_hash;
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
  uint64_t        reserved;
  uint32_t        flags;
  uint8_t         reserved_0;
  uint64_t        payload_size;
  sha2_hash_t     payload_hash;
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
  sha2_hash_t         hw_key_hash;
  uint8_t             my_ecid[ECID_SIZE];
  uint64_t            entry_point;
  uint64_t 	      log;
}__attribute__((packed)) ROM_hw_params;

extern void ROM_sreset (void);
extern "C" ROM_response ROM_verify (ROM_container_raw* container,
                                    ROM_hw_params* params);

/************************* END OF ORIGINAL ROM CODE ***************************/

/* Offsets needed to call functions in jump table at start of ROM code.
   See img/securerom.list.bz2 and search for SHA512_Hash and ROM_verify
   E.g.
    0000000000000018 <_SHA512_Hash>:
    0000000000000028 <_ROM_verify>:
*/
#define SHA512_HASH_FUNCTION_OFFSET 0x18
#define ROM_VERIFY_FUNCTION_OFFSET 0x28

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
 * @param[in] ROM_hw_params*     HW params to pass in. Includes HW keys' hash
 *
 * @return ROM_response ROM_DONE on sucess ROM_FAILURE otherwise
 */
ROM_response call_rom_verify(void*, ROM_container_raw*, ROM_hw_params*);

/**
 * @brief Call rom SHA512 code
 *
 * @param[in] void*            Address of function offset into Secure ROM
 * @param[in] sha2_byte*       Pointer to effective address of blob to hash
 * @param[in] size_t           Size of blob to hash
 * @param[in/out] sha2_hash_t* Pointer to resulting hash value
 *
 * @return N/A
 */
void call_rom_SHA512(void*, const sha2_byte *, size_t, sha2_hash_t*);

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
    sb_flags_t() : hw_hb_fw(false), hw_opal(false), hw_phyp(false),
                   hw_key_transition(false) {}
    bool hw_hb_fw;
    bool hw_opal;
    bool hw_phyp;
    bool hw_key_transition;
};


#endif
