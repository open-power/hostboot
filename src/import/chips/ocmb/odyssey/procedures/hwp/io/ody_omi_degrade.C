/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_degrade.C $ */
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
///------------------------------------------------------------------------------
/// @file ody_omi_degrade.C
/// @brief Attempt degrade recovery on degraded lanes
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------
// EKB-Mirror-To: hostboot

#include <ody_omi_degrade.H>
#include <ody_scom_omi.H>
#include <ody_io_ppe_common.H>
#include <ody_omi_hss_init.H>
#include <ody_omi_hss_dccal_start.H>
#include <ody_omi_hss_dccal_poll.H>

enum IO_DEGRADE_CONSTS
{
    UNDEGRADE_BIT = 1,
    TX_POWERON_BIT = 2,
    RX_POWERON_BIT = 3,

    TRAIN_MODE_BIT = 52,
    TRAIN_MODE_LEN = 4,

    CYA_ALLOW_UNDEGRADE_BIT = 1,

    TX_PERF_DEGRADED_BIT = 20,
    TX_PERF_DEGRADED_LEN = 2,
    RX_PERF_DEGRADED_BIT = 22,
    RX_PERF_DEGRADED_LEN = 2,

    LANES_DISABLED_BIT = 56,
    LANES_DISABLED_LEN = 8,

    RX_CTLE_PEAK1_VAL = 4,
    RX_CTLE_PEAK2_VAL = 4,
    RX_LTE_GAIN_VAL = 7,
    RX_LTE_ZERO_VAL = 1,
};

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_degrade(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const uint8_t i_step,
                                  const uint8_t i_loops_to_poll)
{
    FAPI_DBG("Starting ody_omi_degrade");

    constexpr uint8_t c_max_lanes = 8;
    constexpr uint8_t c_thread = 0;

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(PHY_ODY_OMI_BASE);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    fapi2::buffer<uint64_t> l_buffer = 0x0;
    uint32_t l_disabled_lanes = 0;
    uint32_t l_fail = 0;
    uint8_t l_done = 0;
    uint8_t l_lane = 0;

    // Allow undegrade (clear bit)
    // Power on Tx/Rx
    if (i_step == 0)
    {
        FAPI_DBG("common_omi_degrade::degrade Degrade Step 0");
        FAPI_TRY(fapi2::getScom(i_target, scomt::omi::D_REG_DL0_CYA_BITS, l_buffer));
        l_buffer.setBit<TX_POWERON_BIT>();
        l_buffer.setBit<RX_POWERON_BIT>();
        l_buffer.setBit<UNDEGRADE_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, scomt::omi::D_REG_DL0_CYA_BITS, l_buffer));
        l_buffer.flush<0>();

        // Allow Undegrade
        FAPI_TRY(fapi2::getScom(i_target, scomt::omi::D_REG_DL0_CYA_BITS, l_buffer));
        l_buffer.setBit<CYA_ALLOW_UNDEGRADE_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, scomt::omi::D_REG_DL0_CYA_BITS, l_buffer));
        l_buffer.flush<0>();
    }
    // Reset lane
    // Reset Rx presets
    // Rerun dccal
    else if (i_step == 1)
    {
        FAPI_DBG("common_omi_degrade::degrade Degrade Step 1");

        for (l_lane = 0; l_lane <= c_max_lanes; l_lane++)
        {
            FAPI_TRY(l_ppe_common.ext_cmd_start(i_target, c_thread, l_lane, l_lane, ody_io::IORESET_PL));
            FAPI_TRY(l_ppe_common.ext_cmd_poll(i_target, c_thread, ody_io::IORESET_PL, l_done, l_fail));
        }

        FAPI_TRY(ody_omi_hss_init(i_target));
        FAPI_TRY(ody_omi_hss_dccal_start(i_target));
    }
    // Poll dccal
    else if (i_step == 2)
    {
        FAPI_DBG("common_omi_degrade::degrade Degrade Step 2");
        FAPI_TRY(ody_omi_hss_dccal_poll(i_target));
    }
    // Retrain
    else if (i_step == 3)
    {
        FAPI_DBG("common_omi_degrade::degrade Degrade Step 3");
        FAPI_TRY(fapi2::getScom(i_target, scomt::omi::D_REG_DL0_CONFIG0, l_buffer));
        l_buffer.insertFromRight<TRAIN_MODE_BIT, TRAIN_MODE_LEN, uint8_t>(0x8);
        FAPI_TRY(fapi2::putScom(i_target, scomt::omi::D_REG_DL0_CONFIG0, l_buffer));
        l_buffer.flush<0>();
    }
    // confirm width
    // if not full bandwidth, set FIR again
    else if (i_step == 4)
    {
        FAPI_DBG("common_omi_degrade::degrade Degrade Step 4");
        l_disabled_lanes = 0x0;
        FAPI_TRY(fapi2::getScom(i_target, scomt::omi::D_REG_DL0_STATUS, l_buffer));
        l_buffer.extractToRight<LANES_DISABLED_BIT, LANES_DISABLED_LEN, uint32_t>(l_disabled_lanes);

        for (l_lane = 0; l_lane <= c_max_lanes; l_lane++)
        {
            // Lane is disabled
            if ((0x1 << l_lane) & l_disabled_lanes)
            {
                // Reset the degrade bit
                FAPI_DBG("Lane(0x%8X) is still disabled", l_lane);
                FAPI_TRY(fapi2::getScom(i_target, scomt::omi::D_REG_DL0_CONFIG1, l_buffer));
                l_buffer.insertFromRight<TX_PERF_DEGRADED_BIT, TX_PERF_DEGRADED_LEN, uint8_t>(0b1 << l_lane);
                l_buffer.insertFromRight<RX_PERF_DEGRADED_BIT, RX_PERF_DEGRADED_LEN, uint8_t>(0b1 << l_lane);
                FAPI_TRY(fapi2::putScom(i_target, scomt::omi::D_REG_DL0_CONFIG1, l_buffer));
                l_buffer.flush<0>();
            }
        }
    }

    FAPI_ASSERT(!l_disabled_lanes,
                fapi2::IO_PPE_UNDEGRADE_FAIL()
                .set_TARGET(i_target)
                .set_DISABLED_LANES(l_disabled_lanes),
                "IO PPE undegrade attempt failed. Disabled lanes 0x%8X", l_disabled_lanes);

fapi_try_exit:
    FAPI_DBG("End ody_omi_degrade");
    return fapi2::current_err;
}
