/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/header.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#ifndef __SECUREBOOT_HEADER_H
#define __SECUREBOOT_HEADER_H

#include <stdint.h>
#include <pnor/pnorif.H>
#include <util/singleton.H>

/** @file header.H
 *
 *  @brief Class for manipulating the base image (HBB) secureboot header.
 */
namespace SECUREBOOT
{
    /** @class Header
     *  @brief Class for storing the base image (HBB) header for later use.
     */
    class Header
    {
        public:
            /**
             *  @brief Build a base image (HBB) header object
             */
            Header()
             : iv_data(NULL)
            {
            }

            /**
             *  @brief Destroy a base image (HBB) header object, including any
             *      cached header page
             */
            ~Header()
            {
                free(const_cast<void*>(iv_data));
                iv_data=NULL;
            }

            /**
             *  @brief Extracts base image (HBB) header (ECC removed) from
             *      area preserved across the bootloader to HBB handoff to
             *      support extending HBB measurements to TPM
             *
             *  @warning Asserts if header is already cached (code bug)
             */
            void loadHeader();

            /**
             *  @brief Return pointer to base image (HBB) header.
             *
             *  @par Detailed Description:
             *     During boot, SBE copies the boot loader (HBBL) into the cache
             *     and hands off control to it.  The boot loader then loads the
             *     base image (HBB), including its secure header.  After
             *     verifying HBB, the boot loader copies hostboot to the trusted
             *     memory location and passes control to HBB, which locates and
             *     preserves the secure header (among other things) before
             *     initializing the other non-preserved areas of the cache.  In
             *     secure mode, HBB then initializes this header object with the
             *     preserved secure header.
             *
             *     In non-secure mode, Hostboot pulls the header from PNOR and
             *     and writes it into this object.
             *
             *     This API then returns the addresses of the cached header.
             *
             *  @param[out] o_pHeader Pointer to HBB header
             *
             *  @warning Asserts if HBB header not loaded (code bug)
             */
            void getHeader(
                const void*& o_pHeader) const;

        private:

            /**
             *  @brief Populate the base image (HBB) header (ECC removed)
             *      to support extending HBB measurements to TPM
             *
             *  @param[in] i_pHeader Pointer to 4k HBB header
             *
             *  @warning Asserts if input pointer is NULL (code bug)
             *  @warning Asserts if header already cached (code bug)
             *  @warning Memory violation if buffer data is less than 4k in size
             *      (code bug)
             *  @warning Ignores buffer data beyond 4k in size
             */
            void _set(
                const void* i_pHeader);

            // Pointer to copy of the base image's (HBB's) secureboot header
            const void* iv_data;

            // Don't allow copies / assignments
            Header(const Header& that);
            Header& operator=(const Header&);
    };

    /**
     *  @brief Returns the base image (HBB) header singleton
     *
     *  @return Header Reference to base image (HBB) header object
     */
    Header& baseHeader();

};

#endif
