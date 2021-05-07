/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_attr_update.C $  */
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
/// @file p10_attr_update.C
/// @brief Stub HWP for FW to override attributes programmatically (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

///
/// *HW HW Maintainer: Nicholas Landi <nlandi@ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_attr_update.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// expected field size
constexpr uint32_t MER0_VD_KEYWORD_SIZE_EXP  = 2;
constexpr uint32_t MER0_PDI_KEYWORD_SIZE_EXP = 270;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Update attributes from module VPD MER0 #I
/// @param[in] i_target   Processor chip target
/// @return FAPI2_RC_SUCCESS, else error
///
fapi2::ReturnCode
p10_attr_update_mer0_pdI_mvpd(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    uint32_t l_keyword_size = 0;
    uint8_t l_vd_keyword_data[MER0_VD_KEYWORD_SIZE_EXP] = { 0 };
    uint8_t l_pdi_keyword_data[MER0_PDI_KEYWORD_SIZE_EXP] = { 0 };
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_target, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);

    // validate MER0 VD version
    FAPI_TRY(fapi2::getMvpdField(fapi2::MVPD_RECORD_MER0,
                                 fapi2::MVPD_KEYWORD_VD,
                                 i_target,
                                 NULL,
                                 l_keyword_size),
             "Error from getMvpdField (MER0, VD, size check) on target: %s",
             l_targetStr);

    FAPI_ASSERT(l_keyword_size == MER0_VD_KEYWORD_SIZE_EXP,
                fapi2::P10_ATTR_UPDATE_MVPD_READ_ERR()
                .set_TARGET(i_target)
                .set_KEYWORD(fapi2::MVPD_KEYWORD_VD)
                .set_KEYWORD_SIZE(l_keyword_size),
                "Invalid MER0 VD record size (%s)",
                l_targetStr);

    FAPI_TRY(fapi2::getMvpdField(fapi2::MVPD_RECORD_MER0,
                                 fapi2::MVPD_KEYWORD_VD,
                                 i_target,
                                 l_vd_keyword_data,
                                 l_keyword_size),
             "Error from getMvpdField (MER0, VD, retrieval) on target: %s",
             l_targetStr);

    if ((l_vd_keyword_data[0] == 0x30) &&
        (l_vd_keyword_data[1] == 0x31))
    {
        FAPI_DBG("MER0 VD keyword: 0x3031, will not process #I");
        goto fapi_try_exit;
    }
    else if ((l_vd_keyword_data[0] == 0x30) &&
             (l_vd_keyword_data[1]  > 0x31))
    {
        FAPI_DBG("MER0 VD keyword greater than 0x3031, will process #I");
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::P10_ATTR_UPDATE_VD_KEYWORD_VERSION_ERR()
                    .set_TARGET(i_target)
                    .set_VERSION((l_vd_keyword_data[0] << 8) | (l_vd_keyword_data[1])),
                    "Unsupported MER0 VD keyword content found: 0x%02X%02X",
                    l_vd_keyword_data[0],
                    l_vd_keyword_data[1]);
    }

    // process MER0 #I data
    FAPI_TRY(fapi2::getMvpdField(fapi2::MVPD_RECORD_MER0,
                                 fapi2::MVPD_KEYWORD_PDI,
                                 i_target,
                                 NULL,
                                 l_keyword_size),
             "Error from getMvpdField (MER0, PDI, size check) on target: %s",
             l_targetStr);

    FAPI_ASSERT(l_keyword_size == MER0_PDI_KEYWORD_SIZE_EXP,
                fapi2::P10_ATTR_UPDATE_MVPD_READ_ERR()
                .set_TARGET(i_target)
                .set_KEYWORD(fapi2::MVPD_KEYWORD_PDI)
                .set_KEYWORD_SIZE(l_keyword_size),
                "Invalid MER0 PDI record size (%s)",
                l_targetStr);

    FAPI_TRY(fapi2::getMvpdField(fapi2::MVPD_RECORD_MER0,
                                 fapi2::MVPD_KEYWORD_PDI,
                                 i_target,
                                 l_pdi_keyword_data,
                                 l_keyword_size),
             "Error from getMvpdField (MER0, PDI, retrieval) on target: %s",
             l_targetStr);

    // check header
    FAPI_ASSERT((l_pdi_keyword_data[0] == 0x42) &&
                (l_pdi_keyword_data[1] == 0x4C) &&
                (l_pdi_keyword_data[2] == 0x03) &&
                (l_pdi_keyword_data[3] == 0x03) &&
                (l_pdi_keyword_data[4] == 0x58),
                fapi2::P10_ATTR_UPDATE_PDI_KEYWORD_HEADER_ERR()
                .set_TARGET(i_target)
                .set_HEADER_B0(l_pdi_keyword_data[0])
                .set_HEADER_B1(l_pdi_keyword_data[1])
                .set_HEADER_B2(l_pdi_keyword_data[2])
                .set_HEADER_B3(l_pdi_keyword_data[3])
                .set_HEADER_B4(l_pdi_keyword_data[4])
                .set_HEADER_B5(l_pdi_keyword_data[5]),
                "Invalid CRP0 PDI header pattern (%s)",
                l_targetStr);

    // fill bad lane vector attribute from MVPD for each IOHS
    for (auto& l_iohs_target : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
    {
        fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_Type l_bad_lane_vec_valid = fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_TRUE;
        fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_Type l_bad_lane_vec = 0;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos = 0;
        uint8_t l_chiplet_id = 0;
        uint8_t l_pdi_byte_start_idx = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_unit_pos));

        l_pdi_byte_start_idx = 6 + (3 * l_unit_pos);
        l_bad_lane_vec = (l_pdi_keyword_data[l_pdi_byte_start_idx] << 24) |
                         (l_pdi_keyword_data[l_pdi_byte_start_idx + 1] << 16) |
                         ((l_pdi_keyword_data[l_pdi_byte_start_idx + 2] & 0xC0) << 8);
        l_chiplet_id = (l_pdi_keyword_data[l_pdi_byte_start_idx + 2] & 0x3F);

        FAPI_ASSERT(l_chiplet_id == (0x18 + l_unit_pos),
                    fapi2::P10_ATTR_UPDATE_PDI_KEYWORD_CHIPLET_ID_ERR()
                    .set_TARGET(i_target)
                    .set_ENTRY_OFFSET(l_pdi_byte_start_idx)
                    .set_ENTRY_B0(l_pdi_keyword_data[l_pdi_byte_start_idx])
                    .set_ENTRY_B1(l_pdi_keyword_data[l_pdi_byte_start_idx + 1])
                    .set_ENTRY_B2(l_pdi_keyword_data[l_pdi_byte_start_idx + 2])
                    .set_CHIPLET_ID(l_chiplet_id)
                    .set_UNIT_POS(l_unit_pos),
                    "Invalid CRP0 PDI entry (%s)",
                    l_targetStr);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID, l_iohs_target, l_bad_lane_vec_valid));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC, l_iohs_target, l_bad_lane_vec));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


fapi2::ReturnCode
p10_attr_update(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    FAPI_TRY(p10_attr_update_mer0_pdI_mvpd(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
