/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_ppe_cache.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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

///
/// @file io_ppe_cache.H
/// @brief Cache utility class
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#pragma once

#define IO_PPE_MAX_CACHE_SIZE 128

class io_ppe_cache
{
    private:
        int iv_size;
        int iv_head;
        uint64_t iv_address[IO_PPE_MAX_CACHE_SIZE];
        uint64_t iv_data[IO_PPE_MAX_CACHE_SIZE];
        uint8_t iv_modified[IO_PPE_MAX_CACHE_SIZE];

    public:
        io_ppe_cache();
        bool hasAddress(uint64_t i_addr);
        uint64_t getData(uint64_t i_addr);
        bool add(uint64_t i_addr, uint64_t i_data, uint8_t i_modified);
        bool pop(uint64_t& o_addr, uint64_t& o_data, uint8_t& o_modified);
};
