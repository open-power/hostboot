/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/containerheader.H $                */
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
#ifndef __SECUREBOOT_CONTAINER_HEADER_H
#define __SECUREBOOT_CONTAINER_HEADER_H

#include <errl/errlentry.H>
#include <secureboot/service.H>
#include <securerom/ROM.H>
#include <limits.h>
#include <array>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <initservice/initserviceif.H>

// Forward Declaration
class SecureRomManagerTest;

namespace SECUREBOOT
{

/** @class ContainerHeader
 *  @brief Class for parsing secureboot container headers.
 */
class ContainerHeader
{
    public:

        /**
         *  @brief Enum specifying a specific ECID count field from the secure
         *      header
         */
        enum class ECID_COUNT_FIELD : uint8_t
        {
            HW_HEADER = 0x00, // ECID count field in the HW header
            FW_HEADER = 0x01, // ECID count field in the FW header
        };

        /**
         * @brief Default Constructor
         */
        ContainerHeader():
            iv_headerInfo{}, iv_v3_headerInfo{}, iv_componentId{}, iv_isValid(false),
            iv_pHdrStart(nullptr), iv_hdrBytesRead(0), iv_totalFwKeysSize(0),
            iv_sbFlags{}, iv_hwKeyHash{}, iv_isV3(false), iv_fakeHeader{}
        {}

        /**
         * @brief Sets Container header from virtual address provided and parses
         *        to set values accordingly so they can be retrieved later.
         *
         * @param[in] i_header  virtual address pointing to a secure container
         *                      header to parse.
         *                      nullptr input will assert
         * @return Error handle if error; otherwise nullptr
         */
        errlHndl_t setHeader(const void* i_header);

        /**
         * @brief  Same as setHeader(), but generates a fake header from
         *         minimal input and then parses the header
         *
         * @param[in] i_totalSize   Total Container Size
         * @param[in] i_compId      Component ID
         *
         * @return Error handle if error; otherwise nullptr
         */
        errlHndl_t setFakeHeader(const size_t i_totalSize,
                                 const char* i_compId);

        /**
         * @brief Initialize internal variables
         */
        void initVars();

        /**
         * @brief Destructor
         */
        ~ContainerHeader(){}

        /**
         * @brief Retrieves total container size (includes header, payload text,
         *     and payload data sizes)
         * @return size_t - Total container size in bytes
         */
        size_t totalContainerSize() const;

        /**
         * @brief Retrieves the prefix header flags
         *
         * @return uint32_t containing prefix header flags
         */
        uint32_t prefixHeaderFlags() const;

        /**
         * @brief Retrieves pointer to first hw key
         * @return ecc_key_t* - ptr to first hw key
         */
        const ecc_key_t* hw_keys() const;

        /**
         * @brief Total size of all hw keys concatenated
         *        One value for V1 container headers; one value for
         *        V3 container headers.
         */
        // V1
        static const size_t totalHwKeysSize = HW_KEY_COUNT*sizeof(ecc_key_t);
        // V3
        static const size_t v3_totalHwKeysSize = sizeof(ecc_key_t) // hw_pkey_a;
                                                 + sizeof(mldsa_pub_key_t); // hw_pkey_d;

        /**
         * @brief Retrieves payload text size
         * @return size_t - size of payload text size
         */
        size_t payloadTextSize() const;

        /**
         * @brief Retrieves payload text hash
         * @return SHA512_t* - ptr to hash of payload text
         */
        const SHA512_t* payloadTextHash() const;

        /**
         * @brief Retrieves total size of all fw keys concatenated
         * @return size_t - size of concatenated fw keys
         */
        size_t totalFwKeysSize() const;

        /**
         * @brief Retrieves fw public key hash
         * @return SHA512_t* - ptr to hash of fw public keys
         */
        const SHA512_t* fwKeyHash() const;

        /**
         * @brief Retrieves pointer to first fw key
         * @return ecc_key_t* - ptr to first fw key
         */
        const ecc_key_t* fw_keys() const;

        /**
         * @brief Retrieves pointer to first fw signature
         * @return ecc_key_t* - ptr to first fw signature
         */
        const ecc_key_t* fw_sigs() const;

        /**
         * @brief Retrieves pointer to sb flag struct holding all hw and sw
         *        flags set when parsing the header.
         * @return sb_flags_t - hw and fw flag struct
         */
        const sb_flags_t* sb_flags() const;

        /**
         * @brief Retrieves hw public key hash from the container
         * @return SHA512_t* - ptr to hash of hw public keys
         */
        const SHA512_t* hwKeyHash() const;

        /**
         * @brief Returns if the parsed header is a valid secureboot one. This
         *        is a temporary, non-secure way of pragmatically determining
         *        if secureboot signing was supported. Eventually it will always
         *        happen
         * @return bool - whether or not the container is a valid secureboot
         */
        bool isValid() const;

        /**
         *  @brief Returns the container's component ID as an invariant
         *      character string, or an empty string if none provided.
         *
         *  @return const char* Component ID string
         */
        const char* componentId() const;

        /**
         *  @brief Returns the container's fake header
         *
         *  @return const uint8_t* fake header
         */
        const uint8_t* fakeHeader() const;

        /**
         *  @brief Returns the container's secure version
         *
         *  @return const uint8_t secure version
         */
        const uint8_t secureVersion() const;

        /**
         *  @brief Returns if the container is a V3 container (true)
         *         or a V1 container(false)
         *
         *  @return bool - whether or not the container is a V3 container
         */
        bool isV3() const;

    private:

        /**
         *  @brief Complete V1 container header structure based on
         *         ROM structures
         */
        struct SecureHeaderInfo
        {
            ROM_container_raw hw_hdr;
            ROM_prefix_header_raw hw_prefix_hdr;
            ROM_prefix_data_raw hw_prefix_data;
            ROM_fw_header_raw fw_hdr;
            ROM_fw_sig_raw fw_sig;
        };

        // Entire cached V1 container header content
        SecureHeaderInfo iv_headerInfo;


        /**
         *  @brief Complete V3 container header structure based on
         *         ROM structures
         */
        struct V3_SecureHeaderInfo
        {
            ROM_v3_container_raw v3_hw_hdr;
            ROM_v3_prefix_header_raw v3_hw_prefix_hdr;
            ROM_v3_prefix_data_raw v3_hw_prefix_data;
            ROM_v3_fw_header_raw v3_fw_hdr;
            ROM_v3_fw_sig_raw v3_fw_sig;
        };

        // entire cached V3 container header content
        V3_SecureHeaderInfo iv_v3_headerInfo;

        /**
         *  @brief Common Header between V1 ROM_container_raw and
         *         V3 ROM_v3_container_raw. See src/include/securerom/ROM.H
         *         for details
         */
        ROM_common_container_fields iv_commonRawHdr;

        /**
         *  @brief Container's component ID (one byte larger than associated
         *      container header field to allow for a NULL terminator)
         *
         *  @note this is the same size for V1 and V3; confirmed with
         *        static_assert check below
         */
        char iv_componentId[  sizeof(ROM_fw_header_raw::component_id)
                            + sizeof(uint8_t) ];
        static_assert(sizeof(ROM_fw_header_raw::component_id) ==
                      sizeof(ROM_v3_fw_header_raw::component_id),
                      "V1 and V3 component_id sizes do not match!");

        // Indicates if container header is a valid, in a very loose sense,
        // secureboot header.
        bool iv_isValid;

        // Pointer to the start of the container header
        const uint8_t* iv_pHdrStart;

        // Counter for bytes read while parsing the container header
        // Set in safeMemCpyAndInc()
        size_t iv_hdrBytesRead;

        // Total size of all software keys concatenated
        size_t iv_totalFwKeysSize;

        // Struct to hold all hw and fw flags set
        sb_flags_t iv_sbFlags;

        // HW keys' hash for current container.
        SHA512_t iv_hwKeyHash;

        // While V1 uses SHA512_t for the HW Keys' Hash type, V3 uses sha3_t.
        // The size for both is the same (64 bytes), and the logic in
        // containerheader.H/C assumes that.  So do a static_assert to catch if
        // something ever changes.
        static_assert(sizeof(SHA512_t) == sizeof(sha3_t),
                      "sizeof(SHA512_t) and sizeof(sha3_t) differ!");
        static_assert(SHA512_DIGEST_LENGTH == SHA3_DIGEST_LENGTH,
                      "SHA512_DIGEST_LENGTH and SHA3_DIGEST_LENGTH differ!");
        static_assert(sizeof(SHA512_t) == SHA3_DIGEST_LENGTH,
                      "sizeof(SHA512_t) and SHA3_DIGEST_LENGTH differ!");

        // Indicates if container header is for a V3 container (true) or
        // for a V1 header (false)
        bool iv_isV3;

        /**
         * @brief Determines what flags are set based on the hw and fw flag bit
         *        fields in the container header.
         *        Also sets iv_sbFlags private member
         */
        void parseFlags();

        /**
         * @brief Generate and store hw key hash. Concatenate all hw public keys
         *        and then take sha512 hash.
         *        Also sets iv_hwKeyHash private member
         */
#ifndef __HOSTBOOT_RUNTIME
        void genHwKeyHash();
#endif

        /**
         * @brief Weak check to determine if secureboot header looks right.
         *        Also sets iv_isValid private member
         * @return Error handle if error; otherwise nullptr
         */
        errlHndl_t validate();

        /**
         * @brief Print out useful sections of the container header
         */
        void print() const;

        /**
         * @brief parse_header Blob
         *
         * Parses a secure container header defined by ROM structures and set
         * internal header structure.
         * Note: nullptr header will assert
         *
         * @return Error handle if error; otherwise nullptr
         */
        errlHndl_t parse_header();

        /**
         *  @brief Validate that the specified ECID count field from the secure
         *      header is 0
         *
         *  @param[in] i_ecidCountField Indicates which secure header ECID count
         *      field (HW header or FW header) should be validated
         *  @param[in] i_ecidCount The actual value of the ECID count field
         *
         *  @return errlHndl_t Error log handle indicating success or failure
         *  @retval nullptr    Success; the ECID count field is 0 (and valid)
         *  @retval !nullptr   Error; the ECID count field had a value other
         *      than 0 and the error log handle points to a valid error log
         */
        errlHndl_t validateEcidCount(
            const ECID_COUNT_FIELD i_ecidCountField,
            const uint8_t          i_ecidCount) const;

        /**
         * @brief Checks bounds of parsing before mempy and increments pointer
         *
         * Ensures that we don't memcpy more bytes than the max size of a
         * secure container header (will check iv_isV3 to use the proper
         * header size).  Optionally ensures that the requested copy does not
         * exceed a supplied maximum transaction size, in order to prevent
         * dynamically sized data area overruns.  Error log created on any
         * violation of the above constraints.
         *
         * @param[in] i_dest    Pointer to the memory location to copy to
         *                      nullptr input will assert
         * @param[in] io_hdr    Pointer to current location of container header
         *                      nullptr input will assert
         * @param[in] i_size    Number of bytes to copy
         * @param[in] i_maxSize Maximum transaction size in bytes for this
         *                      single copy.  Default is V1 secure header size,
         *                      but can pass in V3_SECURE_HEADER_SIZE for V3
         *                      headers
         *
         * @return Error handle if error; otherwise nullptr
         */
        errlHndl_t safeMemCpyAndInc(
                   void*     i_dest,
            const  uint8_t*& io_hdr,
                   size_t    i_size,
                   size_t    i_maxSize=MAX_SECURE_HEADER_SIZE);

        // Pointer to fake header generated
        std::array<uint8_t,PAGE_SIZE> iv_fakeHeader;

        /**
         * @brief Generate fake V1 container header with minimal information
         *        and stores in instance variable.
         *
         * @note  This does not support V3 container headers
         *
         * @param[in] i_size        Size of content to add header to
         * @param[in] i_compId      Component ID
         */
        void genFakeHeader(const size_t i_size,
                           const char* const i_compId);

        friend class ::SecureRomManagerTest;
};

}; //end of SECUREBOOT namespace

#endif
