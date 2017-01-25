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
                free(iv_data);
                iv_data=NULL;
            }

            // @TODO RTC 168021 Converge to single method of reading
            // secure header

            /**
             *  @brief Extracts base image (HBB) header (ECC removed) from
             *      HBB secure load address (HRMOR - 4k) to support extending
             *      HBB measurements to TPM in secure mode.
             *
             *  @warning Asserts if header is already cached (code bug)
             */
            void loadSecurely();

            // @TODO RTC 168021 Converge to single method of reading
            // secure header

            /**
             *  @brief Caches non-secure PNOR copy of the base image (HBB)
             *      header (ECC removed) to support extending HBB measurements
             *      to TPM in non-secure mode.
             *
             *  @param[in] i_pHeader Pointer to non-secure 4k HBB header
             *      extracted from PNOR.
             *
             *  @warning Asserts if input pointer is NULL (code bug)
             *  @warning Asserts if header already cached (code bug)
             *  @warning Memory violation if buffer data is less than 4k in size
             *      (code bug)
             *  @warning Ignores buffer data beyond 4k in size
             */
            void setNonSecurely(
                const void* i_pHeader);

            /**
             *  @brief Return pointer to base image (HBB) header.
             *
             *  @par Detailed Description:
             *     When SBE first loads Hostboot, if system is in secure mode,
             *     it copies the HBB code to the HRMOR address (aka the secure
             *     load address) and puts the HBB header 4k in front of it.  In
             *     non-secure mode, SBE only loads the HBB code to the HRMOR and
             *     discards the header, leaving no trace of it in memory.  When
             *     HBB gets control, if in secure mode, it copies its own header
             *     from HRMOR-4k and caches it in this object.  Otherwise, if
             *     not in secure mode, it pulls the header from PNOR and writes
             *     it into this object.  This API then returns the addresses of
             *     the cached header.
             *
             *  @param[out] o_pHeader Pointer to HBB header
             *
             *  @warning Asserts if HBB header not loaded (code bug)
             */
            void getHeader(
                const void*& o_pHeader) const;

        private:

            /**
             *  @brief Returns base (HBB) image secure load address (the address
             *      where SBE -always- loads hostboot regardless of security
             *      state)
             *
             *  @param[out] o_pCode Base (HBB) image secure load address
             */
            void _calcSecureLoadAddr(
                const void*& o_pCode) const;

            // Pointer to copy of the base image's (HBB's) secureboot header
            void* iv_data;

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
