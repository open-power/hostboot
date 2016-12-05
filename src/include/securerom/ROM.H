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
/****************************************************************************
 *
 ****************************************************************************/
#ifndef ROM_H
#define ROM_H

/****************************************************************************/
#ifndef PHYPLIBFUNCTIONS
#include <hw_utils.h>
#endif
#include <sha512.h>
#include <ecverify.h>

/****************************************************************************/
#define CONTAINER_VERSION   1
#define HEADER_VERSION      1
#define HASH_ALG_SHA512     1
#define SIG_ALG_ECDSA521    1

#define HBI_BASE_SIGNING_KEY 0x80000000

#define ROM_MAGIC_NUMBER     0x17082011

typedef struct {
  uint16_t     version;     // (1: see versions above)
  uint8_t      hash_alg;    // (1: SHA-512)
  uint8_t      sig_alg;     // (1: SHA-512/ECDSA-521)
}__attribute__((packed)) ROM_version_raw;

typedef struct {
  uint32_t        magic_number;    // (17082011)
  uint16_t        version;         // (1: see versions above)
  uint64_t        container_size;  // filled by caller
  uint64_t        target_hrmor;    // filled by caller
  uint64_t        stack_pointer;   // filled by caller  //bottom of stack -> 128k added by rom code to get real stack pointer
  ecc_key_t       hw_pkey_a;
  ecc_key_t       hw_pkey_b;
  ecc_key_t       hw_pkey_c;
  uint64_t        prefix; // prefix header place holder
  // followed by sw header (if not special prefix)
  // followed by optional unprotected payload data
}__attribute__((packed)) ROM_container_raw;

typedef struct {
  ROM_version_raw ver_alg;
  uint64_t        code_start_offset;
  uint64_t        reserved;
  uint32_t        flags;
  uint8_t         sw_key_count;
  uint64_t        payload_size;
  sha2_hash_t     payload_hash;
  uint8_t         ecid_count;
  uint8_t         ecid[ECID_SIZE]; // optional ecid place holder ecid_count * ecid_size(128 bits)
  // followed by prefix data (sig,keys) key raw
}__attribute__((packed)) ROM_prefix_header_raw;

#define PREFIX_HEADER_SIZE(_p) (sizeof(ROM_prefix_header_raw)+((_p->ecid_count-1)*ECID_SIZE))

typedef struct {
  ecc_signature_t  hw_sig_a;
  ecc_signature_t  hw_sig_b;
  ecc_signature_t  hw_sig_c;
  ecc_key_t        sw_pkey_p;
  ecc_key_t        sw_pkey_q;
  ecc_key_t        sw_pkey_r;
}__attribute__((packed)) ROM_prefix_data_raw;

typedef struct {
  ROM_version_raw ver_alg;
  uint64_t        code_start_offset;
  uint64_t        reserved;
  uint32_t        flags;
  uint8_t         reserved_0;
  uint64_t        payload_size;
  sha2_hash_t     payload_hash;
  uint8_t         ecid_count;
  uint8_t         ecid[ECID_SIZE]; // optional ecid place holder ecid_count * ecid_size(128 bits)
  // followed by sw sig raw
}__attribute__((packed)) ROM_sw_header_raw;

#define SW_HEADER_SIZE(_p) (sizeof(ROM_sw_header_raw)+((_p->ecid_count-1)*ECID_SIZE))

typedef struct {
  ecc_signature_t sw_sig_p;
  ecc_signature_t sw_sig_q;
  ecc_signature_t sw_sig_r;
  // followed by zero's padding to 4K
  // followed by protected sw payload_data
  // followed by unprotected sw payload_text
}__attribute__((packed)) ROM_sw_sig_raw;

/****************************************************************************/
typedef enum { ROM_DONE, ROM_FAILED, PHYP_PARTIAL } ROM_response;

#ifndef PHYPLIBFUNCTIONS
typedef struct {
  sha2_hash_t         hw_key_hash;
  uint8_t             my_ecid[ECID_SIZE];
  uint64_t            entry_point;
  uint64_t 	      log;
}__attribute__((packed)) ROM_hw_params;

//extern void ROM_instruction_start (void);
extern void ROM_sreset (void);
extern ROM_response ROM_verify (ROM_container_raw* container,
                                ROM_hw_params*     params);
#endif

#endif
