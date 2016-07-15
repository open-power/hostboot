/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/containerheader.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <secureboot/rom.H>

// Forward Declaration
class SecureROMTest;

namespace SECUREBOOT
{

/** @class ContainerHeader
 *  @brief Class for parsing secureboot container headers.
 */
class ContainerHeader
{
    public:

        /**
         * @brief ContainerHeader
         *
         * This constructor parses the input container header and sets values
         * accordingly so they can be retrieved later.
         *
         * @param[in] i_header  Secure container header to parse.
         *                      NULL input will assert
         */
        ContainerHeader(const void* i_header):
            iv_isValid(false),iv_hdrBytesRead(0)
        {
            assert(i_header != NULL);
            iv_pHdrStart = reinterpret_cast<const uint8_t*>(i_header);
            memset(&iv_headerInfo, 0x00, sizeof(iv_headerInfo));
            parse_header(i_header);
        };

        /**
         * @brief Destructor
         */
        ~ContainerHeader(){};

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

        // @TODO RTC: 155374 remove, SecureROMTest will use iv_isValid.
        /**
         * @brief Returns if the parsed header is a valid secureboot one. This
         *        is a temporary, non-secure way of pragmatically determining
         *        if secureboot signing was supported. Eventually it will always
         *        happen
         * @return bool - whether or not the container is a valid secureboot
         */
        bool isValid() const;

    private:
        /**
         * @brief Default Constructor in private to prevent being instantiated
         *        by non friend/children derivatives.
         */
        ContainerHeader(){};

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

        /**
         * @brief Weak check to determine if secureboot header looks right.
         *        Also sets iv_isValid private member
         */
        void validate();

        /**
         * @brief Print out useful sections of the container header
         */
        void print() const;

        /**
         * @brief parse_header Blob
         *
         * Parses a secure container header defined by ROM structures and set
         * internal header structure.
         *
         * @param[in] i_containerHdr    Secure container header to parse
         *                              NULL input will assert
         */
        void parse_header(const void* i_header);

        /**
         * @brief Checks bounds of parsing before mempy and increments pointer
         *
         * Ensures that we don't memcpy more bytes than the max size of a
         * secure container header. Asserts on out of bounds memcpy.
         *
         * @param[in] i_dest   Pointer to the memory location to copy to
         *                     NULL input will assert
         * @param[in] io_hdr   Pointer to current location of container header
         *                     NULL input will assert
         * @param[in] i_size   Number of bytes to copy
         */
        void safeMemCpyAndInc(void* i_dest, const uint8_t* &io_hdr,
                              const size_t i_size);

        friend class ::SecureROMTest;
};

}; //end of SECUREBOOT namespace

#endif
