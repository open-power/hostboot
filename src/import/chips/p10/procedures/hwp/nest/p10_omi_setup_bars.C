/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_omi_setup_bars.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
/// @file p10_omi_setup_bars.H
/// @brief Setup p10 OMI MMIO/OCConfig bars
///
///

// *HWP HWP Owner: Ben Gass bgass@us.ibm.com
// *HWP FW Owner: Ilya Smirnov ismirno@us.ibm.com
// *HWP Consumed by: HB

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p10_omi_setup_bars.H>
#include <p10_fbc_utils.H>
#include <p10_scom_mc_a.H>
#include <p10_scom_mc_b.H>
#include <p10_scom_mc_d.H>
#include <p10_scom_mc_8.H>
#include <p10_scom_mc_9.H>
#include <p10_scom_mc_e.H>

#include <lib/inband/exp_inband.H>

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------

fapi2::ReturnCode p10_omi_setup_bars(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");
    using namespace scomt::mc;
    uint64_t l_base_addr_nm0;
    uint64_t l_base_addr_nm1;
    uint64_t l_base_addr_m;
    fapi2::buffer<uint64_t> l_mmio_bar;
    fapi2::buffer<uint64_t> l_cfg_bar;
    uint64_t l_base_addr_mmio;
    uint8_t l_mcc_pos;
    fapi2::ATTR_CHIP_EC_FEATURE_HW550549_Type l_hw550549;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW550549,
                           i_target,
                           l_hw550549),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW550549)");

    // determine base address of chip MMIO range
    FAPI_TRY(p10_fbc_utils_get_chip_base_address(i_target,
             EFF_TOPOLOGY_ID,
             l_base_addr_nm0,
             l_base_addr_nm1,
             l_base_addr_m,
             l_base_addr_mmio),
             "Error from p9_fbc_utils_get_chip_base_address");

    FAPI_DBG("l_base_addr_mmio: 0x%llx", l_base_addr_mmio);

    for (auto l_mcc : i_target.getChildren<fapi2::TARGET_TYPE_MCC>())
    {
        fapi2::ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        uint64_t l_omi_inband_addr = 0;
        fapi2::buffer<uint64_t> l_scom_data;

        auto l_omi_targets = l_mcc.getChildren<fapi2::TARGET_TYPE_OMI>();

        // get MI target to configure MCFGPR
        if (l_omi_targets.size() > 0)
        {

            auto l_mi = l_mcc.getParent<fapi2::TARGET_TYPE_MI>();

            // Set the sizes for the MMIO/Config bars
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mcc, l_mcc_pos),
                     "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            l_scom_data.flush<0>();

            if (l_mcc_pos % 2 == 0)
            {
                FAPI_TRY(GET_SCOMFIR_MCFGP0(l_mi, l_scom_data));
                FAPI_INF("Read MCFGP0 Value 0x%.16llX", l_scom_data);
            }
            else
            {
                FAPI_TRY(GET_SCOMFIR_MCFGP1(l_mi, l_scom_data));
                FAPI_INF("Read MCFGP1 Value 0x%.16llX", l_scom_data);
            }

            // 2GB cfg and MMIO
            FAPI_TRY(PREP_SCOMFIR_MCFGP0(l_mi));
            SET_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE(mss::exp::ib::EXPLR_IB_BAR_SIZE, l_scom_data);
            SET_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE(mss::exp::ib::EXPLR_IB_BAR_SIZE, l_scom_data);

            // Write to reg
            if (l_mcc_pos % 2 == 0)
            {
                FAPI_INF("Write MCFGP0 Value 0x%.16llX", l_scom_data);
                FAPI_TRY(PUT_SCOMFIR_MCFGP0(l_mi, l_scom_data));
            }
            else
            {
                FAPI_INF("Write MCFGP1 Value 0x%.16llX", l_scom_data);
                FAPI_TRY(PREP_SCOMFIR_MCFGP1(l_mi));
                FAPI_TRY(PUT_SCOMFIR_MCFGP1(l_mi, l_scom_data));
            }

            for (auto l_omi : l_omi_targets)
            {
                uint8_t l_pos = 0;
                // retrieve OMI pos
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                       l_omi,
                                       l_pos),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                // retrieve inband BAR offset
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET,
                                       l_omi,
                                       l_bar_offset),
                         "Error from FAPI_ATTR_GET (ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET)");

                FAPI_DBG("l_bar_offset: 0x%llx", l_bar_offset);

                // If this is channel B, then the B bit must be set.  If it is not, then the B bit must not be set.
                FAPI_ASSERT( ((l_pos % 2) == 1) ==  // Is this B channel?
                             ((l_bar_offset & mss::exp::ib::EXPLR_IB_BAR_B_BIT) == mss::exp::ib::EXPLR_IB_BAR_B_BIT),

                             fapi2::P10_OMI_SETUP_BARS_INVALID_BAR()
                             .set_TARGET(l_omi)
                             .set_BAR_VALUE(l_bar_offset),
                             "B Channel requires BAR size bit set");

                FAPI_ASSERT(((l_bar_offset & mss::exp::ib::EXPLR_IB_BAR_MASK_ZERO) == 0),
                            fapi2::P10_OMI_SETUP_BARS_INVALID_BAR()
                            .set_TARGET(l_omi)
                            .set_BAR_VALUE(l_bar_offset),
                            "Bar size not honored");

                FAPI_ASSERT(((l_bar_offset & mss::exp::ib::EXPLR_IB_MMIO_OFFSET) == 0),
                            fapi2::P10_OMI_SETUP_BARS_INVALID_BAR()
                            .set_TARGET(l_omi)
                            .set_BAR_VALUE(l_bar_offset),
                            "MMIO bit must not be set");

                l_omi_inband_addr = l_bar_offset;
            }

            FAPI_DBG("l_omi_inband_addr: 0x%llx", l_omi_inband_addr);

            // Force A Bar value
            l_omi_inband_addr = l_omi_inband_addr & (~mss::exp::ib::EXPLR_IB_BAR_B_BIT);

            FAPI_DBG("l_omi_inband_addr: 0x%llx", l_omi_inband_addr);

            // Add MMIO address for the chip
            l_omi_inband_addr = l_omi_inband_addr | l_base_addr_mmio;

            FAPI_DBG("l_omi_inband_addr: 0x%llx", l_omi_inband_addr);

            // Get cfg bar value
            fapi2::buffer<uint64_t> l_omi_inband_buf = l_omi_inband_addr;
            FAPI_DBG("l_omi_inband_buf: 0x%llx", l_omi_inband_buf);
            l_cfg_bar = l_omi_inband_buf;
            l_cfg_bar = (l_omi_inband_buf << 8) >>
                        (64 - SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN);
            FAPI_DBG("l_cfg_bar: 0x%llx", l_cfg_bar);

            // Get MMIO bar value
            l_omi_inband_addr = l_omi_inband_addr | mss::exp::ib::EXPLR_IB_MMIO_OFFSET;
            l_omi_inband_buf = l_omi_inband_addr;
            FAPI_DBG("l_omi_inband_buf: 0x%llx", l_omi_inband_buf);
            l_mmio_bar = (l_omi_inband_buf << 8) >>
                         (64 - SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN);
            FAPI_DBG("l_mmio_bar: 0x%llx", l_mmio_bar);

            l_scom_data.flush<0>();

            if(l_mcc_pos % 2 == 0)
            {
                FAPI_TRY(GET_SCOMFIR_MCFGPR0(l_mi, l_scom_data));
            }
            else
            {
                FAPI_TRY(GET_SCOMFIR_MCFGPR1(l_mi, l_scom_data));
            }

            FAPI_TRY(PREP_SCOMFIR_MCFGPR0(l_mi));
            SET_SCOMFIR_MCFGPR0_CONFIGURATION_VALID(l_scom_data);
            SET_SCOMFIR_MCFGPR0_MMIO_VALID(l_scom_data);
            SET_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS(l_cfg_bar, l_scom_data);
            SET_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS(l_mmio_bar, l_scom_data);

            // configure inband channel 0 MCFGPR0
            if(l_mcc_pos % 2 == 0)
            {
                FAPI_TRY(PUT_SCOMFIR_MCFGPR0(l_mi, l_scom_data));
            }
            // configure inband channel 1 MCFGPR1
            else
            {
                FAPI_TRY(PREP_SCOMFIR_MCFGPR1(l_mi));
                FAPI_TRY(PUT_SCOMFIR_MCFGPR1(l_mi, l_scom_data));
            }
        }
    }

    for (auto l_mi : i_target.getChildren<fapi2::TARGET_TYPE_MI>())
    {

        FAPI_DBG("Unmasking FIR");

        fapi2::buffer<uint64_t> l_mcfiraction;
        fapi2::buffer<uint64_t> l_mcfirmask_and;

        // Setup MC Fault Isolation Action1 register buffer
        l_mcfiraction.setBit<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
        l_mcfiraction.setBit<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
        l_mcfiraction.setBit<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
        l_mcfiraction.setBit<SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
        l_mcfiraction.setBit<SCOMFIR_MCFIR_POP_RCMD_BADHIT>();

        if(!l_hw550549) //Unmask only if not affected by HW550549
        {
            l_mcfiraction.setBit<SCOMFIR_MCFIR_SYNC_ERROR>();
        }

        // Setup FIR bits in MC Fault Isolation Mask Register buffer
        l_mcfirmask_and.flush<1>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
        l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_MULTIPLE_TID_ERROR>();

        if(!l_hw550549) //Set only if not affected by HW550549
        {
            l_mcfirmask_and.clearBit<SCOMFIR_MCFIR_SYNC_ERROR>();
        }

        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_mi, l_targetStr, sizeof(l_targetStr));
        FAPI_INF("Unmask FIR for MC target: %s", l_targetStr);

        // Write MC FIR action1
        FAPI_TRY(fapi2::putScom(l_mi, SCOMFIR_MCFIRACT1, l_mcfiraction),
                 "Error from putScom (SCOMFIR_MCFIRACT1)");

        // Write mask
        FAPI_TRY(fapi2::putScom(l_mi, SCOMFIR_MCFIRMASK_WO_AND, l_mcfirmask_and),
                 "Error from putScom (SCOMFIR_MCFIRMASK_WO_AND)");

        FAPI_DBG("Unmask Complete");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
