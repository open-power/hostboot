/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_omi_isolation.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_omi_isolation.C
/// @brief Isolate OMI failure to callout proc as needed
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HWSV
///-----------------------------------------------------------------------------
// EKB-Mirror-To: hostboot

#include <p10_omi_isolation.H>
#include <p10_scom_omic.H>
#include <p10_scom_omi.H>

int p10_omi_isolation_twos_comp(uint64_t i_val, uint64_t i_bits)
{
    FAPI_DBG("Begin");
    int l_val = i_val;
    int l_bits = i_bits;

    if ((l_val & (1 << (l_bits - 1))) != 0)
    {
        l_val = l_val - (1 << l_bits);
    }

    FAPI_DBG("End val: %d", l_val);
    return l_val;
}

//setupGroupRegs
fapi2::ReturnCode p10_omi_isolation_setup(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
        std::vector<uint64_t>& l_lanes)
{
    FAPI_DBG("Begin");
    using namespace scomt::omic;

    fapi2::buffer<uint64_t> l_data;

    auto l_omic_target = i_omi_target.getParent<fapi2::TARGET_TYPE_OMIC>();

    // Tx HS Bist Enable = 0
    FAPI_TRY(PREP_CTL_REGS_TX_MODE1_PG(l_omic_target));
    FAPI_TRY(fapi2::getScom(l_omic_target, CTL_REGS_TX_MODE1_PG, l_data));
    SET_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(0, l_data);
    FAPI_TRY(fapi2::putScom(l_omic_target, CTL_REGS_TX_MODE1_PG, l_data));

    //c_tx_tdr_pulse_width
    l_data = 0;
    FAPI_TRY(PREP_CTL_REGS_TX_CNTL6_PG(l_omic_target));
    SET_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(100, l_data);
    FAPI_TRY(PUT_CTL_REGS_TX_CNTL6_PG(l_omic_target, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

//restoreGroupRegs
fapi2::ReturnCode p10_omi_isolation_restore(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
        std::vector<uint64_t>& l_lanes)
{
    FAPI_DBG("Begin");
    using namespace scomt::omic;

    fapi2::buffer<uint64_t> l_data = 0;

    auto l_omic_target = i_omi_target.getParent<fapi2::TARGET_TYPE_OMIC>();

    //c_tx_tdr_pulse_width
    l_data = 0;
    FAPI_TRY(PREP_CTL_REGS_TX_CNTL6_PG(l_omic_target));
    SET_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(0, l_data);
    FAPI_TRY(PUT_CTL_REGS_TX_CNTL6_PG(l_omic_target, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

//_tdrTest
fapi2::ReturnCode p10_omi_isolation_tdr_test(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
        uint64_t i_lane, int i_phase, uint64_t i_dac, bool i_expect, TdrStruct& o_result)
{
    FAPI_DBG("Begin");
    using namespace scomt::omic;
    using namespace scomt::omi;

    const uint64_t DAC_DELAY_NS = 100000;
    const uint64_t DAC_DELAY_SIM_CYCLES = 1000000;

    bool l_actual = 0;
    uint64_t l_addr = 0;
    fapi2::buffer<uint64_t> l_data = 0;
    auto l_omic_target = i_omi_target.getParent<fapi2::TARGET_TYPE_OMIC>();



    //c_tx_tdr_dac_cntl
    FAPI_TRY(PREP_CTL_REGS_TX_CNTL4_PG(l_omic_target));
    SET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(i_dac, l_data);

    if (i_phase)
    {
        SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(l_data);
    }

    FAPI_TRY(PUT_CTL_REGS_TX_CNTL4_PG(l_omic_target, l_data));

    fapi2::delay(DAC_DELAY_NS, DAC_DELAY_SIM_CYCLES);

    //c_tx_tdr_capt_val
    l_addr = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL | (i_lane << 32);
    FAPI_TRY(fapi2::getScom(i_omi_target, l_addr, l_data));

    l_actual = l_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL>();

    if (i_expect != l_actual)
    {
        FAPI_DBG("Tdr tx fail i_expect: %d l_actual: %d", i_expect, l_actual);
        o_result.iv_status = TdrResult::Open;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

//runTdrTest
fapi2::ReturnCode p10_omi_isolation_run_tdr(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
        uint64_t i_lane,  TdrStruct& o_result)
{
    FAPI_DBG("Begin");
    using namespace scomt::omic;
    using namespace scomt::omi;

    uint64_t l_c_offset_width = 6400;
    uint64_t l_c_upper_max = 232; //# +40
    uint64_t l_c_upper_min = 152; //# -40
    uint64_t l_c_lower_max = 103; //# +40
    uint64_t l_c_lower_min = 23;  //# -40
    uint64_t l_offset_3 = (l_c_offset_width * 3) / 8;
    uint64_t l_offset_7 = (l_c_offset_width * 7) / 8;
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0;

    auto l_omic_target = i_omi_target.getParent<fapi2::TARGET_TYPE_OMIC>();


    //c_tx_tdr_enable
    l_data = 0;
    l_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
    l_addr = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL | (i_lane << 32);
    FAPI_TRY(fapi2::putScom(i_omi_target, l_addr, l_data));

    //c_tx_lane_invert
    l_data = 0;
    l_addr = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL | (i_lane << 32);
    FAPI_TRY(fapi2::putScom(i_omi_target, l_addr, l_data));

    for (int l_phase = 0; l_phase < 2; l_phase++)
    {
        l_data = 0;
        FAPI_TRY(PREP_CTL_REGS_TX_CNTL5_PG(l_omic_target));
        SET_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(l_offset_3, l_data);
        FAPI_TRY(PUT_CTL_REGS_TX_CNTL5_PG(l_omic_target, l_data));

        if (l_phase == 0)
        {
            FAPI_TRY(p10_omi_isolation_tdr_test(i_omi_target, i_lane, l_phase, l_c_upper_min, true , o_result));
            FAPI_TRY(p10_omi_isolation_tdr_test(i_omi_target, i_lane, l_phase, l_c_upper_max, false, o_result));
        }
        else
        {
            FAPI_TRY(p10_omi_isolation_tdr_test(i_omi_target, i_lane, l_phase, l_c_lower_min, true , o_result));
            FAPI_TRY(p10_omi_isolation_tdr_test(i_omi_target, i_lane, l_phase, l_c_lower_max, false, o_result));
        }

        l_data = 0;
        FAPI_TRY(PREP_CTL_REGS_TX_CNTL5_PG(l_omic_target));
        SET_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(l_offset_7, l_data);
        FAPI_TRY(PUT_CTL_REGS_TX_CNTL5_PG(l_omic_target, l_data));

        if (l_phase == 0)
        {
            FAPI_TRY(p10_omi_isolation_tdr_test(i_omi_target, i_lane, l_phase, l_c_lower_min, true , o_result));
            FAPI_TRY(p10_omi_isolation_tdr_test(i_omi_target, i_lane, l_phase, l_c_lower_max, false, o_result));
        }
        else
        {
            FAPI_TRY(p10_omi_isolation_tdr_test(i_omi_target, i_lane, l_phase, l_c_upper_min, true , o_result));
            FAPI_TRY(p10_omi_isolation_tdr_test(i_omi_target, i_lane, l_phase, l_c_upper_max, false, o_result));
        }
    }

    //c_tx_tdr_enable
    l_data = 0x0;
    l_addr = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL | (i_lane << 32);
    FAPI_TRY(fapi2::putScom(i_omi_target, l_addr, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Isolate OMI failure to callout proc as needed
///
/// @param[in]  i_target    OMI target called out
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_isolation(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
                                    std::vector<TdrStruct>& o_data)
{

    FAPI_DBG("Begin");

    std::vector<uint64_t> l_lanes;

    for (uint64_t l_lane = 0; l_lane < 8; l_lane++)
    {
        l_lanes.push_back(l_lane);
    }

    o_data.clear();

    FAPI_TRY(p10_omi_isolation_setup(i_omi_target, l_lanes));

    for (uint64_t l_lane : l_lanes)
    {
        TdrStruct l_result;
        l_result.iv_lane = l_lane;
        l_result.iv_status = TdrResult::Good;
        l_result.iv_length = 0;
        FAPI_TRY(p10_omi_isolation_run_tdr(i_omi_target, l_lane, l_result));
        o_data.push_back(l_result);
    }

    FAPI_TRY(p10_omi_isolation_restore(i_omi_target, l_lanes));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
