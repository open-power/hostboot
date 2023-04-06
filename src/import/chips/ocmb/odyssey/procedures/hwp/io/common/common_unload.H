/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/common_unload.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file common_unload.C
/// @brief Common unload functions
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HW FW Maintainer:
/// *HW Consumed by  : SBE
///-----------------------------------------------------------------------------
#pragma once

#include <fapi2.H>
#include <io_scom_lib.H>
#include <hwp_data_stream.H>

enum UNLOAD_SHIFT_CONSTS
{
    OFFSET_SHIFT = 32,
    TX_SHIFT = 42,
    UNIT_MASK_SHIFT = 24,
    REG_ADDR_SHIFT = 43,
    UNIT_SHIFT = 37,
    LANE_SHIFT = 32,
};

///
/// @brief Utility to enable/disable auto increment mode.
/// @param[in] i_target         Target Chip
/// @param[in] i_base_addr      Target chip's base address
/// @param[in] i_enable         true=enable; false=disable
///
/// @return void function, as we want to continue in fail case.
///
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void auto_increment_ctrl(const fapi2::Target<K, M, V>& i_target,
                         const uint64_t i_base_addr,
                         const bool i_enable)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t c_incr_reg = i_base_addr | 0xA;
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);

    // Enable Auto Increment
    // There's minimal error checking so that the output data is always the same size
    if (i_enable == true)
    {
        l_rc = fapi2::getScom(i_target, c_incr_reg, l_data);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("Auto increment enable getScom failed");
        }

        l_data |= 0x8000000000000000;
        l_rc = fapi2::putScom(i_target, c_incr_reg, l_data);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("Auto increment enable putScom failed");
        }
    }
    else // Disable Auto Increment
    {
        l_rc = fapi2::getScom(i_target, c_incr_reg, l_data);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("Auto increment disable getScom failed");
        }

        l_data |= 0x7FFFFFFFFFFFFFFF;
        l_rc = fapi2::putScom(i_target, c_incr_reg, l_data);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("Auto increment disable putScom failed");
        }
    }

    return;
}

/// @brief                      Stream SCOM data to file
/// @param[in] i_target         Target Chip
/// @param[out] o_ostream       Streaming object to write data to
/// @param[in] i_base_addr      Target chip's base address
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_scom_data(const fapi2::Target<K, M, V>& i_target,
                      fapi2::hwp_bit_ostream& o_ostream,
                      const uint64_t i_base_addr)
{
    uint32_t offsets[] = {0x00, 0x02, 0x04, 0x05, 0x0A, 0x0D, 0x0E, 0x13, 0x14, 0x15, 0x17, 0x18, 0x19, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x27, 0x2C, 0x2D};

    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t i = 0; i < sizeof(offsets) / sizeof(offsets[0]); i++)
    {
        l_addr = i_base_addr | offsets[i];

        l_rc = fapi2::getScom(i_target, l_addr, l_data); // FIR Bits

        if (l_rc)
        {
            l_data = 0xDEADDEADDEADDEAD;
        }

        o_ostream.put64(l_data);
    }

    o_ostream.flush();
}

/// @brief                      Stream SRAM per PPE data to file
/// @param[in] i_target         Target Chip
/// @param[in] i_base_addr      Target chip's base address
/// @param[out] o_ostream       Streaming object to write data to
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_mem_data_pp(const fapi2::Target<K, M, V>& i_target,
                        const uint64_t i_base_addr,
                        fapi2::hwp_bit_ostream& o_ostream)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    uint64_t c_addr_reg = i_base_addr | 0xD;
    uint64_t c_data_reg = i_base_addr | 0xE;

    // Enable Auto Increment
    auto_increment_ctrl(i_target, i_base_addr, true);

    //                      img regs            debug log
    uint64_t l_base[] = {0xFFFF30C000000000, 0xFFFF7C0000000000};
    uint32_t l_size[] = {0x20,               0x400};

    for (uint32_t i = 0; i < sizeof(l_base) / sizeof(l_base[0]); i++)
    {
        fapi2::putScom(i_target, c_addr_reg, l_base[i]);

        for (uint32_t offset = 0; offset < l_size[i]; offset += 0x8)
        {
            l_rc = fapi2::getScom(i_target, c_data_reg, l_data);

            if (l_rc)
            {
                l_data = 0xDEADDEADDEADDEAD;
            }

            o_ostream.put64(l_data);
        }
    }

    o_ostream.flush();

    // Disable Auto Increment
    auto_increment_ctrl(i_target, i_base_addr, false);
}

/// @brief                      Stream SRAM per thread data to file
/// @param[in] i_target         Target Chip
/// @param[in] i_base_addr      Target chip's base address
/// @param[in] i_threads        Number of threads to run on
/// @param[out] o_ostream       Streaming object to write data to
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_mem_data_pt(const fapi2::Target<K, M, V>& i_target,
                        const uint64_t i_base_addr,
                        const uint32_t i_threads,
                        fapi2::hwp_bit_ostream& o_ostream)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    uint64_t c_addr_reg = i_base_addr | 0xD;
    uint64_t c_data_reg = i_base_addr | 0xE;

    // Enable Auto Increment
    auto_increment_ctrl(i_target, i_base_addr, true);

    // Loop over # of threads for FW & Mem regs
    //                      firmware regs       mem regs
    uint64_t l_base[] = {0xFFF30E0000000000, 0xFFFF580000000000};
    uint32_t l_size[] = {0x20,               0x400};

    for (uint32_t thread = 0; thread < i_threads; thread++)
    {
        for (uint32_t i = 0; i < sizeof(l_base) / sizeof(l_base[0]); i++)
        {
            fapi2::putScom(i_target, c_addr_reg, l_base[i]);

            for (uint32_t offset = 0; offset < l_size[i]; offset += 0x8)
            {
                l_rc = fapi2::getScom(i_target, c_data_reg, l_data);

                if (l_rc)
                {
                    l_data = 0xDEADDEADDEADDEAD;
                }

                o_ostream.put64(l_data);
            }
        }
    }

    o_ostream.flush();

    // Disable Auto Increment
    auto_increment_ctrl(i_target, i_base_addr, false);
}

/// @brief                  Stream the per lane data back to file
/// @param[in] i_target         Target Chip
/// @param[out] o_ostream       Target chip's base address
/// @param[in] i_base_addr      Streaming object to write data to
/// @param[in] i_num_groups     Number of groups to loop over
/// @param[in] i_max_lanes      Number of lanes to loop over
/// @param[in] i_start          Starting register value
/// @param[in] i_end            Ending register value
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_pl_data(const fapi2::Target<K, M, V>& i_target,
                    fapi2::hwp_bit_ostream& o_ostream,
                    const uint64_t i_base_addr,
                    const uint16_t i_num_groups,
                    const uint16_t i_max_lanes,
                    const uint16_t i_start,
                    const uint16_t i_end)
{
    FAPI_DBG("Stream PL Data");

    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t l_reg_addr = i_start; l_reg_addr <= i_end; l_reg_addr += 0x10)
    {
        for (uint32_t l_ioo_unit = 0; l_ioo_unit < i_num_groups; l_ioo_unit++)
        {
            for (uint32_t l_lane = 0; l_lane < i_max_lanes; l_lane++)
            {
                l_addr = buildAddr(i_base_addr, l_ioo_unit, l_lane, l_reg_addr);

                l_rc = fapi2::getScom(i_target, l_addr, l_data);

                if (l_rc)
                {
                    l_data = 0xDEADDEADDEADDEAD;
                }

                o_ostream.put16(l_data);
            }
        }
    }
}

/// @brief                  Stream the per lane data back to file
/// @param[in] i_target         Target Chip
/// @param[out] o_ostream       Target chip's base address
/// @param[in] i_base_addr      Streaming object to write data to
/// @param[in] i_num_groups     Number of groups to loop over
/// @param[in] i_start          Starting register value
/// @param[in] i_end            Ending register value
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_pg_data(const fapi2::Target<K, M, V>& i_target,
                    fapi2::hwp_bit_ostream& o_ostream,
                    const uint64_t i_base_addr,
                    const uint16_t i_num_groups,
                    const uint16_t i_start,
                    const uint16_t i_end)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t l_reg_addr = i_start; l_reg_addr <= i_end; l_reg_addr += 0x10)
    {
        for (uint32_t l_ioo_unit = 0; l_ioo_unit < i_num_groups; l_ioo_unit++)
        {
            l_addr = buildAddr(i_base_addr, l_ioo_unit, 0, l_reg_addr);

            l_rc = fapi2::getScom(i_target, l_addr, l_data);

            if (l_rc)
            {
                l_data = 0xDEADDEADDEADDEAD;
            }

            o_ostream.put16(l_data);
        }
    }
}

/// @brief                  Stream the per lane data back to file
/// @param[in] i_target         Target Chip
/// @param[out] o_ostream       Target chip's base address
/// @param[in] i_base_addr      Streaming object to write data to
/// @param[in] i_start          Starting register value
/// @param[in] i_end            Ending register value
template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_pb_data(const fapi2::Target<K, M, V>& i_target,
                    fapi2::hwp_bit_ostream& o_ostream,
                    const uint64_t i_base_addr,
                    const uint16_t i_start,
                    const uint16_t i_end)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t l_reg_addr = i_start; l_reg_addr <= i_end; l_reg_addr += 0x10)
    {
        l_addr = buildAddr(i_base_addr, 0, 0, l_reg_addr);

        l_rc = fapi2::getScom(i_target, l_addr, l_data);

        if (l_rc)
        {
            l_data = 0xDEADDEADDEADDEAD;
        }

        o_ostream.put16(l_data);
    }
}
