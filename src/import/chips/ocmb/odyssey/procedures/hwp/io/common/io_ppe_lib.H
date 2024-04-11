/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_ppe_lib.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/// *HW Team: IO
/// *HW Level: 3
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
    private:
        const uint64_t csar_scom_offset = 0x0D;
        const uint64_t csdr_scom_offset = 0x0E;
    public:
        uint64_t base_addr;

        io_ppe_regs(uint64_t i_base_addr) :
            base_addr(i_base_addr)
        {
#if IO_PPE_MAX_CACHE_SIZE > 0
            FAPI_DBG("io_ppe_regs constructor");

            cache_overflow = false;
#endif
        }

        inline __attribute__((always_inline))
        fapi2::ReturnCode getData(const fapi2::Target<K, M, V>& i_target,
                                  const uint32_t i_section_addr,
                                  const uint32_t i_address,
                                  const uint32_t i_mask,
                                  const uint32_t i_shift,
                                  const uint32_t i_thread,
                                  const uint32_t i_thread_size,
                                  const uint32_t i_lane,
                                  fapi2::buffer<uint64_t>& o_data)
        {
            return getData(i_target,
                           calcParm1(i_section_addr, i_address, i_thread, i_thread_size, i_lane, i_shift),
                           i_mask, o_data);
        }

        inline __attribute__((always_inline))
        fapi2::ReturnCode putData(const fapi2::Target<K, M, V>& i_target,
                                  const uint32_t i_section_addr,
                                  const uint32_t i_address,
                                  const uint32_t i_mask,
                                  const uint32_t i_shift,
                                  const uint32_t i_thread,
                                  const uint32_t i_thread_size,
                                  const uint32_t i_lane,
                                  fapi2::buffer<uint64_t> i_data)
        {
            return putData(i_target,
                           calcParm1(i_section_addr, i_address, i_thread, i_thread_size, i_lane, i_shift),
                           i_mask, i_data);
        }

        fapi2::ReturnCode flushCache(const fapi2::Target<K, M, V>& i_target);

    private:

#if IO_PPE_MAX_CACHE_SIZE > 0

        //TODO: Remove stdlib useage
        io_ppe_cache cache;
        bool cache_overflow;
        fapi2::Target<K, M, V> last_target;
#endif

        constexpr  __attribute__((always_inline))
        uint32_t calcParm1(const uint32_t i_section_addr,
                           const uint32_t i_address,
                           const uint32_t i_thread,
                           const uint32_t i_thread_size,
                           const uint32_t i_lane,
                           const uint32_t i_shift)
        {
            /*

                    See section 5.2.6 PPE SRAM in the paxo_workbook

                    PPE SRAM size: 96K

                    i_address is the address of a 16 bit register in the PPE SRAM.
                    There are 4 registers covered by a 64 bit read/write of the sram,
                    The max number of registers in a section is 512 (1024B mem_regs).
                    Per-lane mem_reg registers are addressed as 0byyyyyxxxx (y = 5-
                    bit lane number, x = 4-bit per-lane register offset)
                    We mask out the 2 least significant bits of the register address
                    and shift left 1 bit to get the byte address that starts the 64bit
                    read/write the covers the register.

                    i_section_addr is the byte address in the SRAM where the
                    register section begins.

                    Each register section can be divided into equal segments for each
                    thread.  i_thread_size specifies the byte size for each thread.

                    The least significant 2 bits of i_address are used to determine
                    which 16 bits of a 64 bit access contains the register.

                    A mask is applied to each 16 bit register and the resulting value
                    is then shifted left by i_shift to obtain the final result.

                    NOTE! There are some registers that span 32 bits.  This code
                    supports those by allowing for a 32 bit mask value and
                    checking for when it is larger than a 16 bit value.

                    Parm1 is a combination of the final calculated byte address of the
                    64 bits that contains the register, the i_shift value, and the
                    least significant 2 bits of the address.

                    Parm1 bits

                       3         2         1         0
                      10987654321098765432109876543210

                      0         1         2         3
                      01234567890123456789012345678901
                      |      |  ||           |       |
                      |      |  ||           |       \
                      |      |  ||           \________byte address of 64 bit access
                      |      |  |\
                      |      |  \_i_address[30:31]
                      |      \
                      \_______i_shift


             */

            return ((i_address & 3) << 20) | (i_shift << 24) |
                   ((i_section_addr & 0x000FFFFF) +
                    ((((i_lane << 4) | i_address) & 0xFFC) << 1) +
                    (i_thread * i_thread_size));
        }

        uint64_t extractData(const uint64_t i_8b_data,
                             const uint32_t i_parm1,
                             const uint32_t i_parm2);

        uint64_t updateData(const uint64_t i_8b_data,
                            const uint32_t i_reg_data,
                            const uint32_t i_parm1,
                            const uint32_t i_parm2);

#if IO_PPE_MAX_CACHE_SIZE > 0
        fapi2::ReturnCode cacheData(const fapi2::Target<K, M, V>& i_target,
                                    const uint64_t i_address,
                                    const fapi2::buffer<uint64_t> i_data,
                                    const uint8_t i_modified);
#endif

        fapi2::ReturnCode getData(const fapi2::Target<K, M, V>& i_target,
                                  const uint32_t i_parm1,
                                  const uint32_t i_parm2,
                                  fapi2::buffer<uint64_t>& o_data);

        fapi2::ReturnCode putData(const fapi2::Target<K, M, V>& i_target,
                                  const uint32_t i_parm1,
                                  const uint32_t i_parm2,
                                  fapi2::buffer<uint64_t> i_data);

        fapi2::ReturnCode getData(const fapi2::Target<K, M, V>& i_target, const uint64_t i_addr,
                                  fapi2::buffer<uint64_t>& o_data);

        fapi2::ReturnCode putData(const fapi2::Target<K, M, V>& i_target, uint64_t i_addr,
                                  const fapi2::buffer<uint64_t> i_data);

};

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::getData(const fapi2::Target<K, M, V>& i_target,
        const uint32_t i_parm1,
        const uint32_t i_parm2,
        fapi2::buffer<uint64_t>& o_data)
{
    uint64_t l_addr = uint64_t(i_parm1 | 0xFFF00000) << 32;
    fapi2::buffer<uint64_t> l_data;

    // FAPI_DBG("io_ppe_regs::getData: calcAddress l_addr 0x%08X%08X",
    //          (l_addr >> 32) & 0xFFFFFFFF, l_addr & 0xFFFFFFFF);

#if IO_PPE_MAX_CACHE_SIZE > 0

    if (!cache.hasAddress(l_addr))
    {
#endif
        FAPI_TRY(getData(i_target, l_addr, l_data));
        // FAPI_DBG("io_ppe_regs::getData: getData from HW l_data 0x%08X%08X",
        //          (l_data >> 32) & 0xFFFFFFFF, l_data & 0xFFFFFFFF);
        FAPI_TRY(cacheData(i_target, l_addr, l_data, 0)); //Cache un-modified data
#if IO_PPE_MAX_CACHE_SIZE > 0
    }
    else
    {
        l_data = cache.getData(l_addr);
        // FAPI_DBG("io_ppe_regs::getData: getData from Cache l_data 0x%08X%08X",
        //          (l_data >> 32) & 0xFFFFFFFF, l_data & 0xFFFFFFFF);
    }

#endif

    o_data = extractData(l_data, i_parm1, i_parm2);
    // FAPI_DBG("io_ppe_regs::getData: extractData - o_data 0x%08X%08X",
    //          (o_data >> 32) & 0xFFFFFFFF, o_data & 0xFFFFFFFF);

fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::putData(const fapi2::Target<K, M, V>& i_target,
        const uint32_t i_parm1,
        const uint32_t i_parm2,
        fapi2::buffer<uint64_t> i_data)
{
    uint64_t l_addr = uint64_t(i_parm1 | 0xFFF00000) << 32;
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
    // FAPI_DBG(">>updateData l_data: %llx, i_data: %llx", l_data, i_data);
    l_data = updateData(l_data, i_data, i_parm1, i_parm2);
    // FAPI_DBG("<<updateData l_data: %llx, i_data: %llx", l_data, i_data);

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
    FAPI_TRY(fapi2::putScom(i_target, base_addr | csar_scom_offset, i_addr));
    FAPI_TRY(fapi2::getScom(i_target, base_addr | csdr_scom_offset, o_data));
fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::putData(const fapi2::Target<K, M, V>& i_target, uint64_t i_addr,
        const fapi2::buffer<uint64_t> i_data)
{
    FAPI_TRY(fapi2::putScom(i_target, base_addr | csar_scom_offset, i_addr));
    FAPI_TRY(fapi2::putScom(i_target, base_addr | csdr_scom_offset, i_data));
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
        const uint32_t i_parm1,
        const uint32_t i_parm2)
{
    const uint64_t l_reg16 = (i_parm1 >> 20) & 3;
    const uint32_t i_shift = (i_parm1 >> 24) & 0xFF;
    const uint32_t i_mask = i_parm2;
    uint64_t l_data = i_8b_data;

    if (i_mask > 0xFFFF)
    {
        if (l_reg16 > 2)
        {
            FAPI_ERR("Attempting to align a register greater than 16 bits across a 64 bit boundary");
        }
        else
        {
            l_data >>= (2 - l_reg16) * 16;
        }
    }
    else
    {
        l_data >>= (3 - l_reg16) * 16;
    }

    l_data &= i_mask;
    l_data >>= i_shift;
    return l_data;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
uint64_t io_ppe_regs<K, M, V>::updateData(const uint64_t i_8b_data,
        const uint32_t i_reg_data,
        const uint32_t i_parm1,
        const uint32_t i_parm2)
{
    const uint64_t l_reg16 = (i_parm1 >> 20) & 3;
    const uint32_t i_shift = (i_parm1 >> 24) & 0xFF;
    const uint32_t i_mask = i_parm2;
    uint64_t l_update_8b = i_reg_data;
    l_update_8b <<= i_shift;
    l_update_8b &= i_mask;

    //Some registers can be 32 bits now.  Test if the mask covers more than 16 bits.
    uint64_t l_wrt_mask = i_mask;

    if (i_mask > 0xFFFF)
    {
        if (l_reg16 > 2)
        {
            FAPI_ERR("Attempting to align a register greater than 16 bits across a 64 bit boundary");
        }
        else
        {
            l_wrt_mask <<= (2 - l_reg16) * 16;
            l_update_8b <<= (2 - l_reg16) * 16;
        }
    }
    else
    {
        l_update_8b <<= (3 - l_reg16) * 16;
        l_wrt_mask <<= (3 - l_reg16) * 16;
    }

    l_wrt_mask = ~l_wrt_mask;

    uint64_t l_data = l_wrt_mask & i_8b_data;
    l_data |= l_update_8b;
    // FAPI_DBG("l_reg16: %llx l_update_8b: %llx l_wrt_mask: %llx i_8b_data: %llx", l_reg16,
    //          l_update_8b, l_wrt_mask, i_8b_data);
    // FAPI_DBG(" l_data: %llx i_mask: %llx", l_data, i_mask);
    return l_data;
}


template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_regs<K, M, V>::flushCache(const fapi2::Target<K, M, V>& i_target)
{

    // FAPI_DBG("Start flushCache");
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
        FAPI_DBG("cache.pop: l_addr: %X, l_data %X, l_modified: %d", l_addr, l_data, l_modified);

        if (l_modified)
        {
            FAPI_TRY(putData(i_target, l_addr, l_data));
        }
    }

fapi_try_exit:
#endif
    // FAPI_DBG("End flushCache");
    return fapi2::current_err;
}
