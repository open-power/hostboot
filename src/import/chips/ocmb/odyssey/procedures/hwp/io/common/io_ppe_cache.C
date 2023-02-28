/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_ppe_cache.C $ */
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

/// @file io_ppe_cache.C
/// @brief Cache utility functions
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE

#include <fapi2.H>
#include <io_ppe_cache.H>

io_ppe_cache::io_ppe_cache()
{
    iv_head = 0;
    iv_size = 0;
}

bool io_ppe_cache::hasAddress(uint64_t i_addr)
{
    bool l_found = false;
    int l_idx = iv_head;

    for (int i = 0; i < iv_size && !l_found; i++)
    {
        l_found = iv_address[l_idx] == i_addr;
        l_idx++;

        if (l_idx >= IO_PPE_MAX_CACHE_SIZE)
        {
            l_idx = 0;
        }
    }

    return l_found;
}

uint64_t io_ppe_cache::getData(uint64_t i_addr)
{
    int l_idx = iv_head;

    for (int i = 0; i < iv_size; i++)
    {
        if (iv_address[l_idx] == i_addr)
        {
            return iv_data[l_idx];
        }

        l_idx++;

        if (l_idx >= IO_PPE_MAX_CACHE_SIZE)
        {
            l_idx = 0;
        }
    }

    return 0;
}

bool io_ppe_cache::add(uint64_t i_addr, uint64_t i_data, uint8_t i_modified)
{
    //Look to see if address is already in cache
    int l_idx = iv_head;

    for (int i = 0; i < iv_size; i++)
    {
        if (iv_address[l_idx] == i_addr)
        {
            iv_data[l_idx] = i_data;
            iv_modified[l_idx] = i_modified;
            return true;
        }

        l_idx++;

        if (l_idx >= IO_PPE_MAX_CACHE_SIZE)
        {
            l_idx = 0;
        }
    }

    //Address not already in cache, see if we can add it
    if (iv_size >= IO_PPE_MAX_CACHE_SIZE)
    {
        return false;
    }

    int l_tail = iv_head + iv_size;

    if (l_tail >= IO_PPE_MAX_CACHE_SIZE)
    {
        l_tail -= IO_PPE_MAX_CACHE_SIZE;
    }

    iv_address[l_tail] = i_addr;
    iv_data[l_tail] = i_data;
    iv_modified[l_tail] = i_modified;

    // FAPI_DBG("io_ppe_cache::add: iv_address[%d] 0x%08X%08X", l_tail,
    //          (iv_address[l_tail] >> 32) & 0xFFFFFFFF,
    //          iv_address[l_tail] & 0xFFFFFFFF);
    // FAPI_DBG("io_ppe_cache::add: iv_data[%d] 0x%08X%08X", l_tail,
    //          (iv_data[l_tail] >> 32) & 0xFFFFFFFF,
    //          iv_data[l_tail] & 0xFFFFFFFF);
    // FAPI_DBG("io_ppe_cache::add: iv_modified[%d] 0x%.2X", l_tail, iv_modified[l_tail]);

    iv_size++;
    return true;
}

bool io_ppe_cache::pop(uint64_t& o_addr, uint64_t& o_data, uint8_t& o_modified)
{
    if (iv_size == 0)
    {
        return false;
    }

    o_addr = iv_address[iv_head];
    o_data = iv_data[iv_head];
    o_modified = iv_modified[iv_head];
    //FAPI_DBG("o_addr: %llx o_data: %llx o_modified: %llx", o_addr, o_data, o_modified);
    iv_size--;
    iv_head++;

    if (iv_head >= IO_PPE_MAX_CACHE_SIZE)
    {
        iv_head = 0;
    }

    return true;
}
