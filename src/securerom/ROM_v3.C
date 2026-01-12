/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/ROM_v3.C $                                      */
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

#include <securerom/ROM.H>
#include <securerom/ecverify.H>
#include <securerom/status_codes.H>
#include <securerom/mlca.H>
#include <string.h>

#define v3_valid_magic_number(header) \
    (GET32((header)->magic_number) == ROM_MAGIC_NUMBER)
#define v3_valid_container_version(header) \
    (GET16((header)->version) == V3_CONTAINER_VERSION)
#define v3_valid_prefix_header_version(header) \
    (GET16((header)->ver_alg.version) == V3_HEADER_VERSION)
#define v3_valid_fw_header_version(header) \
    (GET16((header)->ver_alg.version) == V3_HEADER_VERSION)

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#endif

static bool is_zero(uint8_t* data, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (data[i] != 0)
        {
            return false;
        }
    }
    return true;
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
asm(".globl .L.ROM_v3_verify");
ROM_response ROM_v3_verify( ROM_v3_container_raw* container,
                            ROM_hw_params* params,
                            void* i_data,
                            ROM_HASH_ALGORITHM i_hash_algo)
{
    sha3_t digest;  // used for both sha3_512 and sha512 hash algorithms since
                    // they are the same size
    ROM_v3_prefix_header_raw* prefix;
    ROM_v3_prefix_data_raw* hw_data;
    ROM_v3_fw_header_raw* fw_header;
    ROM_v3_fw_sig_raw* fw_sig;
    uint64_t size;
    ROM_SIGNATURE_ALGORITHM expected_fw_sig_algo;
    int mldsa_rc = 0;

    // params->log is used to pass in a FW Secure Version to
    // compare against the container's fw_header's fw_secure_version field
    uint8_t i_fw_secure_version = static_cast<uint8_t>(params->log);

    params->log=CONTEXT|BEGIN;

    // Test for valid input hash algorithm
    // While the V3 container can support different hash algorithms in different
    // places, currently ONLY 1 of sha512() and sha3_512() can be used
    // throughout the container
    if ((i_hash_algo != HASH_ALG_SHA3_512) &&
        (i_hash_algo != HASH_ALG_SHA512))
    {
        FAILED(INVALID_HASH_ALGO_INPUT,"invalid i_hash_algo input");
    }

    // Since we have a valid i_hash_algo, set the corresponding expected
    // fw signature algorithm
    if (i_hash_algo == HASH_ALG_SHA3_512)
    {
        expected_fw_sig_algo = SIG_ALG_SHA3_512_ECDSA521_MLDSA;
    }
    else // HASH_ALG_SHA512
    {
        expected_fw_sig_algo = SIG_ALG_SHA512_ECDSA521_MLDSA;
    }

    // ----------------------------------------
    // Process initial fields of the container
    // ---------------------------------------

    // Test for valid container magic number and version (sanity check)
    if(!v3_valid_magic_number(container))
      FAILED(MAGIC_NUMBER_TEST,"bad container magic number");

    if(!v3_valid_container_version(container))
      FAILED(CONTAINER_VERSION_TEST,"bad container version");

    // Process hw keys
    // Test for valid hw keys
    // Size is over both public keys
    size = sizeof(ecc_key_t)           // hw_pkey_a
            + sizeof(mldsa_pub_key_t); // hw_pkey_d
    // Use the passed in hash algorithm to hash the keys
    // NOTE: container does not have a field that explicitly says
    //       what hash was used for these hw public keys
    if (i_hash_algo == HASH_ALG_SHA3_512)
    {
        sha3(container->hw_pkey_a, size, &digest);
    }
    else // HASH_ALG_512
    {
        SHA512_Hash(container->hw_pkey_a, size, &digest);
    }
    // Compare it to the HW Keys' Hash that was passed in
    if(memcmp(params->hw_key_hash, digest, sizeof(sha3_t)))
    {
        FAILED(HW_KEY_HASH_TEST,"invalid hw keys");
    }

    // Test that reserved field is zero
    if (!is_zero(container->reserved, ARRAY_SIZE(container->reserved)))
    {
        FAILED(CONTAINER_RESERVED_TEST, "container reserved field not 0");
    }

    // ----------------------
    // Process prefix header
    // ----------------------
    prefix = (ROM_v3_prefix_header_raw*) &container->prefix;

    // Test for valid prefix header version
    if(!v3_valid_prefix_header_version(prefix))
        FAILED(PREFIX_VERSION_TEST,"bad prefix header version");

    // Test for mismatch between input hash algorithm and
    // container's hw prefix hash algorithm
    uint8_t prefix_hash_algo = prefix->ver_alg.hash_alg;
    if (i_hash_algo > prefix_hash_algo)
        FAILED(HASH_ALGO_MISTMATCH_FW_PUBLIC_KEYS_1,"input i_hash_algo > hw prefix header algo");

    if (i_hash_algo < prefix_hash_algo)
        FAILED(HASH_ALGO_MISTMATCH_FW_PUBLIC_KEYS_2,"input i_hash_algo < hw prefix header algo");

    // Test for mismatch between expected signature hash algorithm and
    // container's hw prefix signature algorithm
    uint8_t prefix_sig_algo = prefix->ver_alg.sig_alg;
    if (expected_fw_sig_algo > prefix_sig_algo)
        FAILED(HASH_ALGO_MISTMATCH_FW_SIG_1,"expected sig algo > hw prefix header algo");

    if (expected_fw_sig_algo < prefix_sig_algo)
        FAILED(HASH_ALGO_MISTMATCH_FW_SIG_2,"expected sig algo < hw prefix header algo");

    // Test for valid prefix header signatures (all)
    hw_data = (ROM_v3_prefix_data_raw*) ((uint8_t*) prefix + V3_PREFIX_HEADER_SIZE(prefix));
    // Use the proper hash algorithm to hash
    if (i_hash_algo == HASH_ALG_SHA3_512)
    {
        sha3((uint8_t*)prefix, V3_PREFIX_HEADER_SIZE(prefix), &digest);
    }
    else // HASH_ALG_512
    {
        SHA512_Hash((uint8_t*)prefix, V3_PREFIX_HEADER_SIZE(prefix), &digest);
    }

    // Test for HW Signatures:
    // First ec_verify hw_ecdsa_public_key_A and hw_signature A
    if (ec_verify (container->hw_pkey_a,
                   digest,
                   hw_data->hw_sig_a)<1)
    {
        FAILED(HW_SIGNATURE_TEST_ECDSA,"invalid hw signature - ECDSA");
    }

    // Then hw_mldsa_public_key_d (hw_pkey_d) and hw_signature_D
    mldsa_rc = mldsa_verify(hw_data->hw_sig_d,
                    MLDSA_SIG_SIZE,
                    digest,
                    SHA3_DIGEST_LENGTH,
                    container->hw_pkey_d,
                    MLDSA_PUBLIC_KEY_SIZE);

    if(mldsa_rc <= 0)
    {
        FAILED(HW_SIGNATURE_TEST_MLDSA,"invalid hw signature - MLDSA");
    }

    // Test for machine specific matching ecid
    // All ECID bytes must be 0
    if (!is_zero(prefix->ecid, ECID_SIZE))
    {
        FAILED(PREFIX_ECID_TEST, "invalid ecid bytes");
    }

    if (prefix->reserved)
    {
        FAILED(PREFIX_RESERVED_TEST, "perfix reserved field not 0");
    }

    if (!is_zero(prefix->reserved1, ARRAY_SIZE(prefix->reserved1)))
    {
        FAILED(PREFIX_RESERVED1_TEST, "perfix reserved1 field not 0");
    }

    // Test for valid prefix payload hash
    // size should be over both public keys
    size = GET64(prefix->payload_size);
    // Use the proper hash algorithm to hash the public fw keys
    if (i_hash_algo == HASH_ALG_SHA3_512)
    {
        sha3(hw_data->fw_pkey_p, size, &digest);
    }
    else // HASH_ALG_512
    {
        SHA512_Hash(hw_data->fw_pkey_p, size, &digest);
    }
    // Compare to hash
    if(memcmp(prefix->payload_hash, digest, sizeof(sha3_t)))
    {
        FAILED(PREFIX_HASH_TEST,"invalid prefix payload hash");
    }

    // Test for valid fw key count (V3 only supports 2)
    if (prefix->fw_key_count != V3_FW_KEY_COUNT)
    {
        FAILED(FW_KEY_INVALID_COUNT,"fw key count not 2");
    }

    // Finish processing prefix header
    // Test for protection of all fw key material (sanity check)
    if(size != (sizeof(ecc_key_t)           // fw_pkey_p;
                + sizeof(mldsa_pub_key_t))) // fw_pkey_s;

    {
        FAILED(FW_KEY_PROTECTION_TEST,"incomplete fw key protection in prefix header");
    }

    // --------------------------
    // Processing fw header
    // --------------------------
    fw_header = (ROM_v3_fw_header_raw*) ((uint8_t*)hw_data
                                       + sizeof(ROM_v3_prefix_data_raw));

    // Test for fw secure version - compare what was passed in via
    // params->log to what the container's fw header has
    if( fw_header->fw_secure_version < i_fw_secure_version)
    {
        FAILED(SECURE_VERSION_TEST,"bad container fw secure version");
    }

    // Test for valid prefix header version
    if(!v3_valid_fw_header_version(prefix))
        FAILED(FW_HEADER_VERSION_TEST,"bad fw header version");

    // Test for mismatch between input hash algorithm and
    // container's hw prefix hash algorithm
    uint8_t fw_hdr_payload_hash_algo = fw_header->ver_alg.hash_alg;
    if (i_hash_algo > fw_hdr_payload_hash_algo)
        FAILED(HASH_ALGO_MISTMATCH_FW_PUBLIC_KEYS_1,"input i_hash_algo > fw header payload algo");

    if (i_hash_algo < fw_hdr_payload_hash_algo)
        FAILED(HASH_ALGO_MISTMATCH_FW_PUBLIC_KEYS_2,"input i_hash_algo < fw header payload algo");


    // test for valid fw header signatures (all)
    fw_sig = (ROM_v3_fw_sig_raw*) ((uint8_t*)fw_header
                                   + sizeof(ROM_v3_fw_header_raw));
    // Use the proper hash algorithm
    if (i_hash_algo == HASH_ALG_SHA3_512)
    {
        sha3((uint8_t*)fw_header, V3_FW_HEADER_SIZE(fw_header), &digest);
    }
    else // HASH_ALG_512
    {
        SHA512_Hash((uint8_t*)fw_header, V3_FW_HEADER_SIZE(header), &digest);
    }

    // Test for FW (aka FW) Signatures:
    // First ec_verify fw_ecdsa_public_key_P and fw_signature P
    if (ec_verify (hw_data->fw_pkey_p,
                   digest,
                   fw_sig->fw_sig_p)<1)
    {
        FAILED(FW_SIGNATURE_TEST_ECDSA,"invalid fw signature - ECDSA");
    }

    // Then fw_mldsa_public_key_S and fw_signature_S
    mldsa_rc = mldsa_verify(fw_sig->fw_sig_s,
                    MLDSA_SIG_SIZE,
                    digest,
                    SHA3_DIGEST_LENGTH,
                    hw_data->fw_pkey_s,
                    MLDSA_PUBLIC_KEY_SIZE);

    if(mldsa_rc <= 0)
    {
        FAILED(FW_SIGNATURE_TEST_MLDSA,"invalid fw signature - MLDSA");
    }

    // Test for machine specific matching ecid
    // check for all 0; if not 0 fail
    if (!is_zero(fw_header->ecid, ECID_SIZE))
    {
        FAILED(HEADER_ECID_TEST, "fw header ecid bytes are not 0");
    }

    if (fw_header->reserved)
    {
        FAILED(HEADER_RESERVED_TEST, "fw header reserved not 0");
    }

    if (!is_zero(fw_header->reserved1, ARRAY_SIZE(fw_header->reserved1)))
    {
        FAILED(HEADER_RESERVED1_TEST, "fw header reserved1 not 0");
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

    // Verify payload
    size = GET64(fw_header->payload_size_protected);
    // Use the proper hash algorithm
    if (i_hash_algo == HASH_ALG_SHA3_512)
    {
        sha3(data_offset, size, &digest);
    }
    else // HASH_ALG_512
    {
        SHA512_Hash(data_offset, size, &digest);
    }

    if(memcmp(fw_header->payload_hash_protected, digest, sizeof(sha3_t)))
    {
        FAILED(HEADER_HASH_TEST,"invalid fw payload hash");
    }
    params->log=CONTEXT|COMPLETED;
    return ROM_DONE;
}
