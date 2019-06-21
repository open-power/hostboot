/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_ppe_lib.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_io_ppe_lib.C
/// @brief Class implementation for manipulating PPE SRAM registers
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <p10_io_ppe_lib.H>


//-------------------------------------------------------
// p10_io_ppe_scom_regs methods
//-------------------------------------------------------

///
/// @brief Reads 8 bytes from the PPE sram at the specified address
///
/// @param[in]  i_target    PAUC target
/// @param[in]  i_addr      Address to read from
/// @param[out] o_data      The data read
///
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_ppe_scom_regs::getData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
        const uint64_t i_addr,
        fapi2::buffer<uint64_t>& o_data)
{
    FAPI_TRY(fapi2::putScom(i_target, csar_scom_addr, i_addr));
    FAPI_TRY(fapi2::getScom(i_target, csdr_scom_addr, o_data));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes 8 bytes to the PPE sram at the specified address
///
/// @param[in]  i_target    PAUC target
/// @param[in]  i_addr      Address to write to
/// @param[in]  i_data      The data to write
///
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_ppe_scom_regs::putData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
        const uint64_t i_addr,
        const fapi2::buffer<uint64_t>& i_data)
{
    FAPI_TRY(fapi2::putScom(i_target, csar_scom_addr, i_addr));
    FAPI_TRY(fapi2::putScom(i_target, csdr_scom_addr, i_data));
fapi_try_exit:
    return fapi2::current_err;
}

//-------------------------------------------------------
// p10_io_ppe_cache methods
//-------------------------------------------------------

///
/// @brief Flushes dirty cache data to the PPE SRAM
///
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_ppe_cache::flush()
{
    for (auto l_ce : cache)
    {
        auto l_target = l_ce.first;
        auto l_addr_map = l_ce.second;

        for (auto l_addr_ce : l_addr_map)
        {
            auto l_addr = l_addr_ce.first;
            auto l_val = l_addr_ce.second;

            if (dirty[l_target][l_addr])
            {
                FAPI_TRY(scom_regs->putData(l_target, l_addr, l_val));
                dirty[l_target][l_addr] = false;
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

//-------------------------------------------------------
// p10_io_ppe_sram_reg methods
//-------------------------------------------------------

///
/// @brief Read a PPE SRAM register from the cache,
///        with option to invalidate the cache first
///
/// @param[in]   i_target    PAUC target
/// @param[out]  o_data      The data read for the register
/// @param[in]   i_inv       Invalidate cache data before read if true
///
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_ppe_sram_reg::getData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
        fapi2::buffer<uint64_t>& o_data, const bool i_inv)
{
    return getData(i_target, o_data, 0, i_inv);
}

///
/// @brief Write data to a PPE SRAM register to the cache,
///        with option to write through the cache
///
/// @param[in]   i_target    PAUC target
/// @param[in]   i_data      The data to write to the register
/// @param[in]   i_write     Write through the cache forcing write the PPE SRAM if true
///
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_ppe_sram_reg::putData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
        fapi2::buffer<uint64_t> i_data, const bool i_write)
{
    return putData(i_target, i_data, 0, i_write);
}

///
/// @brief Read a PPR SRAM lane register from the cache
///        with option to invalidate the cache first
///
/// @param[in]   i_target    PAUC target
/// @param[out]  o_data      The data read for the register
/// @param[in]   i_lane      The lane to read from
/// @param[in]   i_inv       Invalidate cache data before read if true
///
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_ppe_sram_reg::getData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
        fapi2::buffer<uint64_t>& o_data, const int i_lane, const bool i_inv)
{
    uint64_t l_reg16 = address & 0x03;
    uint64_t l_reg_addr = ((i_lane << 4) | address) & 0xFFC;
    l_reg_addr <<= 1; //Undocumented shift required
    uint64_t l_addr = cache->section_address + l_reg_addr;
    l_addr <<= 32;

    bool l_read_reg = i_inv;

    if (!l_read_reg && cache->cache.find(i_target) == cache->cache.end())
    {
        l_read_reg = true;
    }

    if (!l_read_reg && cache->cache[i_target].find(l_addr) == cache->cache[i_target].end())
    {
        l_read_reg = true;
    }

    if (!l_read_reg)
    {
        o_data = cache->cache[i_target][l_addr];
    }
    else
    {
        FAPI_TRY(cache->scom_regs->getData(i_target, l_addr, o_data));
        cache->cache[i_target][l_addr] = o_data;
        cache->dirty[i_target][l_addr] = false;
    }

    o_data >>= (3 - l_reg16) * 16;
    o_data &= mask;
    o_data >>= shift;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write data to a PPE SRAM lane register to the cache,
///        with option to write through the cache
///
/// @param[in]   i_target    PAUC target
/// @param[in]   i_data      The data to write to the register
/// @param[in]   i_lane      The lane to write
/// @param[in]   i_write     Write through the cache forcing write the PPE SRAM if true
///
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_ppe_sram_reg::putData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
        fapi2::buffer<uint64_t> i_data, const int i_lane, const bool i_write)
{
    uint64_t l_reg16 = address & 0x03;
    uint64_t l_reg_addr = ((i_lane << 4) | address) & 0xFFC;
    l_reg_addr <<= 1; //Undocumented shift required
    uint64_t l_addr = cache->section_address + l_reg_addr;
    l_addr <<= 32;

    uint64_t l_wrt_mask = mask;

    fapi2::buffer<uint64_t> l_data = 0;
    FAPI_TRY(getData(i_target, l_data));

    i_data <<= shift;
    i_data &= mask;
    i_data <<= (3 - l_reg16) * 16;

    l_wrt_mask <<= (3 - l_reg16) * 16;
    l_wrt_mask = ~l_wrt_mask;

    l_data = l_wrt_mask & cache->cache[i_target][l_addr];
    l_data |= i_data;
    cache->cache[i_target][l_addr] = l_data;

    if (i_write)
    {
        FAPI_TRY(cache->scom_regs->putData(i_target, l_addr, l_data));
        cache->dirty[i_target][l_addr] = false;
    }
    else
    {
        cache->dirty[i_target][l_addr] = true;
    }

fapi_try_exit:
    return fapi2::current_err;
}

p10_io_ppe_scom_regs p10_io_phy_ppe_scom_regs(scomt::pauc::PHY_PPE_WRAP_ARB_CSAR,
        scomt::pauc::PHY_PPE_WRAP_ARB_CSDR);
