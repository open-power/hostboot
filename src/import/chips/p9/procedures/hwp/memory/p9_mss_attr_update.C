/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_attr_update.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_mss_attr_update.C
/// @brief Programatic over-rides related to effective config
///
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <mss.H>
#include <lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>
#include <p9_mss_attr_update.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_PROC_CHIP;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::FAPI2_RC_SUCCESS;

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// expected field size 255B
constexpr uint32_t CRP0_Lx_RECORD_SIZE_EXP = 255;

// offset of keyword version information
constexpr uint8_t Lx_VERSION_OFFSET = 0;
constexpr uint8_t Lx_V2_VALUE = 2;
constexpr uint8_t Lx_V1_VALUE = 1;
constexpr uint8_t Lx_V0_VALUE = 0;

// Lx version 1 parsing/extraction constants
// group offsets within section
constexpr uint8_t Lx_V1_S_OFFSET_TO_G0 = 2;
constexpr uint8_t Lx_V1_S_OFFSET_TO_G1 = 34;
// data offsets within group (0)
constexpr uint8_t Lx_V1_G0_OFFSET_TO_VALID = 0;
constexpr uint8_t Lx_V1_G0_OFFSET_TO_FWMS[mss::MARK_STORE_COUNT] = { 1, 4, 7, 10, 13, 16, 19, 22 };
constexpr uint8_t Lx_V1_G0_OFFSET_TO_VREF_DAC = 25;
constexpr uint8_t Lx_V1_G0_OFFSET_TO_VDDR_BIAS = 26;
// data offsets within group (1)
constexpr uint8_t Lx_V1_G1_OFFSET_TO_VALID = 0;
constexpr uint8_t Lx_V1_G1_OFFSET_TO_DPHY_RLO = 1;
constexpr uint8_t Lx_V1_G1_OFFSET_TO_TSYS_ADR = 2;
constexpr uint8_t Lx_V1_G1_OFFSET_TO_TSYS_DATA = 3;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Given target and memory frequency, return MVPD Lx keyword and
///        offset to first byte in frequency-specific customization section
/// @param[in] i_target the port target (e.g., MCA)
/// @param[out] o_keyword Lx keyword ID for this port
/// @param[out] o_s_offset frequency-specific section byte offset
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update_get_lx_offsets(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                  fapi2::MvpdKeyword& o_keyword,
                                  uint8_t& o_s_offset)
{
    FAPI_DBG("%s Start p9_mss_attr_update_get_lx_offsets", mss::c_str(i_target));

    switch( mss::pos(i_target) )
    {
        case 0:
            o_keyword = fapi2::MVPD_KEYWORD_L1;
            break;

        case 1:
            o_keyword = fapi2::MVPD_KEYWORD_L2;
            break;

        case 2:
            o_keyword = fapi2::MVPD_KEYWORD_L3;
            break;

        case 3:
            o_keyword = fapi2::MVPD_KEYWORD_L4;
            break;

        case 4:
            o_keyword = fapi2::MVPD_KEYWORD_L5;
            break;

        case 5:
            o_keyword = fapi2::MVPD_KEYWORD_L6;
            break;

        case 6:
            o_keyword = fapi2::MVPD_KEYWORD_L7;
            break;

        case 7:
            o_keyword = fapi2::MVPD_KEYWORD_L8;
            break;

        default:
            // Can't actually happen and if it did it's a huge programming error elsewhere.
            // We test for this in the CI tests, too, to make sure this assertion is a good one.
            FAPI_ERR("Unknown port position %d in p9_mss_attr_update_get_lx_offsets", mss::pos(i_target));
            fapi2::Assert(false);
            break;
    };

    uint64_t l_freq = 0;

    FAPI_TRY( mss::freq(mss::find_target<TARGET_TYPE_MCBIST>(i_target), l_freq) );

    switch (l_freq)
    {
        case (fapi2::ENUM_ATTR_MSS_FREQ_MT2666):
            o_s_offset = Lx_V1_R_OFFSET_TO_F3S;
            break;

        case (fapi2::ENUM_ATTR_MSS_FREQ_MT2400):
            o_s_offset = Lx_V1_R_OFFSET_TO_F2S;
            break;

        case (fapi2::ENUM_ATTR_MSS_FREQ_MT2133):
            o_s_offset = Lx_V1_R_OFFSET_TO_F1S;
            break;

        case (fapi2::ENUM_ATTR_MSS_FREQ_MT1866):
            o_s_offset = Lx_V1_R_OFFSET_TO_F0S;
            break;

        default:
            // Can't actually happen and if it did it's a huge programming error elsewhere.
            FAPI_ERR("Invalid MSS frequency in p9_mss_attr_update_get_lx_offsets");
            fapi2::Assert(false);
            break;
    }

fapi_try_exit:
    FAPI_DBG("End p9_mss_attr_update_get_lx_offsets");
    return fapi2::current_err;
}

///
/// @brief Set ATTR_MSS_MVPD_FWMS from MVPD Lx keyword
/// @param[in] i_target, the port target (e.g., MCA)
/// @param[in] i_record_data, pointer to VPD keyword data
/// @parmm[in] i_f_s_offset, byte offset to frequency-specific section
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update_fwms(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                        const uint8_t* i_record_data,
                        const uint8_t i_f_s_offset)
{
    FAPI_DBG("Start p9_mss_attr_update_fwms");

    // if group is valid, update attribute value associated with this port
    if (i_record_data[i_f_s_offset +
                      Lx_V1_S_OFFSET_TO_G0 +
                      Lx_V1_G0_OFFSET_TO_VALID])
    {
        fapi2::ATTR_MSS_MVPD_FWMS_Type l_fwms;
        const auto& l_mcs_target = mss::find_target<TARGET_TYPE_MCS>(i_target);
        const auto l_index = mss::index(i_target);

        // read current attribute value
        FAPI_TRY( mss::mvpd_fwms(l_mcs_target, &(l_fwms[0][0])) );

        // update attribute value for this port
        for (size_t l_ms = 0; l_ms < mss::MARK_STORE_COUNT; l_ms++)
        {
            uint8_t l_offset_to_fwms =
                i_f_s_offset +                  // offset to section
                Lx_V1_S_OFFSET_TO_G0 +          // offset to group
                Lx_V1_G0_OFFSET_TO_FWMS[l_ms];  // offset to mark

            // clear value, build final value for this index
            l_fwms[l_index][l_ms] = 0;
            l_fwms[l_index][l_ms] |= (i_record_data[l_offset_to_fwms++] << 16);
            l_fwms[l_index][l_ms] |= (i_record_data[l_offset_to_fwms++] << 8);
            l_fwms[l_index][l_ms] |= (i_record_data[l_offset_to_fwms]);
        }

        // update attribute value
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_MVPD_FWMS, l_mcs_target, l_fwms),
                 "Error from FAPI_ATTR_SET (ATTR_MSS_MVPD_FWMS) on target: %s",
                 mss::c_str(l_mcs_target));
    }

fapi_try_exit:
    FAPI_DBG("End p9_mss_attr_update_fwms");
    return fapi2::current_err;
}

///
/// @brief Set ATTR_MSS_VREF_DAC_NIBBLE from MVPD Lx keyword
/// @param[in] i_target, the port target (e.g., MCA)
/// @param[in] i_record_data, pointer to VPD keyword data
/// @parmm[in] i_f_s_offset, byte offset to frequency-specific section
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update_dac_nibble(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                              const uint8_t* i_record_data,
                              const uint8_t i_f_s_offset)
{
    FAPI_DBG("Start p9_mss_attr_update_dac_nibble");

    // if group is valid, update attribute value associated with this port
    if (i_record_data[i_f_s_offset +
                      Lx_V1_S_OFFSET_TO_G0 +
                      Lx_V1_G0_OFFSET_TO_VALID])
    {
        fapi2::ATTR_MSS_VREF_DAC_NIBBLE_Type l_vref_dac_nibble;
        const auto& l_mcs_target = mss::find_target<TARGET_TYPE_MCS>(i_target);

        // read current attribute value
        FAPI_TRY( mss::vref_dac_nibble(l_mcs_target, l_vref_dac_nibble) );

        // update attribute value for this port
        l_vref_dac_nibble[mss::index(i_target)] =
            i_record_data[i_f_s_offset +                  // offset to section
                          Lx_V1_S_OFFSET_TO_G0 +          // offset to group
                          Lx_V1_G0_OFFSET_TO_VREF_DAC];   // offset to data

        // update attribute value
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_VREF_DAC_NIBBLE, l_mcs_target, l_vref_dac_nibble),
                 "Error from FAPI_ATTR_SET (ATTR_MSS_VREF_DAC_NIBBLE) on target: %s",
                 mss::c_str(l_mcs_target));
    }

fapi_try_exit:
    FAPI_DBG("End p9_mss_attr_update_dac_nibble");
    return fapi2::current_err;
}

///
/// @brief Set ATTR_MSS_VOLT_VDDR from MVPD Lx keyword
/// @param[in] i_target, the port target (e.g., MCA)
/// @param[in] i_record_data, pointer to VPD keyword data
/// @parmm[in] i_f_s_offset, byte offset to frequency-specific section
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update_vddr(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                        const uint8_t* i_record_data,
                        const uint8_t i_f_s_offset)
{
    FAPI_DBG("Start p9_mss_attr_update_vddr");

    // if group is valid, update attribute value associated with this port
    if (i_record_data[i_f_s_offset +
                      Lx_V1_S_OFFSET_TO_G0 +
                      Lx_V1_G0_OFFSET_TO_VALID])
    {
        fapi2::ATTR_MSS_VOLT_VDDR_Type l_mss_volt_vddr;
        const auto& l_mcbist_target = mss::find_target<TARGET_TYPE_MCBIST>(i_target);

        // update attribute value for this port
        l_mss_volt_vddr =
            i_record_data[i_f_s_offset +                    // offset to section
                          Lx_V1_S_OFFSET_TO_G0 +            // offset to group
                          Lx_V1_G0_OFFSET_TO_VDDR_BIAS];    // offset to data (byte 0)
        l_mss_volt_vddr = l_mss_volt_vddr << 8;

        l_mss_volt_vddr |=
            i_record_data[i_f_s_offset +                    // offset to section
                          Lx_V1_S_OFFSET_TO_G0 +            // offset to group
                          Lx_V1_G0_OFFSET_TO_VDDR_BIAS + 1]; // offset to data (byte 1)

        // update attribute value
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_VOLT_VDDR, l_mcbist_target, l_mss_volt_vddr),
                 "Error from FAPI_ATTR_SET (ATTR_MSS_VOLT_VDDR) on target: %s",
                 mss::c_str(l_mcbist_target));
    }

fapi_try_exit:
    FAPI_DBG("End p9_mss_attr_update_vddr");
    return fapi2::current_err;
}

///
/// @brief Set ATTR_MSS_VPD_MR_DPHY_RLO from MVPD Lx keyword
/// @param[in] i_target, the port target (e.g., MCA)
/// @param[in] i_record_data, pointer to VPD keyword data
/// @parmm[in] i_f_s_offset, byte offset to frequency-specific section
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update_dphy_rlo(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                            const uint8_t* i_record_data,
                            const uint8_t i_f_s_offset)
{
    FAPI_DBG("Start p9_mss_attr_update_dphy_rlo");

    // if group is valid, update attribute value associated with this port
    if (i_record_data[i_f_s_offset +
                      Lx_V1_S_OFFSET_TO_G0 +
                      Lx_V1_G1_OFFSET_TO_VALID])
    {
        fapi2::ATTR_MSS_VPD_MR_DPHY_RLO_Type l_vpd_mr_dphy_rlo;
        const auto& l_mcs_target = mss::find_target<TARGET_TYPE_MCS>(i_target);

        // read current attribute value
        FAPI_TRY( mss::vpd_mr_dphy_rlo(l_mcs_target, l_vpd_mr_dphy_rlo) );

        // update attribute value for this port
        l_vpd_mr_dphy_rlo[mss::index(i_target)] =
            i_record_data[i_f_s_offset +                  // offset to section
                          Lx_V1_S_OFFSET_TO_G1 +          // offset to group
                          Lx_V1_G1_OFFSET_TO_DPHY_RLO];   // offset to data

        // update attribute value
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_DPHY_RLO, l_mcs_target, l_vpd_mr_dphy_rlo),
                 "Error from FAPI_ATTR_SET (ATTR_MSS_VPD_MR_DPHY_RLO) on target: %s",
                 mss::c_str(l_mcs_target));
    }

fapi_try_exit:
    FAPI_DBG("End p9_mss_attr_update_dphy_rlo");
    return fapi2::current_err;
}


///
/// @brief Set ATTR_MSS_VPD_MR_TSYS_ADR from MVPD Lx keyword
/// @param[in] i_target, the port target (e.g., MCA)
/// @param[in] i_record_data, pointer to VPD keyword data
/// @parmm[in] i_f_s_offset, byte offset to frequency-specific section
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update_tsys_adr(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                            const uint8_t* i_record_data,
                            const uint8_t i_f_s_offset)
{
    FAPI_DBG("Start p9_mss_attr_update_tsys_adr");

    // if group is valid, update attribute value associated with this port
    if (i_record_data[i_f_s_offset +
                      Lx_V1_S_OFFSET_TO_G0 +
                      Lx_V1_G1_OFFSET_TO_VALID])
    {
        fapi2::ATTR_MSS_VPD_MR_TSYS_ADR_Type l_vpd_mr_tsys_adr;
        const auto& l_mcs_target = mss::find_target<TARGET_TYPE_MCS>(i_target);

        // update attribute value for this port
        l_vpd_mr_tsys_adr =
            i_record_data[i_f_s_offset +                  // offset to section
                          Lx_V1_S_OFFSET_TO_G1 +          // offset to group
                          Lx_V1_G1_OFFSET_TO_TSYS_ADR];   // offset to data

        // update attribute value
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_TSYS_ADR, l_mcs_target, l_vpd_mr_tsys_adr),
                 "Error from FAPI_ATTR_SET (ATTR_MSS_VPD_MR_TSYS_ADR) on target: %s",
                 mss::c_str(l_mcs_target));
    }

fapi_try_exit:
    FAPI_DBG("End p9_mss_attr_update_tsys_adr");
    return fapi2::current_err;
}

///
/// @brief Set ATTR_MSS_VPD_MR_TSYS_DATA from MVPD Lx keyword
/// @param[in] i_target, the port target (e.g., MCA)
/// @param[in] i_record_data, pointer to VPD keyword data
/// @parmm[in] i_f_s_offset, byte offset to frequency-specific section
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update_tsys_data(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                             const uint8_t* i_record_data,
                             const uint8_t i_f_s_offset)
{
    FAPI_DBG("Start p9_mss_attr_update_tsys_data");

    // if group is valid, update attribute value associated with this port
    if (i_record_data[i_f_s_offset +
                      Lx_V1_S_OFFSET_TO_G0 +
                      Lx_V1_G1_OFFSET_TO_VALID])
    {
        fapi2::ATTR_MSS_VPD_MR_TSYS_DATA_Type l_vpd_mr_tsys_data;
        const auto& l_mcs_target = mss::find_target<TARGET_TYPE_MCS>(i_target);

        // update attribute value for this port
        l_vpd_mr_tsys_data =
            i_record_data[i_f_s_offset +                   // offset to section
                          Lx_V1_S_OFFSET_TO_G1 +           // offset to group
                          Lx_V1_G1_OFFSET_TO_TSYS_DATA];   // offset to data

        // update attribute value
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_TSYS_DATA, l_mcs_target, l_vpd_mr_tsys_data),
                 "Error from FAPI_ATTR_SET (ATTR_MSS_VPD_MR_TSYS_DATA) on target: %s",
                 mss::c_str(l_mcs_target));
    }

fapi_try_exit:
    FAPI_DBG("End p9_mss_attr_update_tsys_data");
    return fapi2::current_err;
}


///
/// @brief Apply chip specific overrides from module VPD
/// @param[in] i_target, the port target (e.g., MCA)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update_lx_mvpd(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    FAPI_INF("Start p9_mss_attr_update_lx_mvpd");

    uint32_t l_keyword_size;
    uint8_t l_keyword_data[CRP0_Lx_RECORD_SIZE_EXP];
    fapi2::MvpdKeyword l_keyword;
    uint8_t l_section_offset;
    const auto& l_chip_target = mss::find_target<TARGET_TYPE_PROC_CHIP>(i_target);

    // determine keyword/section offset for lookup
    FAPI_TRY(p9_mss_attr_update_get_lx_offsets(i_target, l_keyword, l_section_offset),
             "Error from p9_mss_attr_update_lx_mvpd_offsets");

    // check VPD field size
    FAPI_TRY(fapi2::getMvpdField(fapi2::MVPD_RECORD_CRP0,
                                 l_keyword,
                                 l_chip_target,
                                 NULL,
                                 l_keyword_size),
             "Error from getMvpdField (CRP0, keyword:%d, size check) on target: %s",
             l_keyword, mss::c_str(l_chip_target));

    FAPI_ASSERT(l_keyword_size == CRP0_Lx_RECORD_SIZE_EXP,
                fapi2::P9_MSS_ATTR_UPDATE_MVPD_READ_ERR()
                .set_CHIP_TARGET(l_chip_target)
                .set_KEYWORD_SIZE(l_keyword_size),
                "Invalid CRP0 keyword:%d record size (%s)",
                l_keyword, mss::c_str(l_chip_target));

    // retrieve data
    FAPI_TRY(fapi2::getMvpdField(fapi2::MVPD_RECORD_CRP0,
                                 l_keyword,
                                 l_chip_target,
                                 l_keyword_data,
                                 l_keyword_size),
             "Error from getMvpdField (CRP0, keyword:%d, retrieval) on target: %s",
             l_keyword, mss::c_str(l_chip_target));

    // check version number, currently all supported versions use the same offsets
    // for the purpose of this HWP
    FAPI_ASSERT(((l_keyword_data[Lx_VERSION_OFFSET] == Lx_V0_VALUE) ||
                 (l_keyword_data[Lx_VERSION_OFFSET] == Lx_V1_VALUE) ||
                 (l_keyword_data[Lx_VERSION_OFFSET] == Lx_V2_VALUE)),
                fapi2::P9_MSS_ATTR_UPDATE_MVPD_VERSION_ERR().
                set_CHIP_TARGET(l_chip_target).
                set_VERSION(l_keyword_data[Lx_VERSION_OFFSET]),
                "Invalid CRP0 keyword:%d record version: %02X (%s)",
                l_keyword, l_keyword_data[Lx_VERSION_OFFSET], mss::c_str(l_chip_target));

    // update from frequency specific areas
    FAPI_TRY(p9_mss_attr_update_fwms(i_target, l_keyword_data, l_section_offset),
             "Error from p9_mss_attr_update_fwms");
    FAPI_TRY(p9_mss_attr_update_dac_nibble(i_target, l_keyword_data, l_section_offset),
             "Error from p9_mss_attr_update_dac_nibble");
    FAPI_TRY(p9_mss_attr_update_vddr(i_target, l_keyword_data, l_section_offset),
             "Error from p9_mss_attr_update_vddr");
    FAPI_TRY(p9_mss_attr_update_dphy_rlo(i_target, l_keyword_data, l_section_offset),
             "Error from p9_mss_attr_update_dphy_rlo");
    FAPI_TRY(p9_mss_attr_update_tsys_adr(i_target, l_keyword_data, l_section_offset),
             "Error from p9_mss_attr_update_tsys_adr");
    FAPI_TRY(p9_mss_attr_update_tsys_data(i_target, l_keyword_data, l_section_offset),
             "Error from p9_mss_attr_update_tsys_data");

fapi_try_exit:
    FAPI_INF("End p9_mss_attr_update_lx_mvpd");
    return fapi2::current_err;
}


///
/// @brief Programatic over-rides related to effective config, including data
///        from module VPD
/// @param[in] i_target, the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9_mss_attr_update(const fapi2::Target<TARGET_TYPE_MCS>& i_target)
{
    FAPI_INF("%s Start p9_mss_attr_update", mss::c_str(i_target) );

    // if there are no DIMM, exit
    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("Seeing no DIMM on %s, no attribute overrides to set", mss::c_str(i_target));
        return FAPI2_RC_SUCCESS;
    }

    // apply MPVD overrides per MCA port
    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        FAPI_TRY(p9_mss_attr_update_lx_mvpd(p),
                 "Error from p9_mss_attr_update_lx_mvpd (target: %s)", mss::c_str(p));
    }

fapi_try_exit:
    FAPI_INF("%s End p9_mss_attr_update", mss::c_str(i_target) );
    return fapi2::current_err;
}
