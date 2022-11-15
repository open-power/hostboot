/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_common_utils_ddr5.C $ */
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
/// @file pmic_common_utils.C
/// @brief Utility functions common for several PMIC DDR5 procedures
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <i2c_pmic.H>
#include <pmic_consts.H>
#include <pmic_common_utils.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/c_str.H>
#include <mss_pmic_attribute_accessors_manual.H>

namespace mss
{
namespace pmic
{
namespace ddr5
{

///
/// @brief Helper function to get the minimum vin bulk threshold
///
/// @param[in] i_vin_bulk_min_threshold
/// @return VIN bulk minimum value
///
uint16_t get_minimum_vin_bulk_threshold_helper(
    const uint8_t i_vin_bulk_min_threshold)
{
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    uint16_t l_mapped_vin_bulk = 0;

    switch (i_vin_bulk_min_threshold & FIELDS::R1A_VIN_BULK_POWER_GOOD_THRESHOLD_VOLTAGE_MASK)
    {
        case CONSTS::VIN_BULK_9_5V:
            l_mapped_vin_bulk = 9500;

        case CONSTS::VIN_BULK_8_5V:
            l_mapped_vin_bulk = 8500;

        case CONSTS::VIN_BULK_7_5V:
            l_mapped_vin_bulk = 7500;

        case CONSTS::VIN_BULK_6_5V:
            l_mapped_vin_bulk = 6500;

        case CONSTS::VIN_BULK_5_5V:
            l_mapped_vin_bulk = 5500;

        case CONSTS::VIN_BULK_4_25V:
            l_mapped_vin_bulk = 4250;
    }

    return l_mapped_vin_bulk;
}

///
/// @brief Get the minimum vin bulk threshold
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_vin_bulk_min VIN bulk minimum value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_minimum_vin_bulk_threshold(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    uint16_t& o_vin_bulk_min)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::buffer<uint8_t> l_vin_bulk_min_threshold;

    // Use R1A value
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R1A, l_vin_bulk_min_threshold));

    o_vin_bulk_min = mss::pmic::ddr5::get_minimum_vin_bulk_threshold_helper(
                         l_vin_bulk_min_threshold);

fapi_try_exit:
    return fapi2::current_err;
}

} // ddr5
} // pmic
} // mss
