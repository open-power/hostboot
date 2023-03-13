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
/// @brief unload_ostream hwp_data_ostream implementation for usage with HWP wrappers and unit tests
///
class unload_ostream
{
    public:
        std::vector<uint64_t> iv_data;

        unload_ostream() = default;

        ///
        /// @brief Put function implementation for cronus usage
        ///
        /// @param[in] i_data hwp data unit
        ///
        fapi2::ReturnCodes put(uint64_t i_data)
        {
            // Data unit is a uint32_t currently
            iv_data.push_back(i_data);
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_scom_data(const fapi2::Target<K, M, V>& i_target,
                      unload_ostream& i_ostream,
                      const uint64_t i_base_addr,
                      const uint32_t i_unit_mask,
                      const uint32_t* i_offsets,
                      uint32_t i_len)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t i = 0; i < i_len; i++)
    {
        l_addr = ((uint64_t)i_unit_mask << UNLOAD_SHIFT_CONSTS::UNIT_MASK_SHIFT) | i_base_addr | i_offsets[i];

        l_rc = fapi2::getScom(i_target, l_addr, l_data); // FIR Bits

        if (l_rc)
        {
            l_data = 0xDEADDEADDEADDEAD;
        }

        i_ostream.put(l_data);
    }
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_mem_data(const fapi2::Target<K, M, V>& i_target,
                     unload_ostream& i_ostream,
                     const uint64_t i_addr_reg,
                     const uint64_t i_data_reg,
                     uint64_t* i_base,
                     uint32_t* i_size,
                     uint8_t i_len)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t i = 0; i < i_len; i++)
    {
        fapi2::putScom(i_target, i_addr_reg, i_base[i]);

        for (uint32_t offset = 0; offset < i_size[i]; offset += 0x8)
        {
            // Send the Address
            // l_data = i_base[i] + ((uint64_t)offset << UNLOAD_SHIFT_CONSTS::OFFSET_SHIFT);
            // i_ostream.put(l_data);

            l_rc = fapi2::getScom(i_target, i_data_reg, l_data); // FIR Bits

            if (l_rc)
            {
                l_data = 0xDEADDEADDEADDEAD;
            }

            i_ostream.put(l_data);
        }
    }
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_pl_data(const fapi2::Target<K, M, V>& i_target,
                    unload_ostream& i_ostream,
                    const uint64_t i_base_addr,
                    const uint32_t i_unit_mask,
                    uint32_t i_max_units,
                    uint32_t i_max_lanes,
                    uint16_t i_start,
                    uint16_t i_end)
{
    constexpr uint32_t c_tx_transition = 0x080;

    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t l_reg_addr = i_start; l_reg_addr <= i_end; l_reg_addr++)
    {
        for (uint32_t l_ioo_unit = 0; l_ioo_unit < i_max_units; l_ioo_unit++)
        {
            for (uint32_t l_lane = 0; l_lane < i_max_lanes; l_lane++)
            {
                l_addr = i_base_addr | ((uint64_t)i_unit_mask << UNLOAD_SHIFT_CONSTS::UNIT_MASK_SHIFT);
                l_addr |= ((uint64_t)l_reg_addr << UNLOAD_SHIFT_CONSTS::REG_ADDR_SHIFT) | ((uint64_t)l_ioo_unit <<
                          UNLOAD_SHIFT_CONSTS::UNIT_SHIFT) | ((uint64_t)l_lane << UNLOAD_SHIFT_CONSTS::LANE_SHIFT);

                if (l_reg_addr >= c_tx_transition)
                {
                    l_addr |= ((uint64_t)0x1 << UNLOAD_SHIFT_CONSTS::TX_SHIFT); // Tx Direction
                }

                l_rc = fapi2::getScom(i_target, l_addr, l_data); // fir bits

                if (l_rc)
                {
                    l_data = 0xDEADDEADDEADDEAD;
                }

                i_ostream.put(l_data);
            }
        }
    }
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_pg_data(const fapi2::Target<K, M, V>& i_target,
                    unload_ostream& i_ostream,
                    const uint64_t i_base_addr,
                    const uint32_t i_unit_mask,
                    const uint32_t i_max_units,
                    uint16_t i_start,
                    uint16_t i_end)
{
    constexpr uint16_t c_tx_transition = 0x180;

    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t l_reg_addr = i_start; l_reg_addr <= i_end; l_reg_addr++)
    {
        for (uint32_t l_ioo_unit = 0; l_ioo_unit < i_max_units; l_ioo_unit++)
        {
            l_addr = i_base_addr | ((uint64_t)i_unit_mask << UNLOAD_SHIFT_CONSTS::UNIT_MASK_SHIFT);
            l_addr |= ((uint64_t)l_reg_addr << UNLOAD_SHIFT_CONSTS::REG_ADDR_SHIFT) | ((uint64_t)l_ioo_unit <<
                      UNLOAD_SHIFT_CONSTS::UNIT_SHIFT);

            if (l_reg_addr >= c_tx_transition)
            {
                l_addr |= ((uint64_t)0x1 << UNLOAD_SHIFT_CONSTS::TX_SHIFT); // Tx Direction
            }

            l_rc = fapi2::getScom(i_target, l_addr, l_data); // fir bits

            if (l_rc)
            {
                l_data = 0xDEADDEADDEADDEAD;
            }

            i_ostream.put(l_data);
        }
    }
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
void stream_pb_data(const fapi2::Target<K, M, V>& i_target,
                    unload_ostream& i_ostream,
                    const uint64_t i_base_addr,
                    const uint32_t i_unit_mask,
                    uint16_t i_start,
                    uint16_t i_end)
{
    constexpr uint16_t c_tx_transition = 0x1EF;

    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;
    uint32_t l_rc = 0; // FAPI_RC_SUCCESS

    for (uint32_t l_reg_addr = i_start; l_reg_addr <= i_end; l_reg_addr++)
    {
        l_addr = i_base_addr | ((uint64_t)i_unit_mask << UNLOAD_SHIFT_CONSTS::UNIT_MASK_SHIFT);
        l_addr |= ((uint64_t)l_reg_addr << UNLOAD_SHIFT_CONSTS::REG_ADDR_SHIFT);

        if (l_reg_addr <= c_tx_transition)
        {
            l_addr |= ((uint64_t)0x1 << UNLOAD_SHIFT_CONSTS::TX_SHIFT); // Tx Direction
        }

        l_rc = fapi2::getScom(i_target, l_addr, l_data); // fir bits

        if (l_rc)
        {
            l_data = 0xDEADDEADDEADDEAD;
        }

        i_ostream.put(l_data);
    }
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode common_unload(const fapi2::Target<K, M, V>& i_target,
                                const uint64_t i_base_addr,
                                const uint32_t i_unit_mask,
                                unload_ostream& i_ostream)
{
    FAPI_DBG("Starting io_ppe_common::unload");

    fapi2::buffer<uint64_t> l_data;
    uint32_t l_max_ioo_units = 2;
    uint32_t l_max_lanes = 18;

    // Based on the unit, reduce the max units & lanes
    if (i_unit_mask == 0xD)
    {
        l_max_ioo_units = 1;
        l_max_lanes = 11;
    }

    FAPI_DBG("HWP: I/O UNLOAD: 0x%02X Groups(%d) Lanes(%d)", i_unit_mask, l_max_ioo_units, l_max_lanes);

    // 1. Flat Scom Regs (64b reads)
    // 2. Mem Regs (64b reads, only need the mem-regs sections)
    // 3. Tx Hardware Regs (16bit reads, will pack them to 32b fifo entries)
    // 4. Rx Hardware Regs (16bit reads, will pack them to 32b fifo entries)

    // 1. Flat Scom Regs (64b reads): 18 * 2 = 36(32B)
    uint32_t offsets[] = {0x00, 0x03, 0x06, 0x07, 0x0A, 0x0D, 0x0E, 0x13, 0x14, 0x15, 0x17, 0x18, 0x19, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x26, 0x27, 0x28, 0x2B};

    stream_scom_data(i_target, i_ostream, 0x00012800, i_unit_mask, offsets, sizeof(offsets) / sizeof(offsets[0]));

    // 2. Mem Regs (64b reads, only need the mem-regs sections)
    uint64_t c_addr_reg = 0x0001280D | ((uint64_t)i_unit_mask << UNLOAD_SHIFT_CONSTS::UNIT_MASK_SHIFT);
    uint64_t c_data_reg = 0x0001280E | ((uint64_t)i_unit_mask << UNLOAD_SHIFT_CONSTS::UNIT_MASK_SHIFT);
    uint64_t c_incr_reg = 0x0001280A | ((uint64_t)i_unit_mask << UNLOAD_SHIFT_CONSTS::UNIT_MASK_SHIFT);

    // Set Auto Increment
    fapi2::getScom(i_target, c_incr_reg, l_data);
    l_data |= 0x8000000000000000;
    fapi2::putScom(i_target, c_incr_reg, l_data);

    uint64_t l_base[] = {0xffff119000000000, 0xffff11b000000000, 0xffff280000000000, 0xffff3c0000000000};
    uint32_t l_size[] = {0x20,               0x50,               0x800,              0x400};

    // 2.1 Image Regs (32B)
    stream_mem_data(i_target, i_ostream, c_addr_reg, c_data_reg, l_base, l_size, (sizeof(l_base) / sizeof(l_base[0])));

    // Disable Auto Increment
    fapi2::getScom(i_target, c_incr_reg, l_data);
    l_data &= 0x7FFFFFFFFFFFFFFF;
    fapi2::putScom(i_target, c_incr_reg, l_data);

    // 3. Tx Hardware Regs (16bit reads, will pack them to 32b fifo entries)

    // RX PL Regs (0x000 - 0x07C)
    // TX PL Regs (0x080 - 0x0A5)
    // RX PG Regs (0x100 - 0x16F)
    // TX PG Regs (0x180 - 0x1AD)
    // TX PB Regs (0x1E0 - 0x1EF)
    // RX PB Regs (0x1F0 - 0x1F3)

    // Rx/Tx PL Regs
    stream_pl_data(i_target, i_ostream, i_base_addr, i_unit_mask, l_max_ioo_units, l_max_lanes, 0x00, 0xa5);

    // Rx/Tx PG Regs
    stream_pg_data(i_target, i_ostream, i_base_addr, i_unit_mask, l_max_ioo_units, 0x100, 0x1AD);

    // Rx/Tx Bus Regs
    stream_pb_data(i_target, i_ostream, i_base_addr, i_unit_mask, 0x1E0, 0x1F3);

fapi_try_exit :
    FAPI_DBG("Ending io_ppe_common::unload");
    return fapi2::current_err;
}
