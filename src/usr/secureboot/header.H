/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/header.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

/** @file header.H
 *
 *  @brief Classes for manipulating Secureboot headers.
 */

namespace SECUREBOOT
{
    /** @class Header
     *  @brief Class for storing the original Secureboot header for later use.
     */
    class Header
    {
        public:
            Header() : iv_data(NULL) {};
            ~Header() {};

            /** @brief Extract header from original HRMOR - 1 page address. */
            void loadBaseHeader();

        private:
            /** Copy of the original secureboot header for the base image. */
            void* iv_data;
    };
};

#endif
