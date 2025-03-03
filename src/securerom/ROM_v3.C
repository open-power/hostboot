/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/ROM_v3.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2025                        */
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

#include <securerom/ROM.H>

#include <securerom/ecverify.H>
#include <securerom/status_codes.H>
#include <string.h>
#include <algorithm>

#define v3_valid_magic_number(header) \
    (GET32((header)->magic_number) == ROM_MAGIC_NUMBER)
#define v3_valid_container_version(header) \
    (GET16((header)->version) == V3_CONTAINER_VERSION)

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#endif

static bool pred_notZero(uint8_t x)
{
    return x != 0;
}

static int v3_valid_ver_alg(ROM_version_raw* ver_alg, uint8_t sig_alg)
{
    if (GET16(ver_alg->version) != V3_HEADER_VERSION)
    {
        return 0;
    }
    if (ver_alg->hash_alg != HASH_ALG_SHA3_512)
    {
        return 0;
    }
    if (!sig_alg)
    {
        return 1;
    }
    if (ver_alg->sig_alg != sig_alg)
    {
        return 0;
    }
    return 1;
}

static inline ROM_v3_container_raw* cast_container(uint64_t addr)
{
    return (ROM_v3_container_raw*) Convert_Mem_Addr(physical_addr(addr));
}

static inline void ROM_v3_init_cache_area(uint64_t target, uint64_t size)
{
    uint64_t i;
    for (i=0;i<size;i+=CACHE_LINE)
    {
        assem_DCBZ(target);
        target+=CACHE_LINE;
    }
}

#ifdef EMULATE_HW
    #define FAILED(_c,_m) { params->log=ERROR_EVENT|CONTEXT|(_c); \
        printf ("FAILED '%s'\n", (_m)); return ROM_FAILED; }
#else
    #define FAILED(_c,_m) { params->log=ERROR_EVENT|CONTEXT|(_c); \
        return ROM_FAILED; }
#endif


#undef  CONTEXT
#define CONTEXT  ROM_V3_VERIFY
// NOTE: ROM_verify is called with with hrmor relative addresses from Hostboot
// @TODO JIRA PFHB-921 reinstate the asm() call so that the securerom
// branch table can properly find this function
//asm(".globl .L.ROM_v3_verify");
ROM_response ROM_v3_verify( ROM_v3_container_raw* container,
                            ROM_hw_params* params,
                            void* i_data )
{
    sha3_t digest;
    ROM_v3_prefix_header_raw* prefix;
    ROM_v3_prefix_data_raw* hw_data;
    ROM_v3_fw_header_raw* header;
    ROM_v3_fw_sig_raw* fw_sig;
    uint64_t size;

    // params->log is used to pass in a FW Secure Version to
    // compare against the container's fw header's fw_secure_version field
    uint8_t i_fw_secure_version = static_cast<uint8_t>(params->log);

    params->log=CONTEXT|BEGIN;

    // test for valid container magic number, version, hash & signature
    // algorithms (sanity check)
    if(!v3_valid_magic_number(container))
      FAILED(MAGIC_NUMBER_TEST,"bad container magic number");

    if(!v3_valid_container_version(container))
      FAILED(CONTAINER_VERSION_TEST,"bad container version");

    // process hw keys
    // test for valid hw keys - do a sha3 hash over both HW keys
    // and then compare it to what was passed in
    size = sizeof(ecc_key_t)           // hw_pkey_a
            + sizeof(mldsa_pub_key_t); // hw_pkey_d
    sha3(container->hw_pkey_a, size, &digest);
    if(memcmp(params->hw_key_hash, digest, sizeof(sha3_t)))
    {
        FAILED(HW_KEY_HASH_TEST,"invalid hw keys");
    }

    if (std::any_of(container->reserved, &(container->reserved[ARRAY_SIZE(container->reserved)]), pred_notZero))
    {
        FAILED(CONTAINER_RESERVED_TEST, "container reserved field not 0");
    }

    // process prefix header
    prefix = (ROM_v3_prefix_header_raw*) &container->prefix;
    // test for valid header version, hash & signature algorithms (sanity check)
    if(!v3_valid_ver_alg(&prefix->ver_alg, SIG_ALG_ECDSA521_MLDSA))
    {
        FAILED(PREFIX_VER_ALG_TEST,"bad prefix header version,alg's");
    }

    // test for valid prefix header signatures (all)
    hw_data = (ROM_v3_prefix_data_raw*) (prefix
                                      + V3_PREFIX_HEADER_SIZE(prefix));
    sha3((uint8_t*)prefix, V3_PREFIX_HEADER_SIZE(prefix), &digest);

    // Test for HW Signatures:
    // First ec_verify hw_ecdsa_public_key_A and hw_signature A, hw sig D
    if (ec_verify (container->hw_pkey_a,
                   digest,
                   hw_data->hw_sig_a)<1)
    {
        FAILED(HW_SIGNATURE_TEST_ECDSA,"invalid hw signature - ECDSA");
    }


    // Then hw_mldsa_public_key_d (hw_pkey_d) and hw_signature_D
    // @TODO JIRA:PFHB-677 enable mldsa_verify call
    //if(mldsa_verify(hw_data->hw_sig_d,
    //                MLDSA_SIG_SIZE,
    //                digest,
    //                SHA3_DIGEST_LENGTH,
    //                container->hw_pkey_d,
    //                MLDSA_PUBLIC_KEY_SIZE) == 0)
    //{
    //    FAILED(HW_SIGNATURE_TEST_MLDSA,"invalid hw signature - MLDSA");
    //}

    // test for machine specific matching ecid
    // All ECID bytes must be 0
    if (std::any_of(prefix->ecid, &prefix->ecid[ECID_SIZE], pred_notZero))
    {
        FAILED(PREFIX_ECID_TEST, "invalid ecid bytes");
    }

    if (prefix->reserved)
    {
        FAILED(PREFIX_RESERVED_TEST, "perfix reserved field not 0");
    }

    if (std::any_of(prefix->reserved1, &(prefix->reserved1[ARRAY_SIZE(prefix->reserved1)]), pred_notZero))
    {
        FAILED(PREFIX_RESERVED1_TEST, "perfix reserved1 field not 0");
    }

    // test for valid prefix payload hash
    // size whould be over both public keys
    size = GET64(prefix->payload_size);
    // hash public keys
    sha3(hw_data->fw_pkey_p, size, &digest);
    // compare to hash
    if(memcmp(prefix->payload_hash, digest, sizeof(sha3_t)))
    {
        FAILED(PREFIX_HASH_TEST,"invalid prefix payload hash");
    }
    // test for valid fw key count (V3 only supports 2)
    if (prefix->fw_key_count != V3_FW_KEY_COUNT)
    {
        FAILED(FW_KEY_INVALID_COUNT,"fw key count not 2");
    }
    // finish processing prefix header
    // test for protection of all fw key material (sanity check)
    if(size != (sizeof(ecc_key_t)           // fw_pkey_p;
                + sizeof(mldsa_pub_key_t))) // fw_pkey_s;

    {
        FAILED(FW_KEY_PROTECTION_TEST,"incomplete fw key protection in prefix header");
    }

    // start processing fw header
    header = (ROM_v3_fw_header_raw*) (hw_data
                                     + sizeof(ROM_v3_prefix_data_raw));


    // test for fw secure version - compare what was passed in via
    // params->log to what the container's fw header has
    if( header->fw_secure_version < i_fw_secure_version)
    {
        FAILED(SECURE_VERSION_TEST,"bad container fw secure version");
    }

    // test for valid header version, hash & signature algorithms (sanity check)
    if(!v3_valid_ver_alg(&header->ver_alg, 0))
    {
        FAILED(HEADER_VER_ALG_TEST,"bad fw header version,alg");
    }

    // test for valid fw header signatures (all)
    fw_sig = (ROM_v3_fw_sig_raw*) (header
                                   + sizeof(ROM_v3_fw_header_raw));
    sha3((uint8_t*)header, V3_FW_HEADER_SIZE(header), &digest);


    // Test for FW (aka FW) Signatures:
    // First ec_verify fw_ecdsa_public_key_P and fw_signature P
    if (ec_verify (hw_data->fw_pkey_p,
                   digest,
                   fw_sig->fw_sig_p)<1)
    {
        FAILED(FW_SIGNATURE_TEST_ECDSA,"invalid fw signature - ECDSA");
    }


    // Then fw_mldsa_public_key_S and fw_signature_S
    // @TODO JIRA:PFHB-677 enable mldsa_verify call
    //if(mldsa_verify(sw_sig->sw_sig_s,
    //                MLDSA_SIG_SIZE,
    //                digest,
    //                SHA3_DIGEST_LENGTH,
    //                hw_data->sw_pkey_s,
    //                MLDSA_PUBLIC_KEY_SIZE) == 0)
    //{
    //    FAILED(SW_SIGNATURE_TEST_MLDSA,"invalid sw signature - MLDSA");
    //}


    // test for machine specific matching ecid
    // check for all 0; if not 0 fail
    if (std::any_of(header->ecid, &header->ecid[ECID_SIZE], pred_notZero))
    {
        FAILED(HEADER_ECID_TEST, "ecid bytes are not 0");
    }

    if (header->reserved)
    {
        FAILED(HEADER_RESERVED_TEST, "header reserved not 0");
    }

    if (std::any_of(header->reserved1, &(header->reserved1[ARRAY_SIZE(header->reserved1)]), pred_notZero))
    {
        FAILED(HEADER_RESERVED1_TEST, "header reserved1 not 0");
    }

    // Setup the ptr to the data for the sha3 hash call below
    uint8_t* data_offset = 0;
    if (i_data == nullptr)
    {
        // Set the data_offset to the default location of the data
        // being just past the V3 container header
        data_offset = reinterpret_cast<uint8_t*>(container)
                      + V3_SECURE_HEADER_SIZE;
    }
    else
    {
        data_offset = reinterpret_cast<uint8_t*>(i_data);
    }

    size = GET64(header->payload_size_protected);
    sha3(data_offset, size, &digest);

    if(memcmp(header->payload_hash_protected, digest, sizeof(sha3_t)))
    {
        FAILED(HEADER_HASH_TEST,"invalid fw payload hash");
    }
    params->log=CONTEXT|COMPLETED;
    return ROM_DONE;
}
