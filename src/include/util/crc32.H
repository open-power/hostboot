/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/crc32.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#ifndef __UTIL_CRC32_H
#define __UTIL_CRC32_H


namespace Util
{
    const uint8_t CRC32_HASH_SIZE = sizeof(uint32_t);

    /**
     * @brief Creates a 4-byte Cyclic Redundancy Check (CRC) on the data
     *        provided
     *
     * @param[in] ptr          Pointer to the data
     *
     * @param[in] size         Size of the data
     *
     * @return uint32_t        4-byte CRC
     */
    uint32_t crc32_calc(const void* ptr, size_t size);
};

#endif

