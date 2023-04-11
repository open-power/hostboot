/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_tx_zcal.C $ */
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
///------------------------------------------------------------------------------
/// @file ody_omi_hss_tx_zcal.C
/// @brief Odyssey HWP that runs TDR on links
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_tx_zcal.H>
#include <common_io_omi_tdr.H>
#include <io_scom_lib.H>
#include <ody_scom_omi.H>
#include <ody_io_ppe_common.H>
#include <fapi2_subroutine_executor.H>

// Structures

enum ody_omi_tx_zcal
{
    ODY_OMI_TX_ZCAL_PRE1 = 0,
    ODY_OMI_TX_ZCAL_PRE2 = 1,
    ODY_OMI_TX_ZCAL_POST = 2,
    ODY_OMI_TX_ZCAL_MAIN = 3,
    ODY_OMI_TX_ZCAL_ALL  = 4,
};

constexpr uint64_t pSegRegisters[] =
{
    0x08E8,
    0x08D8,
    0x0988,
    0x0898
};

constexpr uint64_t nSegRegisters[] =
{
    0x0908,
    0x08F8,
    0x0998,
    0x08A8
};

constexpr uint8_t segLens[] =
{
    5,
    5,
    9,
    16
};

constexpr uint8_t segHas2R[] =
{
    1,
    1,
    0,
    1
};


inline uint32_t decodeSegs(uint32_t i_segs, uint8_t i_length, uint8_t i_has2r)
{
    uint32_t r_num2rSegs = 0;

    uint32_t l_1r_mask = (0x1 << i_length) - 1;
    uint32_t l_2r_mask = 0;

    if (i_has2r)
    {
        l_2r_mask = (0x1 << (i_length - 1));
        l_1r_mask &= ~l_2r_mask;
    }

    // // only checking the last 3B
    // i_segs &= 0x000001FF;

    r_num2rSegs += (l_2r_mask & i_segs) ? 1 : 0;
    i_segs &= l_1r_mask;

    while(i_segs)
    {
        r_num2rSegs += (i_segs & 0x1) ? 2 : 0;
        i_segs >>= 1;
    }

    return r_num2rSegs;
}

fapi2::ReturnCode forceZCalToDefault(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const uint64_t i_baseAddr,
                                     const uint32_t i_group,
                                     const uint32_t i_lane)
{
    FAPI_DBG("Start - Setting Z Cal to Defaults");

    constexpr uint32_t c_preVal = 0x00F;
    constexpr uint32_t c_postVal = 0x1FF;
    constexpr uint32_t c_mainVal = 0x1FF;
    constexpr uint32_t c_startBit = 48;

    fapi2::buffer<uint64_t> l_buffer;

    uint64_t l_addr = 0;

    // Set P Pre1
    FAPI_DBG("Setting P Pre1 0x%x", c_preVal);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, pSegRegisters[ODY_OMI_TX_ZCAL_PRE1]);
    l_buffer.flush<0>();
    l_buffer.insertFromRight<c_startBit, segLens[ODY_OMI_TX_ZCAL_PRE1]>(c_preVal);
    FAPI_TRY(putScom(i_target, l_addr, l_buffer), "Error putscom to address 0x%08X.", l_addr);

    // Set P Pre2
    FAPI_DBG("Setting P Pre2 0x%x", c_preVal);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, pSegRegisters[ODY_OMI_TX_ZCAL_PRE2]);
    l_buffer.flush<0>();
    l_buffer.insertFromRight<c_startBit, segLens[ODY_OMI_TX_ZCAL_PRE2]>(c_preVal);
    FAPI_TRY(putScom(i_target, l_addr, l_buffer), "Error putscom to address 0x%08X.", l_addr);

    // Set P Post
    FAPI_DBG("Setting P Post 0x%x", c_postVal);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, pSegRegisters[ODY_OMI_TX_ZCAL_POST]);
    l_buffer.flush<0>();
    l_buffer.insertFromRight<c_startBit, segLens[ODY_OMI_TX_ZCAL_POST]>(c_postVal);
    FAPI_TRY(putScom(i_target, l_addr, l_buffer), "Error putscom to address 0x%08X.", l_addr);

    // Set P Main
    FAPI_DBG("Setting P Main 0x%x", c_mainVal);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, pSegRegisters[ODY_OMI_TX_ZCAL_MAIN]);
    l_buffer.flush<0>();
    l_buffer.insertFromRight<c_startBit, segLens[ODY_OMI_TX_ZCAL_MAIN]>(c_mainVal);
    FAPI_TRY(putScom(i_target, l_addr, l_buffer), "Error putscom to address 0x%08X.", l_addr);

    // Set N Pre1
    FAPI_DBG("Setting N Pre1 0x%x", c_preVal);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, nSegRegisters[ODY_OMI_TX_ZCAL_PRE1]);
    l_buffer.flush<0>();
    l_buffer.insertFromRight<c_startBit, segLens[ODY_OMI_TX_ZCAL_PRE1]>(c_preVal);
    FAPI_TRY(putScom(i_target, l_addr, l_buffer), "Error putscom to address 0x%08X.", l_addr);

    // Set N Pre2
    FAPI_DBG("Setting N Pre2 0x%x", c_preVal);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, nSegRegisters[ODY_OMI_TX_ZCAL_PRE2]);
    l_buffer.flush<0>();
    l_buffer.insertFromRight<c_startBit, segLens[ODY_OMI_TX_ZCAL_PRE2]>(c_preVal);
    FAPI_TRY(putScom(i_target, l_addr, l_buffer), "Error putscom to address 0x%08X.", l_addr);

    // Set N Post
    FAPI_DBG("Setting N Post 0x%x", c_postVal);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, nSegRegisters[ODY_OMI_TX_ZCAL_POST]);
    l_buffer.flush<0>();
    l_buffer.insertFromRight<c_startBit, segLens[ODY_OMI_TX_ZCAL_POST]>(c_postVal);
    FAPI_TRY(putScom(i_target, l_addr, l_buffer), "Error putscom to address 0x%08X.", l_addr);

    // Set N Main
    FAPI_DBG("Setting N Main 0x%x", c_mainVal);
    l_addr = buildAddr(i_baseAddr, i_group, i_lane, nSegRegisters[ODY_OMI_TX_ZCAL_MAIN]);
    l_buffer.flush<0>();
    l_buffer.insertFromRight<c_startBit, segLens[ODY_OMI_TX_ZCAL_MAIN]>(c_mainVal);
    FAPI_TRY(putScom(i_target, l_addr, l_buffer), "Error putscom to address 0x%08X.", l_addr);

fapi_try_exit:
    FAPI_DBG("End - Setting Z Cal to Defaults");
    return fapi2::current_err;
}

fapi2::ReturnCode verifyZCal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             const uint64_t i_baseAddr,
                             const uint32_t i_group,
                             const uint32_t i_lane)
{
    FAPI_DBG("Start - Verifying Z Cal");

    const uint8_t c_minSegs = 20 << 1; // 2R Min
    const uint8_t c_maxSegs = 32 << 1; // 2R Max
    const uint8_t c_segBit = 48;

    uint64_t l_addr = 0;
    uint32_t l_data = 0;
    uint8_t l_totalPSegs = 0;
    uint8_t l_totalNSegs = 0;

    // Checks each P segment values.
    for (uint8_t l_index = ODY_OMI_TX_ZCAL_PRE1; l_index < ODY_OMI_TX_ZCAL_ALL; l_index++)
    {
        l_data = 0;
        FAPI_DBG("Psegs Address 0x%08X, Group %d, Lane %d, Reg 0x%x", i_baseAddr, i_group, i_lane, pSegRegisters[l_index]);
        l_addr = buildAddr(i_baseAddr, i_group, i_lane, pSegRegisters[l_index]);
        FAPI_TRY(readIoHardwareReg(i_target, l_addr, c_segBit, segLens[l_index], l_data));
        l_totalPSegs += decodeSegs(l_data, segLens[l_index], segHas2R[l_index]);
    }

    FAPI_DBG("Total P Segs %d", l_totalPSegs);

    // Checks each N segment values.
    for (uint8_t l_index = ODY_OMI_TX_ZCAL_PRE1; l_index < ODY_OMI_TX_ZCAL_ALL; l_index++)
    {
        l_data = 0;
        FAPI_DBG("Nsegs Address 0x%08X, Group %d, Lane %d, Reg 0x%x", i_baseAddr, i_group, i_lane, nSegRegisters[l_index]);
        l_addr = buildAddr(i_baseAddr, i_group, i_lane, nSegRegisters[l_index]);
        FAPI_TRY(readIoHardwareReg(i_target, l_addr, c_segBit, segLens[l_index], l_data));
        l_totalNSegs += decodeSegs(l_data, segLens[l_index], segHas2R[l_index]);
    }

    FAPI_DBG("Total N Segs %d", l_totalNSegs);

    // Check if the number of segements is within the thresholds
    if ((c_minSegs > l_totalPSegs) || (l_totalPSegs > c_maxSegs) ||
        (c_minSegs > l_totalNSegs) || (l_totalNSegs > c_maxSegs))
    {
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::TX_ZCAL_WRONG_SEGS()
                           .set_TARGET_CHIP(i_target)
                           .set_MIN_SEGS(c_minSegs)
                           .set_MAX_SEGS(c_maxSegs)
                           .set_P_SEGS(l_totalPSegs)
                           .set_N_SEGS(l_totalNSegs)
                           .set_LANE(i_lane),
                           "Failed Z Cal - Number of segments is outisde of range P(%d) | N(%d) on lane %d",
                           l_totalPSegs, l_totalNSegs, i_lane);
        // Force value of 25 on leg
        FAPI_TRY(forceZCalToDefault(i_target, i_baseAddr, i_group, i_lane));
    }

fapi_try_exit:
    FAPI_DBG("End - Verifying Z Cal");
    return fapi2::current_err;
}

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_tx_zcal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start");

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys;
    const uint8_t l_numLanes = 8;
    fapi2::ATTR_OMI_TX_LANES_Type l_tx_lanes = 0;
    fapi2::ATTR_IS_SIMULATION_Type l_sim = 0;
    fapi2::ATTR_IS_SIMICS_Type l_simics = fapi2::ENUM_ATTR_IS_SIMICS_REALHW;
    fapi2::ATTR_MSS_IS_APOLLO_Type l_is_apollo;
    uint32_t l_lane = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_TX_LANES, i_target, l_tx_lanes));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, l_sys, l_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, l_sys, l_simics));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_IS_APOLLO, l_sys, l_is_apollo));

    for (l_lane = 0; l_lane < l_numLanes; l_lane++)
    {
        if ((0x80000000 >> l_lane) & l_tx_lanes)
        {
            FAPI_DBG("Lane %d", l_lane);
            // verify zCal & force it to be 25
            verifyZCal(i_target, PHY_ODY_OMI_BASE, 0, l_lane);
        }
    }

    if (!l_sim && !l_is_apollo && !(l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS))
    {
        fapi2::ATTR_FREQ_OMI_MHZ_Type l_freq;

        FAPI_DBG("Zcal");
        // Run TDR isolation
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_freq));
        FAPI_TRY(common_io_omi_tdr(i_target, l_freq, PHY_ODY_OMI_BASE),
                 "Error on TDR isolation");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
