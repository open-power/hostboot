/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_ppe_lib.H $ */
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
/// @file io_ppe_lib.H
///
/// @brief Function lib definition file for IO hwps
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#pragma once

#include <fapi2.H>
#include <io_ppe_cache.H>

template<fapi2::TargetType K, fapi2::MulticastType M = fapi2::MULTICAST_OR, typename V = fapi2::plat_target_handle_t>
fapi2::ReturnCode putScomLane(const fapi2::Target<K, M, V>& i_target, const uint64_t i_addr, const uint64_t i_lane,
                              fapi2::buffer<uint64_t> i_data)
{
    uint64_t l_addr = (i_addr & 0xFFFFFFE0FFFFFFFF);
    l_addr |= (i_lane & 0x1F) << 32;
    FAPI_TRY(fapi2::putScom(i_target, l_addr, i_data));
fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M = fapi2::MULTICAST_OR, typename V = fapi2::plat_target_handle_t>
fapi2::ReturnCode getScomLane(const fapi2::Target<K, M, V>& i_target, const uint64_t i_addr, const uint64_t i_lane,
                              fapi2::buffer<uint64_t>& o_data)
{
    uint64_t l_addr = (i_addr & 0xFFFFFFE0FFFFFFFF);
    l_addr |= (i_lane & 0x1F) << 32;
    FAPI_TRY(fapi2::getScom(i_target, l_addr, o_data));
fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M = fapi2::MULTICAST_OR, typename V = fapi2::plat_target_handle_t>
class io_ppe_regs
{
    public:
        const uint64_t csar_scom_addr;
        const uint64_t csdr_scom_addr;
        const uint64_t xcr;

        io_ppe_regs(uint64_t i_csar, uint64_t i_csdr, uint64_t i_xcr) :
            csar_scom_addr(i_csar), csdr_scom_addr(i_csdr), xcr(i_xcr)
        {
#if IO_PPE_MAX_CACHE_SIZE > 0
            FAPI_DBG("io_ppe_regs constructor");

            cache_overflow = false;
#endif
        }

        fapi2::ReturnCode getData(const fapi2::Target<K, M, V>& i_target,
                                  const uint32_t i_section_addr,
                                  const uint32_t i_address,
                                  const uint32_t i_mask,
                                  const uint32_t i_shift,
                                  const uint32_t i_thread,
                                  const uint32_t i_thread_size,
                                  const uint32_t i_lane,
                                  fapi2::buffer<uint64_t>& o_data);

        fapi2::ReturnCode putData(const fapi2::Target<K, M, V>& i_target,
                                  const uint32_t i_section_addr,
                                  const uint32_t i_address,
                                  const uint32_t i_mask,
                                  const uint32_t i_shift,
                                  const uint32_t i_thread,
                                  const uint32_t i_thread_size,
                                  const uint32_t i_lane,
                                  fapi2::buffer<uint64_t> i_data);

        fapi2::ReturnCode flushCache(const fapi2::Target<K, M, V>& i_target);

        fapi2::ReturnCode hardReset(const fapi2::Target<K, M, V>& i_target);

        fapi2::ReturnCode resume(const fapi2::Target<K, M, V>& i_target);

    private:

#if IO_PPE_MAX_CACHE_SIZE > 0

        //TODO: Remove stdlib useage
        io_ppe_cache cache;
        bool cache_overflow;
        fapi2::Target<K, M, V> last_target;
#endif

        uint64_t calcAddress(const uint32_t i_section_addr,
                             const uint32_t i_address,
                             const uint32_t i_thread,
                             const uint32_t i_thread_size,
                             const uint32_t i_lane);

        uint64_t extractData(const uint64_t i_8b_data,
                             const uint32_t i_address,
                             const uint32_t i_mask,
                             const uint32_t i_shift);

        uint64_t updateData(const uint64_t i_8b_data,
                            const uint32_t i_reg_data,
                            const uint32_t i_address,
                            const uint32_t i_mask,
                            const uint32_t i_shift);

#if IO_PPE_MAX_CACHE_SIZE > 0
        fapi2::ReturnCode cacheData(const fapi2::Target<K, M, V>& i_target,
                                    const uint64_t i_address,
                                    const fapi2::buffer<uint64_t> i_data,
                                    const uint8_t i_modified);
#endif

        fapi2::ReturnCode getData(const fapi2::Target<K, M, V>& i_target, const uint64_t i_addr,
                                  fapi2::buffer<uint64_t>& o_data);

        fapi2::ReturnCode putData(const fapi2::Target<K, M, V>& i_target, uint64_t i_addr,
                                  const fapi2::buffer<uint64_t> i_data);

};

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::getData(const fapi2::Target<K, M, V>& i_target,
        const uint32_t i_section_addr,
        const uint32_t i_address,
        const uint32_t i_mask,
        const uint32_t i_shift,
        const uint32_t i_thread,
        const uint32_t i_thread_size,
        const uint32_t i_lane,
        fapi2::buffer<uint64_t>& o_data)
{
    uint64_t l_addr = calcAddress(i_section_addr, i_address, i_thread, i_thread_size, i_lane);
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("io_ppe_regs::getData: calcAddress l_addr 0x%08X%08X",
             (l_addr >> 32) & 0xFFFFFFFF, l_addr & 0xFFFFFFFF);

#if IO_PPE_MAX_CACHE_SIZE > 0

    if (!cache.hasAddress(l_addr))
    {
#endif
        FAPI_TRY(getData(i_target, l_addr, l_data));
        FAPI_DBG("io_ppe_regs::getData: getData from HW l_data 0x%08X%08X",
                 (l_data >> 32) & 0xFFFFFFFF, l_data & 0xFFFFFFFF);

#if IO_PPE_MAX_CACHE_SIZE > 0
    }
    else
    {
        l_data = cache.getData(l_addr);
        FAPI_DBG("io_ppe_regs::getData: getData from Cache l_data 0x%08X%08X",
                 (l_data >> 32) & 0xFFFFFFFF, l_data & 0xFFFFFFFF);
    }

#endif

    o_data = extractData(l_data, i_address, i_mask, i_shift);
    FAPI_DBG("io_ppe_regs::getData: extractData - o_data 0x%08X%08X",
             (o_data >> 32) & 0xFFFFFFFF, o_data & 0xFFFFFFFF);

#if IO_PPE_MAX_CACHE_SIZE > 0
    FAPI_TRY(cacheData(i_target, l_addr, l_data, 0)); //Cache un-modified data
#endif
fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::putData(const fapi2::Target<K, M, V>& i_target,
        const uint32_t i_section_addr,
        const uint32_t i_address,
        const uint32_t i_mask,
        const uint32_t i_shift,
        const uint32_t i_thread,
        const uint32_t i_thread_size,
        const uint32_t i_lane,
        fapi2::buffer<uint64_t> i_data)
{

    uint64_t l_addr = calcAddress(i_section_addr, i_address, i_thread, i_thread_size, i_lane);
    fapi2::buffer<uint64_t> l_data;

#if IO_PPE_MAX_CACHE_SIZE > 0

    if (!cache.hasAddress(l_addr))
    {
#endif
        FAPI_TRY(getData(i_target, l_addr, l_data));
#if IO_PPE_MAX_CACHE_SIZE > 0
    }
    else
    {
        l_data = cache.getData(l_addr);
    }

#endif
    FAPI_DBG(">>updateData l_data: %llx, i_data: %llx", l_data, i_data);
    l_data = updateData(l_data, i_data, i_address, i_mask, i_shift);
    FAPI_DBG("<<updateData l_data: %llx, i_data: %llx", l_data, i_data);

#if IO_PPE_MAX_CACHE_SIZE > 0
    FAPI_TRY(cacheData(i_target, l_addr, l_data, 1)); //Cache modified data
#endif
fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::getData(const fapi2::Target<K, M, V>& i_target, const uint64_t i_addr,
        fapi2::buffer<uint64_t>& o_data)
{
    FAPI_TRY(fapi2::putScom(i_target, csar_scom_addr, i_addr));
    FAPI_TRY(fapi2::getScom(i_target, csdr_scom_addr, o_data));
fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::putData(const fapi2::Target<K, M, V>& i_target, uint64_t i_addr,
        const fapi2::buffer<uint64_t> i_data)
{
    FAPI_TRY(fapi2::putScom(i_target, csar_scom_addr, i_addr));
    FAPI_TRY(fapi2::putScom(i_target, csdr_scom_addr, i_data));
fapi_try_exit:
    return fapi2::current_err;
}

#if IO_PPE_MAX_CACHE_SIZE > 0
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::cacheData(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_address,
        const fapi2::buffer<uint64_t> i_data,
        const uint8_t i_modified)
{
    bool l_success = cache.add(i_address, i_data, i_modified);

    if (!l_success)
    {
        FAPI_DBG("IO PPE cache overflow");
        uint64_t l_old_addr = 0;
        uint64_t l_old_data = 0;
        uint8_t l_modified = 0;
        cache_overflow = true;

        if (cache.pop(l_old_addr, l_old_data, l_modified))
        {
            if (l_modified)
            {
                FAPI_TRY(putData(i_target, l_old_addr, l_old_data));
            }
        }

        l_success = cache.add(i_address, i_data, i_modified);

        if (!l_success)
        {
            FAPI_ERR("This shouldn't happen");
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}
#endif

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
uint64_t io_ppe_regs<K, M, V>::extractData(const uint64_t i_8b_data,
        const uint32_t i_address,
        const uint32_t i_mask,
        const uint32_t i_shift)
{
    uint64_t l_reg16 = i_address & 0x03;
    uint64_t l_data = i_8b_data;
    l_data >>= (3 - l_reg16) * 16;
    l_data &= i_mask;
    l_data >>= i_shift;
    return l_data;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
uint64_t io_ppe_regs<K, M, V>::updateData(const uint64_t i_8b_data,
        const uint32_t i_reg_data,
        const uint32_t i_address,
        const uint32_t i_mask,
        const uint32_t i_shift)
{
    uint64_t l_reg16 = i_address & 0x03;
    uint64_t l_update_8b = i_reg_data;
    l_update_8b <<= i_shift;
    l_update_8b &= i_mask;
    l_update_8b <<= (3 - l_reg16) * 16;

    uint64_t l_wrt_mask = i_mask;
    l_wrt_mask <<= (3 - l_reg16) * 16;
    FAPI_DBG("l_wrt_mask before invert: %llx", l_wrt_mask);
    l_wrt_mask = ~l_wrt_mask;

    uint64_t l_data = l_wrt_mask & i_8b_data;
    l_data |= l_update_8b;
    FAPI_DBG("l_reg16: %llx l_update_8b: %llx l_wrt_mask: %llx i_8b_data: %llx", l_reg16,
             l_update_8b, l_wrt_mask, i_8b_data);
    FAPI_DBG(" l_data: %llx i_mask: %llx", l_data, i_mask);
    return l_data;
}


template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
uint64_t io_ppe_regs<K, M, V>::calcAddress(const uint32_t i_section_addr,
        const uint32_t i_address,
        const uint32_t i_thread,
        const uint32_t i_thread_size,
        const uint32_t i_lane)
{
    uint64_t l_reg_addr = ((i_lane << 4) | i_address) & 0xFFC;
    l_reg_addr += (i_thread * i_thread_size);
    l_reg_addr <<= 1; //input address is 16bit register address, shift left to get byte addr
    uint64_t l_addr = i_section_addr + l_reg_addr;
    l_addr <<= 32;
    return l_addr;
}


template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::flushCache(const fapi2::Target<K, M, V>& i_target)
{
#if IO_PPE_MAX_CACHE_SIZE > 0

    uint64_t l_addr;
    uint64_t l_data;
    uint8_t l_modified;

    //Note, we should never hit this condition now that flush
    //completely clears the cache.
    if (cache_overflow && i_target != last_target)
    {
        FAPI_ERR("Attempting to flush an overflow cache to a new target");
    }

    cache_overflow = false;
    last_target = i_target;

    while (cache.pop(l_addr, l_data, l_modified))
    {
        if (l_modified)
        {
            FAPI_TRY(putData(i_target, l_addr, l_data));
        }
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::hardReset(const fapi2::Target<K, M, V>& i_target)
{
    fapi2::buffer<uint64_t> l_data = 0x6000000000000000ULL;
    FAPI_TRY(fapi2::putScom(i_target, xcr, l_data));
fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::resume(const fapi2::Target<K, M, V>& i_target)
{
    fapi2::buffer<uint64_t> l_data = 0x2000000000000000ULL;
    FAPI_TRY(fapi2::putScom(i_target, xcr, l_data));
fapi_try_exit:
    return fapi2::current_err;
}
