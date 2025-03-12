/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/common/containerheader.C $                 */
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
#include <secureboot/containerheader.H>
#include "../common/securetrace.H"
#include <secureboot/secure_reasoncodes.H>
#include <pnor/pnor_reasoncodes.H>

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace SECUREBOOT
{

errlHndl_t ContainerHeader::parse_header()
{
    assert(iv_pHdrStart != nullptr, "Cannot parse header that is nullptr");

    errlHndl_t l_errl = nullptr;

    do {

    TRACDCOMP(g_trac_secure,ENTER_MRK"ContainerHeader::parse_header()");

    /*---- Use common header to determine if it is V1 o V3 ----*/
    // Since header could be for V1 or V3, start by applying it to
    // ROM_common_container_fields iv_commonRawHdr:
    //  uint32_t    magic_number;    // (17082011)
    //  uint16_t    version;         // 1 or 3
    //  uint64_t    container_size;  // filled by caller

    // Check magic_number first, and then version
    const uint8_t* l_common_hdr = reinterpret_cast<const uint8_t*>(iv_pHdrStart);
    l_errl = safeMemCpyAndInc(&iv_commonRawHdr, l_common_hdr, sizeof(iv_commonRawHdr));
    if(l_errl)
    {
        break;
    }

    // Early check if magic number is valid, as a quick check to try and prevent
    // any storage exceptions while parsing header.
    if(iv_commonRawHdr.magic_number != ROM_MAGIC_NUMBER)
    {
        TRACFCOMP(g_trac_secure,ERR_MRK"ContainerHeader::parse_header() Magic Number = 0x%X not valid to parse Container Header",
                  iv_commonRawHdr.magic_number);

        /*@
         * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        SECUREBOOT::MOD_SECURE_CONT_HDR_PARSE
         * @reasoncode      PNOR::RC_BAD_SECURE_MAGIC_NUM
         * @userdata1       Actual magic number
         * @userdata2       Expected magic number
         * @devdesc         Error parsing secure header
         * @custdesc        Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        SECUREBOOT::MOD_SECURE_CONT_HDR_PARSE,
                        PNOR::RC_BAD_SECURE_MAGIC_NUM,
                        iv_commonRawHdr.magic_number,
                        ROM_MAGIC_NUMBER,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
        break;
    }

    // Check the container version and handle accordingly
    if ((iv_commonRawHdr.version != CONTAINER_VERSION) && // defined as 1 in ROM.H
        (iv_commonRawHdr.version != V3_CONTAINER_VERSION)) // defined as 0x03 in HOM.H
    {
        TRACFCOMP(g_trac_secure,ERR_MRK"ContainerHeader::parse_header() Invalid Container Version = 0x%X (should be 0x1 or 0x3)",
                  iv_commonRawHdr.version);

        /*@
         * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        SECUREBOOT::MOD_SECURE_CONT_HDR_PARSE
         * @reasoncode      SECUREBOOT::RC_INVALID_HEADER_VERSION
         * @userdata1       Container Version from the Header
         * @userdata2       <unused>
         * @devdesc         Error parsing secure header
         * @custdesc        Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        SECUREBOOT::MOD_SECURE_CONT_HDR_PARSE,
                        SECUREBOOT::RC_INVALID_HEADER_VERSION,
                        iv_commonRawHdr.version,
                        0,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
        break;
    }

    // V1 Support
    else if (iv_commonRawHdr.version == CONTAINER_VERSION)
    {
        iv_isV3 = false;

        TRACDCOMP(g_trac_secure,"ContainerHeader::parse_header(): V1 path: "
                  "iv_isV3=%d",iv_isV3 );

        // Now that we know that it is V1, we can use the V1 structures

        /*---- Parse ROM_container_raw ----*/
        // The rom code has a placeholder for the prefix in the first struct
        // Copy the first part pointed to by iv_pHdrStart onto internal
        // structure iv_headerInfo.hw_hdr
        const uint8_t* l_hdr = reinterpret_cast<const uint8_t*>(iv_pHdrStart);
        size_t l_size = offsetof(ROM_container_raw, prefix);
        l_errl = safeMemCpyAndInc(&iv_headerInfo.hw_hdr, l_hdr, l_size);
        if(l_errl)
        {
            break;
        }

        /*---- Parse ROM_prefix_header_raw ----*/
        l_size = offsetof(ROM_prefix_header_raw, ecid);
        l_errl = safeMemCpyAndInc(&iv_headerInfo.hw_prefix_hdr, l_hdr, l_size);
        if(l_errl)
        {
            break;
        }

        // Ensure HW header ECID count is 0, so that we can safely skip reading the
        // ECID array that is defined in the secure header but unsupported in code.
        l_errl = validateEcidCount(
            ECID_COUNT_FIELD::HW_HEADER,
            iv_headerInfo.hw_prefix_hdr.ecid_count);
        if(l_errl)
        {
            break;
        }

        /*---- Parse ROM_prefix_data_raw ----*/
        l_size = offsetof(ROM_prefix_data_raw, sw_pkey_p);
        l_errl = safeMemCpyAndInc(&iv_headerInfo.hw_prefix_data, l_hdr, l_size);
        if(l_errl)
        {
            break;
        }

        // Get SW keys
        l_size = iv_headerInfo.hw_prefix_hdr.sw_key_count * sizeof(ecc_key_t);
        // Cache total software keys size
        iv_totalSwKeysSize = l_size;
        constexpr size_t MAX_SW_KEY_DATA=(SW_KEY_COUNT_MAX *
                                   sizeof(iv_headerInfo.hw_prefix_data.sw_pkey_p));
        l_errl = safeMemCpyAndInc(&iv_headerInfo.hw_prefix_data.sw_pkey_p, l_hdr,
            l_size,MAX_SW_KEY_DATA);
        if(l_errl)
        {
            break;
        }

        /*---- Parse ROM_sw_header_raw ----*/
        l_size = offsetof(ROM_sw_header_raw, ecid);
        l_errl = safeMemCpyAndInc(&iv_headerInfo.sw_hdr, l_hdr, l_size);
        if(l_errl)
        {
            break;
        }
        strncpy(iv_componentId,iv_headerInfo.sw_hdr.component_id,
            sizeof(iv_headerInfo.sw_hdr.component_id));

        // Ensure SW header ECID count is 0, so that we can safely skip reading the
        // ECID array that is defined in the secure header but unsupported in code.
        l_errl = validateEcidCount(
            ECID_COUNT_FIELD::SW_HEADER,
            iv_headerInfo.sw_hdr.ecid_count);
        if(l_errl)
        {
            break;
        }

        /*---- Parse ROM_sw_sig_raw ----*/
        l_errl = safeMemCpyAndInc(&iv_headerInfo.sw_sig.sw_sig_p, l_hdr,
                                  iv_totalSwKeysSize,MAX_SW_KEY_DATA);
        if(l_errl)
        {
            break;
        }
    }

    // V3 Support
    else
    {
        iv_isV3 = true;

        // Now that we know that it is V3, we can use the V3 structures
        TRACDCOMP(g_trac_secure,"ContainerHeader::parse_header(): V3 path: "
                  "iv_isV3=%d", iv_isV3 );

        /*---- Parse ROM_v3_container_raw ----*/
        // The rom code has a placeholder for the prefix in the first struct
        // Copy the first part pointed to by iv_pHdrStart onto internal
        // structure iv_v3_headerInfo.hw_hdr
        const uint8_t* l_hdr = reinterpret_cast<const uint8_t*>(iv_pHdrStart);
        size_t l_size = offsetof(ROM_v3_container_raw, prefix);
        l_errl = safeMemCpyAndInc(&iv_v3_headerInfo.v3_hw_hdr,
                                  l_hdr,
                                  l_size,
                                  V3_SECURE_HEADER_SIZE);
        if(l_errl)
        {
            break;
        }

        /*---- Parse ROM_v3_prefix_header_raw ----*/
        l_size = sizeof(ROM_v3_prefix_header_raw);
        l_errl = safeMemCpyAndInc(&iv_v3_headerInfo.v3_hw_prefix_hdr,
                                  l_hdr,
                                  l_size,
                                  V3_SECURE_HEADER_SIZE);
        if(l_errl)
        {
            break;
        }

        // @TODO JIRA:PFHB-802 Determine if anything needs to be checked for
        // ECID section as it looks like everything is defaulting to all zeroes
        TRACDBIN(g_trac_secure,"ContainerHeader::parse_header(): V3: ECID Section",
                 &iv_v3_headerInfo.v3_hw_prefix_hdr.ecid, ECID_SIZE);

        // Check for sw_key_count to be 2 is in validate() check below
        // Cache total software keys size
        iv_totalSwKeysSize = sizeof(ecc_key_t)  // sw_pkey_p;
                             + sizeof(mldsa_pub_key_t); // sw_pkey_s;

        /*---- Parse ROM_v3_prefix_data_raw ----*/
        l_size = sizeof(ROM_v3_prefix_data_raw);
        l_errl = safeMemCpyAndInc(&iv_v3_headerInfo.v3_hw_prefix_data,
                                  l_hdr,
                                  l_size,
                                  V3_SECURE_HEADER_SIZE);
        if(l_errl)
        {
            break;
        }

        /*---- Parse ROM_v3_sw_header_raw ----*/
        l_size = sizeof(ROM_v3_sw_header_raw);
        l_errl = safeMemCpyAndInc(&iv_v3_headerInfo.v3_sw_hdr,
                                  l_hdr,
                                  l_size,
                                  V3_SECURE_HEADER_SIZE);
        if(l_errl)
        {
            break;
        }

        // Set container component id
        strncpy(iv_componentId,
                iv_v3_headerInfo.v3_sw_hdr.component_id,
                sizeof(iv_v3_headerInfo.v3_sw_hdr.component_id));

        /*---- Parse ROM_v3_sw_sig_raw ----*/
        l_size = sizeof(ROM_v3_sw_sig_raw);
        l_errl = safeMemCpyAndInc(&iv_v3_headerInfo.v3_sw_sig,
                                  l_hdr,
                                  l_size,
                                  V3_SECURE_HEADER_SIZE);
        if(l_errl)
        {
            break;
        }
    }

    // Parse hw and sw flags
    parseFlags();

#ifndef __HOSTBOOT_RUNTIME
    // Generate hw hash key
    genHwKeyHash();
#endif

    // After parsing check if header is valid, do some quick bound checks
    l_errl = validate();
    if(l_errl)
    {
        break;
    }

    // Debug printing
    print();

    } while(0);

    TRACDCOMP(g_trac_secure,EXIT_MRK"ContainerHeader::parse_header()");

    return l_errl;
}

void ContainerHeader::initVars()
{
    memset(&iv_headerInfo, 0x00, sizeof(iv_headerInfo));
    memset(&iv_v3_headerInfo, 0x00, sizeof(iv_v3_headerInfo));
    memset(&iv_commonRawHdr, 0x00, sizeof(iv_commonRawHdr));
    memset(iv_hwKeyHash, 0, sizeof(SHA512_t));
    memset(iv_componentId,0x00,sizeof(iv_componentId));
}

void ContainerHeader::genFakeHeader(const size_t i_size,
                                    const char* const i_compId)
{
    // NOTE: this only creates a fake V1 container header
    SecureHeaderInfo info {};
    assert(iv_fakeHeader.data() != nullptr, "Internal fake header buffer nullptr");

    uint8_t* l_hdr = reinterpret_cast<uint8_t*>(iv_fakeHeader.data());

     /*---- ROM_container_raw ----*/
    info.hw_hdr.magic_number = ROM_MAGIC_NUMBER;
    info.hw_hdr.version = CONTAINER_VERSION;
    info.hw_hdr.container_size = i_size + PAGE_SIZE;
    // The rom code has a placeholder for the prefix in the first struct so
    // skip it
    size_t l_size = offsetof(ROM_container_raw, prefix);
    memcpy(l_hdr, &info.hw_hdr, l_size);
    l_hdr += l_size;

    /*---- ROM_prefix_header_raw ----*/
    info.hw_prefix_hdr.ver_alg.version = HEADER_VERSION;
    info.hw_prefix_hdr.ver_alg.hash_alg = HASH_ALG_SHA512;
    info.hw_prefix_hdr.ver_alg.sig_alg = SIG_ALG_ECDSA521;
    info.hw_prefix_hdr.sw_key_count = 1;
    info.hw_prefix_hdr.payload_size = sizeof(ecc_key_t);

    l_size = offsetof(ROM_prefix_header_raw, ecid);
    l_size += info.hw_prefix_hdr.ecid_count * ECID_SIZE;
    memcpy(l_hdr, &info.hw_prefix_hdr, l_size);
    l_hdr += l_size;

    /*---- Parse ROM_prefix_data_raw ----*/
    // Skip over variable number of sw keys as they are already zeroed out
    l_size = offsetof(ROM_prefix_data_raw, sw_pkey_p);
    l_size += info.hw_prefix_hdr.sw_key_count * sizeof(ecc_key_t);
    l_hdr += l_size;

    /*---- ROM_sw_header_raw ----*/
    info.sw_hdr.ver_alg.version = 1;
    strncpy(info.sw_hdr.component_id, i_compId,SW_HDR_COMP_ID_SIZE_BYTES);
    info.sw_hdr.ver_alg.hash_alg = HASH_ALG_SHA512;
    info.sw_hdr.ver_alg.sig_alg = SIG_ALG_ECDSA521;
    info.sw_hdr.payload_size = i_size;

    l_size = offsetof(ROM_sw_header_raw, ecid);
    l_size += info.hw_prefix_hdr.ecid_count * ECID_SIZE;
    memcpy(l_hdr, &info.sw_hdr, l_size);
    l_hdr += l_size;

    /*---- Parse ROM_sw_sig_raw ----*/
    // No-op already zeroed out

    iv_pHdrStart = reinterpret_cast<const uint8_t*>(iv_fakeHeader.data());
}

void ContainerHeader::print() const
{
#ifdef HOSTBOOT_DEBUG
    TRACFCOMP(g_trac_secure, ENTER_MRK"ContainerHeader::print iv_isV3=%d", iv_isV3);

    TRACFCOMP(g_trac_secure,"header content size 0x%X", iv_hdrBytesRead);

    /*---- Print ROM_common_container_fields (iv_commonRawHdr) ----*/
    TRACFCOMP(g_trac_secure,INFO_MRK"Common Container Header Info");

    TRACFCOMP(g_trac_secure,"magic_number 0x%X", iv_commonRawHdr.magic_number);
    TRACFCOMP(g_trac_secure,"version 0x%X", iv_commonRawHdr.version);
    TRACFCOMP(g_trac_secure,"container_size 0x%X", iv_commonRawHdr.container_size);

    if (iv_isV3 == false)
    {
        // V1 container
        TRACFCOMP(g_trac_secure,INFO_MRK"V1 Container Header Info");

        /*---- Print ROM_container_raw ----*/
        TRACFCOMP(g_trac_secure,"magic_number 0x%X", iv_headerInfo.hw_hdr.magic_number);
        TRACFCOMP(g_trac_secure,"version 0x%X", iv_headerInfo.hw_hdr.version);
        TRACFCOMP(g_trac_secure,"container_size 0x%X", iv_headerInfo.hw_hdr.container_size);
        TRACFCOMP(g_trac_secure,"target_hrmor 0x%X", iv_headerInfo.hw_hdr.target_hrmor);
        TRACFCOMP(g_trac_secure,"stack_pointer 0x%X", iv_headerInfo.hw_hdr.stack_pointer);
        TRACFBIN(g_trac_secure,"hw_pkey_a", iv_headerInfo.hw_hdr.hw_pkey_a, 64);
        TRACFBIN(g_trac_secure,"hw_pkey_b", iv_headerInfo.hw_hdr.hw_pkey_b, 64);
        TRACFBIN(g_trac_secure,"hw_pkey_c", iv_headerInfo.hw_hdr.hw_pkey_c, 64);

        /*---- Print ROM_prefix_header_raw ----*/
        TRACFCOMP(g_trac_secure,"hw_flags 0x%X", iv_headerInfo.hw_prefix_hdr.flags);
        TRACFCOMP(g_trac_secure,"sw_key_count 0x%X", iv_headerInfo.hw_prefix_hdr.sw_key_count);
        TRACFBIN(g_trac_secure,"sw public key hash", iv_headerInfo.hw_prefix_hdr.payload_hash, SHA512_DIGEST_LENGTH);


        /*---- Print ROM_prefix_data_raw ----*/
        TRACFBIN(g_trac_secure,"sw_pkey_p", iv_headerInfo.hw_prefix_data.sw_pkey_p, sizeof(ecc_key_t));
        if (iv_headerInfo.hw_prefix_hdr.sw_key_count>1)
        {
            TRACFBIN(g_trac_secure,"sw_pkey_q", iv_headerInfo.hw_prefix_data.sw_pkey_q, sizeof(ecc_key_t));
        }
        if (iv_headerInfo.hw_prefix_hdr.sw_key_count>2)
        {
            TRACFBIN(g_trac_secure,"sw_pkey_r", iv_headerInfo.hw_prefix_data.sw_pkey_r, sizeof(ecc_key_t));
        }

        /*---- Print ROM_sw_header_raw ----*/
        TRACFCOMP(g_trac_secure,"component_id \"%s\"", componentId());
        TRACFCOMP(g_trac_secure,"secure version 0x%.2X", iv_headerInfo.sw_hdr.fw_secure_version);
        TRACFCOMP(g_trac_secure,"payload_size 0x%X", iv_headerInfo.sw_hdr.payload_size );
        TRACFBIN(g_trac_secure,"payload_hash", iv_headerInfo.sw_hdr.payload_hash, SHA512_DIGEST_LENGTH);

        /*---- Print ROM_sw_sig_raw ----*/
        TRACFBIN(g_trac_secure,"sw_sig_p", iv_headerInfo.sw_sig.sw_sig_p, sizeof(ecc_key_t));
        if (iv_headerInfo.hw_prefix_hdr.sw_key_count>1)
        {
            TRACFBIN(g_trac_secure,"sw_sig_q", iv_headerInfo.sw_sig.sw_sig_q, sizeof(ecc_key_t));
        }
        if (iv_headerInfo.hw_prefix_hdr.sw_key_count>2)
        {
            TRACFBIN(g_trac_secure,"sw_sig_r", iv_headerInfo.sw_sig.sw_sig_r, sizeof(ecc_key_t));
        }
    }
    else
    {
        // V3 Container
        TRACFCOMP(g_trac_secure,INFO_MRK"V3 Container Header Info");

        /*---- Print ROM_v3_container_raw ----*/
        TRACFCOMP(g_trac_secure,"magic_number 0x%X", iv_v3_headerInfo.v3_hw_hdr.magic_number);
        TRACFCOMP(g_trac_secure,"version 0x%X", iv_v3_headerInfo.v3_hw_hdr.version);
        TRACFCOMP(g_trac_secure,"container_size 0x%X", iv_v3_headerInfo.v3_hw_hdr.container_size);
        TRACFBIN(g_trac_secure,"hw_pkey_a", iv_v3_headerInfo.v3_hw_hdr.hw_pkey_a, 64);
        TRACFBIN(g_trac_secure,"hw_pkey_d", iv_v3_headerInfo.v3_hw_hdr.hw_pkey_d, 64);

        /*---- Print ROM_v3_prefix_header_raw ----*/
        TRACFCOMP(g_trac_secure,"hw verion_alg.version 0x%X", iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.version);
        TRACFCOMP(g_trac_secure,"hw verion_alg.hash_alg 0x%X", iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.hash_alg );
        TRACFCOMP(g_trac_secure,"hw verion_alg.sig_alg 0x%X", iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.sig_alg);
        TRACFCOMP(g_trac_secure,"hw flags 0x%X", iv_v3_headerInfo.v3_hw_prefix_hdr.flags);
        TRACFCOMP(g_trac_secure,"sw_key_count 0x%X", iv_v3_headerInfo.v3_hw_prefix_hdr.sw_key_count);
        TRACFBIN(g_trac_secure,"sw public key hash", iv_v3_headerInfo.v3_hw_prefix_hdr.payload_hash, SHA3_DIGEST_LENGTH);
        TRACFBIN(g_trac_secure,"hw ECID:", &iv_v3_headerInfo.v3_hw_prefix_hdr.ecid, ECID_SIZE);


        /*---- Print ROM_v3_prefix_data_raw ----*/
        TRACFBIN(g_trac_secure,"hw_sig_a", &iv_v3_headerInfo.v3_hw_prefix_data.hw_sig_a, 64);
        TRACFBIN(g_trac_secure,"hw_sig_d", &iv_v3_headerInfo.v3_hw_prefix_data.hw_sig_d, 64);
        TRACFBIN(g_trac_secure,"sw_pkey_p", &iv_v3_headerInfo.v3_hw_prefix_data.sw_pkey_p, 64);
        TRACFBIN(g_trac_secure,"sw_pkey_s", &iv_v3_headerInfo.v3_hw_prefix_data.sw_pkey_s, 64);

        /*---- Print ROM_v3_sw_header_raw ----*/
        TRACFCOMP(g_trac_secure,"sw verion_alg.version 0x%X", iv_v3_headerInfo.v3_sw_hdr.ver_alg.version);
        TRACFCOMP(g_trac_secure,"sw verion_alg.hash_alg 0x%X", iv_v3_headerInfo.v3_sw_hdr.ver_alg.hash_alg );
        TRACFCOMP(g_trac_secure,"sw verion_alg.sig_alg 0x%X", iv_v3_headerInfo.v3_sw_hdr.ver_alg.sig_alg);
        TRACFCOMP(g_trac_secure,"sw flags 0x%X", iv_v3_headerInfo.v3_hw_prefix_hdr.flags);
        TRACFCOMP(g_trac_secure,"component_id \"%s\"", componentId());
        TRACFCOMP(g_trac_secure,"secure version 0x%.2X", iv_v3_headerInfo.v3_sw_hdr.fw_secure_version);
        TRACFCOMP(g_trac_secure,"payload_size_protected 0x%X", iv_v3_headerInfo.v3_sw_hdr.payload_size_protected );
        TRACFCOMP(g_trac_secure,"payload_size_unprotected 0x%X", iv_v3_headerInfo.v3_sw_hdr.payload_size_unprotected );
        TRACFBIN(g_trac_secure,"payload_hash_protected", iv_v3_headerInfo.v3_sw_hdr.payload_hash_protected, SHA3_DIGEST_LENGTH);
        TRACFBIN(g_trac_secure,"sw ECID:", &iv_v3_headerInfo.v3_sw_hdr.ecid, ECID_SIZE);

        /*---- Print ROM_v3_sw_sig_raw ----*/
        TRACFBIN(g_trac_secure,"sw_sig_p", &iv_v3_headerInfo.v3_sw_sig.sw_sig_p, 64);
        TRACFBIN(g_trac_secure,"sw_sig_s", &iv_v3_headerInfo.v3_sw_sig.sw_sig_s, 64);
    }

    TRACFCOMP(g_trac_secure, EXIT_MRK"ContainerHeader::print");
#endif
}

size_t ContainerHeader::totalContainerSize() const
{
    // Found in common header for V1 and V3
    return    iv_commonRawHdr.container_size;
}

uint32_t ContainerHeader::prefixHeaderFlags() const
{
    return (iv_isV3 == true) ? iv_v3_headerInfo.v3_hw_prefix_hdr.flags // V3
                             : iv_headerInfo.hw_prefix_hdr.flags; // V1
}

const ecc_key_t* ContainerHeader::hw_keys() const
{
    return (iv_isV3 == true) ? &iv_v3_headerInfo.v3_hw_prefix_data.hw_sig_a // V3
                             : &iv_headerInfo.hw_hdr.hw_pkey_a; // V1
}

size_t ContainerHeader::payloadTextSize() const
{
    return (iv_isV3 == true) ? iv_v3_headerInfo.v3_sw_hdr.payload_size_protected // V3
                             : iv_headerInfo.sw_hdr.payload_size; // V1
}

const SHA512_t* ContainerHeader::payloadTextHash() const
{
    return (iv_isV3 == true) ? &iv_v3_headerInfo.v3_sw_hdr.payload_hash_protected // V3
                             : &iv_headerInfo.sw_hdr.payload_hash; // V1
}

size_t ContainerHeader::totalSwKeysSize() const
{
    // Same for V1 and V3
    return iv_totalSwKeysSize;
}

const ecc_key_t* ContainerHeader::sw_keys() const
{
    return (iv_isV3 == true) ? &iv_v3_headerInfo.v3_hw_prefix_data.sw_pkey_p
                             : &iv_headerInfo.hw_prefix_data.sw_pkey_p;
}

const SHA512_t* ContainerHeader::swKeyHash() const
{
    return (iv_isV3 == true) ? &iv_v3_headerInfo.v3_hw_prefix_hdr.payload_hash
                             : &iv_headerInfo.hw_prefix_hdr.payload_hash;
}

const ecc_key_t* ContainerHeader::sw_sigs() const
{
    return (iv_isV3 == true) ? &iv_v3_headerInfo.v3_sw_sig.sw_sig_p
                             : &iv_headerInfo.sw_sig.sw_sig_p;
}

const sb_flags_t* ContainerHeader::sb_flags() const
{
    // Same for V1 and V3 - set in parseFlags()
    return &iv_sbFlags;
}

const SHA512_t* ContainerHeader::hwKeyHash() const
{
    // Same for V1 and V3
    return &iv_hwKeyHash;
}

errlHndl_t ContainerHeader::validate()
{
    errlHndl_t l_errl = nullptr;

    // Local variables to use to keep a common error log
    uint32_t l_magic_number = 0;
    uint16_t l_version = 0;
    uint16_t l_version_alg = 0;
    uint8_t  l_hash_alg = 0;
    uint8_t  l_sig_alg = 0;
    uint8_t  l_sw_key_count = 0;

    if (iv_isV3 == false)
    {
        // V1 Check
        iv_isValid = (iv_hdrBytesRead <= MAX_SECURE_HEADER_SIZE)
            && (iv_headerInfo.hw_hdr.magic_number == ROM_MAGIC_NUMBER)
            && (iv_headerInfo.hw_hdr.version == ROM_VERSION)
            && (iv_headerInfo.hw_prefix_hdr.ver_alg.version == ROM_VERSION)
            && (iv_headerInfo.hw_prefix_hdr.ver_alg.hash_alg == ROM_HASH_ALG)
            && (iv_headerInfo.hw_prefix_hdr.ver_alg.sig_alg == ROM_SIG_ALG)
            && (iv_headerInfo.hw_prefix_hdr.sw_key_count >= SW_KEY_COUNT_MIN)
            && (iv_headerInfo.hw_prefix_hdr.sw_key_count <= SW_KEY_COUNT_MAX)
            && (iv_headerInfo.sw_hdr.payload_size != 0);

        if (iv_isValid == false)
        {
            // Setup local variables for common error log below
            l_magic_number = iv_headerInfo.hw_hdr.magic_number;
            l_version = iv_headerInfo.hw_hdr.version;
            l_version_alg = iv_headerInfo.hw_prefix_hdr.ver_alg.version;
            l_hash_alg = iv_headerInfo.hw_prefix_hdr.ver_alg.hash_alg;
            l_sig_alg = iv_headerInfo.hw_prefix_hdr.ver_alg.sig_alg;
            l_sw_key_count = iv_headerInfo.hw_prefix_hdr.sw_key_count;
        }
    }
    else
    {
        // V3 Check
        iv_isValid = (iv_hdrBytesRead <= V3_SECURE_HEADER_SIZE)
            && (iv_v3_headerInfo.v3_hw_hdr.magic_number == ROM_MAGIC_NUMBER)
            && (iv_v3_headerInfo.v3_hw_hdr.version == ROM_V3_VERSION)
            && (iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.version == ROM_V3_VERSION)
            && (iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.hash_alg == ROM_V3_HASH_ALG)
            && (iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.sig_alg == ROM_V3_SIG_ALG)
            && (iv_v3_headerInfo.v3_hw_prefix_hdr.sw_key_count == V3_SW_KEY_COUNT)
            && (iv_v3_headerInfo.v3_sw_hdr.payload_size_protected != 0);

        if (iv_isValid == false)
        {
            // Setup local variables for common error log below
            l_magic_number = iv_v3_headerInfo.v3_hw_hdr.magic_number;
            l_version = iv_v3_headerInfo.v3_hw_hdr.version;
            l_version_alg = iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.version;
            l_hash_alg = iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.hash_alg;
            l_sig_alg = iv_v3_headerInfo.v3_hw_prefix_hdr.ver_alg.sig_alg;
            l_sw_key_count = iv_v3_headerInfo.v3_hw_prefix_hdr.sw_key_count;
        }
    }

    if(!iv_isValid)
    {
        TRACFCOMP(g_trac_secure,ERR_MRK"ContainerHeader::validate() failed weak header verification (iv_isV3=%d)", iv_isV3);
        /*@
         * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        SECUREBOOT::MOD_SECURE_CONT_VALIDATE
         * @reasoncode      SECUREBOOT::RC_CONT_HDR_INVALID
         * @userdata1[0::31]  Magic Number
         * @userdata1[32::63] ROM version
         * @userdata2[0:15]   Algorithm version
         * @userdata2[16:31]  Hash algorithm
         * @userdata2[32:47]  Signature algorithm
         * @userdata2[48:63]  SW key count
         * @devdesc         Error parsing secure header
         * @custdesc        Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            SECUREBOOT::MOD_SECURE_CONT_VALIDATE,
            SECUREBOOT::RC_CONT_HDR_INVALID,
            TWO_UINT32_TO_UINT64(l_magic_number,
                                 l_version),
            FOUR_UINT16_TO_UINT64(l_version_alg,
                                  l_hash_alg,
                                  l_sig_alg,
                                  l_sw_key_count),
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }

    return l_errl;
}

errlHndl_t ContainerHeader::validateEcidCount(
    const ECID_COUNT_FIELD i_ecidCountField,
    const uint8_t          i_ecidCount) const
{
    errlHndl_t pError = nullptr;
    if(i_ecidCount)
    {
        TRACFCOMP(g_trac_secure,ERR_MRK "ContainerHeader::validateEcidCount: "
            "Secure header validation error; ECID count field of type 0x%02X "
            "must be 0x00, but is actually 0x%02X.",
            i_ecidCountField,i_ecidCount);

        /*@
         * @errortype   ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    SECUREBOOT::MOD_SECURE_VALIDATE_ECID_COUNT
         * @reasoncode  SECUREBOOT::RC_INVALID_ECID_COUNT
         * @userdata1   ECID count field type
         * @userdata2   Actual ECID count
         * @devdesc     Error parsing secure header; ECID count field of
         *     specified type was non-zero.  Reinstall boot firmware.
         * @custdesc    Boot firmware integrity issue; Reinstall boot
         *     firmware.
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            SECUREBOOT::MOD_SECURE_VALIDATE_ECID_COUNT,
            SECUREBOOT::RC_INVALID_ECID_COUNT,
            static_cast<uint64_t>(i_ecidCountField),
            i_ecidCount,
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        pError->collectTrace(SECURE_COMP_NAME);
        pError->collectTrace(PNOR_COMP_NAME);
        pError->collectTrace(TRBOOT_COMP_NAME);
    }
    return pError;
}

errlHndl_t ContainerHeader::safeMemCpyAndInc(
          void*     i_dest,
    const uint8_t*& io_hdr,
    const size_t    i_size,
    const size_t    i_maxSize)
{
    assert(i_dest != nullptr, "ContainerHeader: dest nullptr");
    assert(io_hdr != nullptr, "ContainerHeader: current header location nullptr");
    assert(iv_pHdrStart != nullptr, "ContainerHeader: start of header nullptr");

    const size_t l_maxHeaderSize = (iv_isV3) ? V3_SECURE_HEADER_SIZE // V3
                                             : MAX_SECURE_HEADER_SIZE; //V1

    TRACDCOMP(g_trac_secure,
              "dest: %p, src: %p, size: 0x%016llX, max: 0x%016llX",
              i_dest, io_hdr, i_size, i_maxSize);
    errlHndl_t l_errl = nullptr;

    do {

    // Determine if the memcpy is within the bounds of the container header and
    // does not exceed the maximum allowed transaction size
    iv_hdrBytesRead = io_hdr - iv_pHdrStart;
    if(   ((iv_hdrBytesRead + i_size) > l_maxHeaderSize)
       || (i_size > i_maxSize) )
    {
        TRACFCOMP(g_trac_secure,ERR_MRK"ContainerHeader::safeMemCpyAndInc: "
                  "Secure header validation error; requested copy of size "
                  "0x%016llX starting at offset 0x%016llX would exceed either "
                  "container header size of 0x%016llX or max transaction size "
                  "of 0x%016llX.",
                  i_size, iv_hdrBytesRead, l_maxHeaderSize,
                  i_maxSize);

        // Note: in the FFDC below, for every 64 bit size value, intentionally
        // clip off the upper 32 bits in order to fit more FFDC variables.  The
        // chance of any size requiring 64 bits is extremely low.

        /*@
         * @errortype        ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         SECUREBOOT::MOD_SECURE_CONT_HDR_CPY_INC
         * @reasoncode       SECUREBOOT::RC_CONT_HDR_NO_SPACE
         * @userdata1[00:31] Total bytes read so far
         * @userdata1[32:63] Requested size to copy
         * @userdata2[00:31] Max header size
         * @userdata2[32:63] Max transaction size
         * @devdesc          Error parsing secure header; requested copy size
         *     starting at current offset would exceed the header size or the
         *     max transaction size.  Reinstall boot firmware.
         * @custdesc         Boot firmware integrity issue; Reinstall boot
         *     firmware.
         */
        l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            SECUREBOOT::MOD_SECURE_CONT_HDR_CPY_INC,
            SECUREBOOT::RC_CONT_HDR_NO_SPACE,
            TWO_UINT32_TO_UINT64(iv_hdrBytesRead,i_size),
            TWO_UINT32_TO_UINT64(l_maxHeaderSize,i_maxSize),
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
        break;
    }

    memcpy(i_dest, io_hdr, i_size);
    io_hdr += i_size;

    } while(0);

    return l_errl;
}

bool ContainerHeader::isValid() const
{
    // Same for V1 and V3
    return iv_isValid;
}

bool ContainerHeader::isV3() const
{
    return iv_isV3;
}


const char* ContainerHeader::componentId() const
{
    // Same for V1 and V3
    return iv_componentId;
}

const uint8_t ContainerHeader::secureVersion() const
{
    return (iv_isV3 == true) ? iv_v3_headerInfo.v3_sw_hdr.fw_secure_version // V3
                             : iv_headerInfo.sw_hdr.fw_secure_version; // V1
}

void ContainerHeader::parseFlags()
{
    if (iv_isV3 == false)
    {
        // V1 support
        iv_sbFlags.hw_hb_fw = iv_headerInfo.hw_prefix_hdr.flags & HB_FW_FLAG;
        iv_sbFlags.hw_opal = iv_headerInfo.hw_prefix_hdr.flags & OPAL_FLAG;
        iv_sbFlags.hw_phyp = iv_headerInfo.hw_prefix_hdr.flags & PHYP_FLAG;
        iv_sbFlags.hw_lab_override =(  iv_headerInfo.hw_prefix_hdr.flags
                                     & LAB_OVERRIDE_FLAG);
        iv_sbFlags.hw_key_transition =(  iv_headerInfo.hw_prefix_hdr.flags
                                       & KEY_TRANSITION_FLAG);
        iv_sbFlags.sw_hash = iv_headerInfo.sw_hdr.flags & HASH_PAGE_TABLE_FLAG;
    }
    else
    {
        // V3 support
        iv_sbFlags.hw_hb_fw = iv_v3_headerInfo.v3_hw_prefix_hdr.flags & HB_FW_FLAG;
        iv_sbFlags.hw_opal = iv_v3_headerInfo.v3_hw_prefix_hdr.flags & OPAL_FLAG;
        iv_sbFlags.hw_phyp = iv_v3_headerInfo.v3_hw_prefix_hdr.flags & PHYP_FLAG;
        iv_sbFlags.hw_lab_override =(iv_v3_headerInfo.v3_hw_prefix_hdr.flags
                                     & LAB_OVERRIDE_FLAG);
        iv_sbFlags.hw_key_transition =(iv_v3_headerInfo.v3_hw_prefix_hdr.flags
                                       & KEY_TRANSITION_FLAG);
        iv_sbFlags.sw_hash = iv_v3_headerInfo.v3_sw_hdr.flags & HASH_PAGE_TABLE_FLAG;
    }

}

#ifndef __HOSTBOOT_RUNTIME
void ContainerHeader::genHwKeyHash()
{
    // @TODO JIRA:PFHB-680 Update SECUREBOOT::hashBlob for V3 hash algorithm

    // Generate and store hw hash key
    SECUREBOOT::hashBlob(&iv_headerInfo.hw_hdr.hw_pkey_a,
                         totalHwKeysSize, iv_hwKeyHash);

    TRACDBIN(g_trac_secure, "ContainerHeader::genHwKeyHash:",
             iv_hwKeyHash, sizeof(iv_hwKeyHash));
}
#endif

const uint8_t* ContainerHeader::fakeHeader() const
{
    assert(iv_fakeHeader.data() != nullptr, "Fake header should not be nullptr");
    return iv_fakeHeader.data();
}

errlHndl_t ContainerHeader::setHeader(const void* i_header)
{
    assert(i_header != nullptr, "Cannot set header to nullptr");
    iv_pHdrStart = reinterpret_cast<const uint8_t*>(i_header);
    initVars();
    return parse_header();
}


errlHndl_t ContainerHeader::setFakeHeader(const size_t i_totalSize,
                                          const char* i_compId)
{
    initVars();
    genFakeHeader(i_totalSize, i_compId);
    return parse_header();
}


}; //end of SECUREBOOT namespace
