/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/ROM.C $                                         */
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

#include <securerom/ROM.H>
#include <securerom/ecverify.H>
#include <securerom/status_codes.H>
#include <string.h>

#define valid_magic_number(header) \
    (GET32((header)->magic_number) == ROM_MAGIC_NUMBER)
#define valid_container_version(header) \
    (GET16((header)->version) == CONTAINER_VERSION)

static int valid_ver_alg(ROM_version_raw* ver_alg, uint8_t sig_alg)
{
    if (GET16(ver_alg->version) != HEADER_VERSION)
    {
        return 0;
    }
    if (ver_alg->hash_alg != HASH_ALG_SHA512)
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

static int valid_ecid(int ecid_count, uint8_t* ecids, uint8_t* hw_ecid)
{
    if (ecid_count == 0)
    {
        return 1;
    }
    return 0;
}

static int multi_key_verify(uint8_t* digest, int key_count, uint8_t* keys,
                            uint8_t* sigs)
{
    for (;key_count;key_count--,keys+=sizeof(ecc_key_t),
         sigs+=sizeof(ecc_signature_t))
    {
        if (ec_verify (keys, digest, sigs)<1)
        {
            return 0;
        }
    }
    return 1;
}

static inline ROM_container_raw* cast_container(uint64_t addr)
{
    return (ROM_container_raw*) Convert_Mem_Addr(physical_addr(addr));
}

static inline void ROM_init_cache_area(uint64_t target, uint64_t size)
{
    uint64_t i;
    for (i=0;i<size;i+=CACHE_LINE)
    {
        assem_DCBZ(target);
        target+=CACHE_LINE;
    }
}

#undef  CONTEXT
#define CONTEXT  ROM_SRESET
#ifdef EMULATE_HW
void ROM_sreset (void)
{
#else
void ROM_sreset(void)
{
    asm volatile (".globl rom_sreset\n rom_sreset:"); //skip prologue
#endif
    // should never get here unless started too soon by fsp/sbe, checkstop
    ERROR_STOP(EXECUTION_ERROR,"sreset");
}

#ifdef EMULATE_HW
    #define FAILED(_c,_m) { params->log=ERROR_EVENT|CONTEXT|(_c); \
        printf ("FAILED '%s'\n", (_m)); return ROM_FAILED; }
#else
    #define FAILED(_c,_m) { params->log=ERROR_EVENT|CONTEXT|(_c); \
        return ROM_FAILED; }
#endif

#undef  CONTEXT
#define CONTEXT  ROM_VERIFY
// NOTE: ROM_verify is called with with hrmor relative addresses from Hostboot
asm(".globl .L.ROM_verify");
ROM_response ROM_verify( ROM_container_raw* container,
                         ROM_hw_params* params )
{
    SHA512_t digest;
    ROM_prefix_header_raw* prefix;
    ROM_prefix_data_raw* hw_data;
    ROM_sw_header_raw* header;
    ROM_sw_sig_raw* sw_sig;
    uint64_t size;

    params->log=CONTEXT|BEGIN;

    // test for valid container magic number, version, hash & signature
    // algorithms (sanity check)
    if(!valid_magic_number(container))
      FAILED(MAGIC_NUMBER_TEST,"bad container magic number");
    if(!valid_container_version(container))
      FAILED(CONTAINER_VERSION_TEST,"bad container version");

    // process hw keys
    // test for valid hw keys
    SHA512_Hash(container->hw_pkey_a, HW_KEY_COUNT*sizeof(ecc_key_t), &digest);
    if(memcmp(params->hw_key_hash, digest, sizeof(SHA512_t)))
    {
        FAILED(HW_KEY_HASH_TEST,"invalid hw keys");
    }

    // process prefix header
    prefix = (ROM_prefix_header_raw*) &container->prefix;
    // test for valid header version, hash & signature algorithms (sanity check)
    if(!valid_ver_alg(&prefix->ver_alg, SIG_ALG_ECDSA521))
    {
        FAILED(PREFIX_VER_ALG_TEST,"bad prefix header version,alg's");
    }
    // test for valid prefix header signatures (all)
    hw_data = (ROM_prefix_data_raw*) (prefix->ecid
                                      + prefix->ecid_count*ECID_SIZE);
    SHA512_Hash((uint8_t*)prefix, PREFIX_HEADER_SIZE(prefix), &digest);
    if(!multi_key_verify(digest, HW_KEY_COUNT, container->hw_pkey_a,
                         hw_data->hw_sig_a))
    {
        FAILED(HW_SIGNATURE_TEST,"invalid hw signature");
    }
    // test for machine specific matching ecid
    if(!valid_ecid(prefix->ecid_count, prefix->ecid, params->my_ecid))
    {
        FAILED(PREFIX_ECID_TEST,"unauthorized prefix ecid");
    }
    // test for valid prefix payload hash
    size = GET64(prefix->payload_size);
    SHA512_Hash(hw_data->sw_pkey_p, size, &digest);
    if(memcmp(prefix->payload_hash, digest, sizeof(SHA512_t)))
    {
        FAILED(PREFIX_HASH_TEST,"invalid prefix payload hash");
    }
    // test for valid sw key count
    if (prefix->sw_key_count < SW_KEY_COUNT_MIN ||
        prefix->sw_key_count > SW_KEY_COUNT_MAX)
    {
        FAILED(SW_KEY_INVALID_COUNT,"sw key count not between 1-3");
    }
    // finish proce`sing prefix header
    // test for protection of all sw key material (sanity check)
    if(size != (prefix->sw_key_count * sizeof(ecc_key_t)))
    {
        FAILED(SW_KEY_PROTECTION_TEST,"incomplete sw key protection in prefix header");
    }

    // start processing sw header
    header = (ROM_sw_header_raw*) (hw_data->sw_pkey_p
                                   + prefix->sw_key_count*sizeof(ecc_key_t));
    // test for valid header version, hash & signature algorithms (sanity check)
    if(!valid_ver_alg(&header->ver_alg, 0))
    {
        FAILED(HEADER_VER_ALG_TEST,"bad sw header version,alg");
    }
    // test for valid sw header signatures (all)
    sw_sig = (ROM_sw_sig_raw*) (header->ecid + header->ecid_count*ECID_SIZE);
    SHA512_Hash((uint8_t*)header, SW_HEADER_SIZE(header), &digest);
    if(!multi_key_verify(digest, prefix->sw_key_count, hw_data->sw_pkey_p,
                         sw_sig->sw_sig_p))
    {
        FAILED(SW_SIGNATURE_TEST,"invalid sw signature");
    }
    // test for machine specific matching ecid
    if(!valid_ecid(header->ecid_count, header->ecid, params->my_ecid))
    {
        FAILED(HEADER_ECID_TEST,"unauthorized sw ecid");
    }
    // test for entry point within protected payload (sanity check)
    params->entry_point = GET64(header->code_start_offset);
    //check if the entry is HRMOR-relative and aligned
    if(params->entry_point & ~(ENTRY_MASK))
    {
        FAILED(ENTRY_VALID_TEST,"entry is not HRMOR relative or not aligned");
    }
    size = GET64(header->payload_size);
    // must have full instruction (3 more bytes)
    if(params->entry_point+3 >= size)
    {
        FAILED(CODE_PROTECTION_TEST,"unprotected code_start in sw header");
    }
    // begin test for valid sw payload hash
    SHA512_Hash((uint8_t*)container + 4096, size, &digest);

    if(memcmp(header->payload_hash, digest, sizeof(SHA512_t)))
    {
        FAILED(HEADER_HASH_TEST,"invalid sw payload hash");
    }
    params->log=CONTEXT|COMPLETED;
    return ROM_DONE;
}
