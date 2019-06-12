/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_common_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file pmic_common_utils.H
/// @brief Utility functions common for several PMIC procedures
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_COMMON_UTILS_H__
#define __PMIC_COMMON_UTILS_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/utils/pmic_consts.H>
#include <mss_pmic_attribute_getters.H>

namespace mss
{
namespace pmic
{

// Attribute getter pointer for manufacturer/vendor ID
typedef fapi2::ReturnCode (*mfg_id_attr_ptr)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint16_t& o_value);

// Manufacturer / Vendor ID
static constexpr mfg_id_attr_ptr get_mfg_id[] =
{
    mss::attr::get_pmic0_mfg_id,
    mss::attr::get_pmic1_mfg_id
};

using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;;

// Arrays to easily index common parameters by rail
static constexpr uint8_t const VOLT_SETTING_ACTIVE_REGS[] =
{
    REGS::R21_SWA_VOLTAGE_SETTING,
    REGS::R23_SWB_VOLTAGE_SETTING,
    REGS::R25_SWC_VOLTAGE_SETTING,
    REGS::R27_SWD_VOLTAGE_SETTING
};

static constexpr uint8_t const VOLT_SETTING_REGS[] =
{
    REGS::R21_SWA_VOLTAGE_SETTING,
    REGS::R23_SWB_VOLTAGE_SETTING,
    REGS::R25_SWC_VOLTAGE_SETTING,
    REGS::R27_SWD_VOLTAGE_SETTING
};

static constexpr uint8_t const VOLT_RANGE_FLDS[] =
{
    FIELDS::SWA_VOLTAGE_RANGE,
    FIELDS::SWB_VOLTAGE_RANGE,
    FIELDS::SWC_VOLTAGE_RANGE,
    FIELDS::SWD_VOLTAGE_RANGE
};

static constexpr uint32_t const VOLT_RANGE_MINS[][CONSTS::NUM_RANGES] =
{
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN},
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN},
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN},
    {CONSTS::SWD_VOLT_RANGE0_MIN,   CONSTS::SWD_VOLT_RANGE1_MIN}
};

static constexpr uint32_t const VOLT_RANGE_MAXES[][CONSTS::NUM_RANGES] =
{
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX},
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX},
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX},
    {CONSTS::SWD_VOLT_RANGE0_MAX,   CONSTS::SWD_VOLT_RANGE1_MAX}
};

///
/// @brief polls PMIC for PBULK PWR_GOOD status
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode success if good, error if polling fail or power not good
///
fapi2::ReturnCode poll_for_pbulk_good(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Unlocks PMIC vendor region
///
/// @param[in] i_pmic_target JEDEC-COMPLIANT PMIC to unlock
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode unlock_vendor_region(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Locks PMIC vendor region
///
/// @param[in] i_pmic_target - JEDEC-COMPLIANT PMIC to lock
/// @param[in] i_rc - return code from the end of the caller function (if applicable)
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff i_rc == SUCCESS && no errors in unlocking, else return current_err
///
fapi2::ReturnCode lock_vendor_region(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
                                     const fapi2::ReturnCode i_rc = fapi2::FAPI2_RC_SUCCESS);

} // pmic
} // mss

#endif
