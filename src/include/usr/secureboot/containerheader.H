/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/containerheader.H $                */
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
            SW_HEADER = 0x01, // ECID count field in the SW header
        };

        /**
         * @brief Default Constructor
         */
        ContainerHeader():
            iv_componentId{}, iv_headerInfo{}, iv_isValid(false),
            iv_pHdrStart(nullptr), iv_hdrBytesRead(0), iv_totalSwKeysSize(0),
            iv_sbFlags{}, iv_hwKeyHash{}, iv_fakeHeader{}
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
         */
        static const size_t totalHwKeysSize = HW_KEY_COUNT*sizeof(ecc_key_t);

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
         * @brief Retrieves total size of all sw keys concatenated
         * @return size_t - size of concatenated sw keys
         */
        size_t totalSwKeysSize() const;

        /**
         * @brief Retrieves sw public key hash
         * @return SHA512_t* - ptr to hash of sw public keys
         */
        const SHA512_t* swKeyHash() const;

        /**
         * @brief Retrieves pointer to first sw key
         * @return ecc_key_t* - ptr to first sw key
         */
        const ecc_key_t* sw_keys() const;

        /**
         * @brief Retrieves pointer to first sw signature
         * @return ecc_key_t* - ptr to first sw signature
         */
        const ecc_key_t* sw_sigs() const;

        /**
         * @brief Retrieves pointer to sb flag struct holding all hw and sw
         *        flags set when parsing the header.
         * @return sb_flags_t - hw and sw flag struct
         */
        const sb_flags_t* sb_flags() const;

        /**
         * @brief Retrieves hw public key hash
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

    private:

        /**
         *  @brief Complete container header structure based on ROM structures
         */
        struct SecureHeaderInfo
        {
            ROM_container_raw hw_hdr;
            ROM_prefix_header_raw hw_prefix_hdr;
            ROM_prefix_data_raw hw_prefix_data;
            ROM_sw_header_raw sw_hdr;
            ROM_sw_sig_raw sw_sig;
        };

        /**
         *  @brief Container's component ID (one byte larger than associated
         *      container header field to allow for a NULL terminator)
         */
        char iv_componentId[  sizeof(ROM_sw_header_raw::component_id)
                            + sizeof(uint8_t) ];

        // Entire cached container header content
        SecureHeaderInfo iv_headerInfo;

        // Indicates if container header is a valid, in a very loose sense,
        // secureboot header.
        bool iv_isValid;

        // Pointer to the start of the container header
        const uint8_t* iv_pHdrStart;

        // Counter for bytes read while parsing the container header
        size_t iv_hdrBytesRead;

        // Total size of all software keys concatenated
        size_t iv_totalSwKeysSize;

        // Struct to hold all hw and sw flags set
        sb_flags_t iv_sbFlags;

        // HW keys' hash for current container.
        SHA512_t iv_hwKeyHash;

        /**
         * @brief Determines what flags are set based on the hw and sw flag bit
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
         *      field (HW header or SW header) should be validated
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
         * secure container header.  Optionally ensures that the requested copy
         * does not exceed a supplied maximum size, in order to prevent
         * dynamically sized data area overruns.  Error log created on any
         * violation of the above constraints.
         *
         * @param[in] i_dest    Pointer to the memory location to copy to
         *                      nullptr input will assert
         * @param[in] io_hdr    Pointer to current location of container header
         *                      nullptr input will assert
         * @param[in] i_size    Number of bytes to copy
         * @param[in] i_maxSize Maximum transaction size in bytes for this
         *     single copy.  Default=secure header size.
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
         * @brief Generate fake header with minimal information and stores in
         *        instance variable
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
