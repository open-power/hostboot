/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/common/containerheader.C $                 */
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
    const uint8_t* l_hdr = reinterpret_cast<const uint8_t*>(iv_pHdrStart);

    errlHndl_t l_errl = nullptr;

    do {
    /*---- Parse ROM_container_raw ----*/
    // The rom code has a placeholder for the prefix in the first struct
    size_t l_size = offsetof(ROM_container_raw, prefix);
    l_errl = safeMemCpyAndInc(&iv_headerInfo.hw_hdr, l_hdr, l_size);
    if(l_errl)
    {
        break;
    }

    // Early check if magic number is valid, as a quick check to try and prevent
    // any storage exceptions while parsing header.
    if(iv_headerInfo.hw_hdr.magic_number != ROM_MAGIC_NUMBER)
    {
        TRACFCOMP(g_trac_secure,ERR_MRK"ContainerHeader::parse_header() Magic Number = 0x%X not valid to parse Container Header",
                  iv_headerInfo.hw_hdr.magic_number);

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
                        iv_headerInfo.hw_hdr.magic_number,
                        ROM_MAGIC_NUMBER,
                        true/*SW Error*/);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
        break;
    }

    /*---- Parse ROM_prefix_header_raw ----*/
    l_size = offsetof(ROM_prefix_header_raw, ecid);
    l_errl = safeMemCpyAndInc(&iv_headerInfo.hw_prefix_hdr, l_hdr, l_size);
    if(l_errl)
    {
        break;
    }

    // Get ECID array
    l_size = iv_headerInfo.hw_prefix_hdr.ecid_count * ECID_SIZE;
    l_errl = safeMemCpyAndInc(&iv_headerInfo.hw_prefix_hdr.ecid, l_hdr, l_size);
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
    l_errl = safeMemCpyAndInc(&iv_headerInfo.hw_prefix_data.sw_pkey_p, l_hdr,
                              l_size);
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

    // Get ECID array
    l_size = iv_headerInfo.sw_hdr.ecid_count * ECID_SIZE;
    l_errl = safeMemCpyAndInc(&iv_headerInfo.sw_hdr.ecid, l_hdr, l_size);
    if(l_errl)
    {
        break;
    }

    /*---- Parse ROM_sw_sig_raw ----*/
    l_errl = safeMemCpyAndInc(&iv_headerInfo.sw_sig.sw_sig_p, l_hdr,
                              iv_totalSwKeysSize);
    if(l_errl)
    {
        break;
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

    return l_errl;
}

void ContainerHeader::initVars()
{
    memset(&iv_headerInfo, 0x00, sizeof(iv_headerInfo));
    memset(iv_hwKeyHash, 0, sizeof(SHA512_t));
    memset(iv_componentId,0x00,sizeof(iv_componentId));
}

void ContainerHeader::genFakeHeader(const size_t i_totalSize,
                                    const char* const i_compId)
{
    SecureHeaderInfo info {};
    assert(iv_fakeHeader.data() != nullptr, "Internal fake header buffer nullptr");

    uint8_t* l_hdr = reinterpret_cast<uint8_t*>(iv_fakeHeader.data());

     /*---- ROM_container_raw ----*/
    info.hw_hdr.magic_number = ROM_MAGIC_NUMBER;
    info.hw_hdr.version = CONTAINER_VERSION;
    info.hw_hdr.container_size = i_totalSize;
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
    info.sw_hdr.payload_size = i_totalSize - PAGE_SIZE;

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
    TRACFCOMP(g_trac_secure, ENTER_MRK"ContainerHeader::print");

    TRACFCOMP(g_trac_secure,"header content size 0x%X", iv_hdrBytesRead);

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

    TRACFCOMP(g_trac_secure, EXIT_MRK"ContainerHeader::print");
#endif
}

size_t ContainerHeader::totalContainerSize() const
{
    return iv_headerInfo.hw_hdr.container_size;
}

uint32_t ContainerHeader::prefixHeaderFlags() const
{
    return iv_headerInfo.hw_prefix_hdr.flags;
}

const ecc_key_t* ContainerHeader::hw_keys() const
{
    return &iv_headerInfo.hw_hdr.hw_pkey_a;
}

size_t ContainerHeader::payloadTextSize() const
{
    return iv_headerInfo.sw_hdr.payload_size;
}

const SHA512_t* ContainerHeader::payloadTextHash() const
{
    return &iv_headerInfo.sw_hdr.payload_hash;
}

size_t ContainerHeader::totalSwKeysSize() const
{
    return iv_totalSwKeysSize;
}

const ecc_key_t* ContainerHeader::sw_keys() const
{
    return &iv_headerInfo.hw_prefix_data.sw_pkey_p;
}

const SHA512_t* ContainerHeader::swKeyHash() const
{
    return &iv_headerInfo.hw_prefix_hdr.payload_hash;
}

const ecc_key_t* ContainerHeader::sw_sigs() const
{
    return &iv_headerInfo.sw_sig.sw_sig_p;
}

const sb_flags_t* ContainerHeader::sb_flags() const
{
    return &iv_sbFlags;
}

const SHA512_t* ContainerHeader::hwKeyHash() const
{
    return &iv_hwKeyHash;
}

errlHndl_t ContainerHeader::validate()
{
    errlHndl_t l_errl = nullptr;

    iv_isValid = (iv_hdrBytesRead <= MAX_SECURE_HEADER_SIZE)
        && (iv_headerInfo.hw_hdr.magic_number == ROM_MAGIC_NUMBER)
        && (iv_headerInfo.hw_hdr.version == ROM_VERSION)
        && (iv_headerInfo.hw_prefix_hdr.ver_alg.version == ROM_VERSION)
        && (iv_headerInfo.hw_prefix_hdr.ver_alg.hash_alg == ROM_HASH_ALG)
        && (iv_headerInfo.hw_prefix_hdr.ver_alg.sig_alg == ROM_SIG_ALG)
        && (iv_headerInfo.hw_prefix_hdr.sw_key_count >= SW_KEY_COUNT_MIN)
        && (iv_headerInfo.hw_prefix_hdr.sw_key_count <= SW_KEY_COUNT_MAX)
        && (iv_headerInfo.sw_hdr.payload_size != 0);

    if(!iv_isValid)
    {
        TRACFCOMP(g_trac_secure,ERR_MRK"ContainerHeader::validate() failed weak header verification");
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
            TWO_UINT32_TO_UINT64(iv_headerInfo.hw_hdr.magic_number,
                                 iv_headerInfo.hw_hdr.version),
            FOUR_UINT16_TO_UINT64(iv_headerInfo.hw_prefix_hdr.ver_alg.version,
                                  iv_headerInfo.hw_prefix_hdr.ver_alg.hash_alg,
                                  iv_headerInfo.hw_prefix_hdr.ver_alg.sig_alg,
                                  iv_headerInfo.hw_prefix_hdr.sw_key_count),
            true/*SW Error*/);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }

    return l_errl;
}

errlHndl_t ContainerHeader::safeMemCpyAndInc(void* i_dest, const uint8_t* &io_hdr,
                                       const size_t i_size)
{
    assert(i_dest != nullptr, "ContainerHeader: dest nullptr");
    assert(io_hdr != nullptr, "ContainerHeader: current header location nullptr");
    assert(iv_pHdrStart != nullptr, "ContainerHeader: start of header nullptr");

    TRACDCOMP(g_trac_secure,"dest: 0x%X src: 0x%X size: 0x%X",i_dest, io_hdr, i_size);
    errlHndl_t l_errl = nullptr;

    do {
    // Determine if the memcpy is within the bounds of the container header
    iv_hdrBytesRead = io_hdr - iv_pHdrStart;
    if((iv_hdrBytesRead + i_size) > MAX_SECURE_HEADER_SIZE)
    {
        TRACFCOMP(g_trac_secure,ERR_MRK"ContainerHeader::safeMemCpyAndInc parsed header is out of bounds of max header size of 0x%X",
                  MAX_SECURE_HEADER_SIZE);
        /*@
         * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        SECUREBOOT::MOD_SECURE_CONT_HDR_CPY_INC
         * @reasoncode      SECUREBOOT::RC_CONT_HDR_NO_SPACE
         * @userdata1       Size needed
         * @userdata2       Max secure header size
         * @devdesc         Error parsing secure header
         * @custdesc        Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    SECUREBOOT::MOD_SECURE_CONT_HDR_CPY_INC,
                                    SECUREBOOT::RC_CONT_HDR_NO_SPACE,
                                    iv_hdrBytesRead + i_size,
                                    MAX_SECURE_HEADER_SIZE,
                                    true/*SW Error*/);
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
    return iv_isValid;
}

const char* ContainerHeader::componentId() const
{
    return iv_componentId;
}

void ContainerHeader::parseFlags()
{
    iv_sbFlags.hw_hb_fw = iv_headerInfo.hw_prefix_hdr.flags & HB_FW_FLAG;
    iv_sbFlags.hw_opal = iv_headerInfo.hw_prefix_hdr.flags & OPAL_FLAG;
    iv_sbFlags.hw_phyp = iv_headerInfo.hw_prefix_hdr.flags & PHYP_FLAG;
    iv_sbFlags.hw_lab_override =(  iv_headerInfo.hw_prefix_hdr.flags
                                 & LAB_OVERRIDE_FLAG);
    iv_sbFlags.hw_key_transition =(  iv_headerInfo.hw_prefix_hdr.flags
                                   & KEY_TRANSITION_FLAG);
}

#ifndef __HOSTBOOT_RUNTIME
void ContainerHeader::genHwKeyHash()
{

    // Generate and store hw hash key
    SECUREBOOT::hashBlob(&iv_headerInfo.hw_hdr.hw_pkey_a,
                         totalHwKeysSize, iv_hwKeyHash);

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
