/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/mss_pmic_attribute_accessors_manual.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file mss_pmic_attribute_accessors_manual.H
/// @brief Manual PMIC attribute accessors
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_PMIC_ATTR_ACCESSORS_MANUAL_H_
#define _MSS_PMIC_ATTR_ACCESSORS_MANUAL_H_

#include <fapi2.H>
#include <mss_pmic_attribute_getters.H>
#include <mss_pmic_attribute_setters.H>
#include <lib/utils/pmic_consts.H>

namespace mss
{
namespace attr
{

//--------------------
// Attribute Getters
//--------------------

// Attribute getter pointer for manufacturer/vendor ID
typedef fapi2::ReturnCode (*mfg_id_attr_ptr)(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint16_t& o_value);

// Manufacturer / Vendor ID
static constexpr mfg_id_attr_ptr get_mfg_id[] =
{
    mss::attr::get_pmic0_mfg_id,
    mss::attr::get_pmic1_mfg_id,
};

/// @brief pointer to PMIC attribute getters for OCMB parent target of pmic
typedef fapi2::ReturnCode (*pmic_attr_ptr)(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint8_t& o_value);
typedef fapi2::ReturnCode (*pmic_attr_ptr_signed)(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        int8_t& o_value);

// Pointers below allow for run-time attribute getter selection by PMIC ID (0,1)

// PMIC0/1 Revision
static constexpr pmic_attr_ptr get_revision[] =
{
    mss::attr::get_pmic0_revision,
    mss::attr::get_pmic1_revision
};

// Voltage Setting
static constexpr pmic_attr_ptr get_swa_voltage_setting[] =
{
    mss::attr::get_pmic0_swa_voltage_setting,
    mss::attr::get_pmic1_swa_voltage_setting
};
static constexpr pmic_attr_ptr get_swb_voltage_setting[] =
{
    mss::attr::get_pmic0_swb_voltage_setting,
    mss::attr::get_pmic1_swb_voltage_setting
};
static constexpr pmic_attr_ptr get_swc_voltage_setting[] =
{
    mss::attr::get_pmic0_swc_voltage_setting,
    mss::attr::get_pmic1_swc_voltage_setting
};
static constexpr pmic_attr_ptr get_swd_voltage_setting[] =
{
    mss::attr::get_pmic0_swd_voltage_setting,
    mss::attr::get_pmic1_swd_voltage_setting
};

// Voltage Range Select
static constexpr pmic_attr_ptr get_swa_voltage_range_select[] =
{
    mss::attr::get_pmic0_swa_voltage_range_select,
    mss::attr::get_pmic1_swa_voltage_range_select
};
static constexpr pmic_attr_ptr get_swb_voltage_range_select[] =
{
    mss::attr::get_pmic0_swb_voltage_range_select,
    mss::attr::get_pmic1_swb_voltage_range_select
};
static constexpr pmic_attr_ptr get_swc_voltage_range_select[] =
{
    mss::attr::get_pmic0_swc_voltage_range_select,
    mss::attr::get_pmic1_swc_voltage_range_select
};
static constexpr pmic_attr_ptr get_swd_voltage_range_select[] =
{
    mss::attr::get_pmic0_swd_voltage_range_select,
    mss::attr::get_pmic1_swd_voltage_range_select
};

// Voltage Offset
static constexpr pmic_attr_ptr_signed get_swa_voltage_offset[] =
{
    mss::attr::get_pmic0_swa_voltage_offset,
    mss::attr::get_pmic1_swa_voltage_offset
};
static constexpr pmic_attr_ptr_signed get_swb_voltage_offset[] =
{
    mss::attr::get_pmic0_swb_voltage_offset,
    mss::attr::get_pmic1_swb_voltage_offset
};
static constexpr pmic_attr_ptr_signed get_swc_voltage_offset[] =
{
    mss::attr::get_pmic0_swc_voltage_offset,
    mss::attr::get_pmic1_swc_voltage_offset
};
static constexpr pmic_attr_ptr_signed get_swd_voltage_offset[] =
{
    mss::attr::get_pmic0_swd_voltage_offset,
    mss::attr::get_pmic1_swd_voltage_offset
};

// EFD Fields

// Offset
static constexpr pmic_attr_ptr_signed get_efd_swa_voltage_offset[] =
{
    mss::attr::get_efd_pmic0_swa_voltage_offset,
    mss::attr::get_efd_pmic1_swa_voltage_offset
};

static constexpr pmic_attr_ptr_signed get_efd_swb_voltage_offset[] =
{
    mss::attr::get_efd_pmic0_swb_voltage_offset,
    mss::attr::get_efd_pmic1_swb_voltage_offset
};

static constexpr pmic_attr_ptr_signed get_efd_swc_voltage_offset[] =
{
    mss::attr::get_efd_pmic0_swc_voltage_offset,
    mss::attr::get_efd_pmic1_swc_voltage_offset
};

static constexpr pmic_attr_ptr_signed get_efd_swd_voltage_offset[] =
{
    mss::attr::get_efd_pmic0_swd_voltage_offset,
    mss::attr::get_efd_pmic1_swd_voltage_offset
};

// Current limiter warnings (EFD)
static constexpr pmic_attr_ptr get_swa_current_warning[] =
{
    mss::attr::get_pmic0_swa_current_warning,
    mss::attr::get_pmic1_swa_current_warning
};

static constexpr pmic_attr_ptr get_swb_current_warning[] =
{
    mss::attr::get_pmic0_swb_current_warning,
    mss::attr::get_pmic1_swb_current_warning
};

static constexpr pmic_attr_ptr get_swc_current_warning[] =
{
    mss::attr::get_pmic0_swc_current_warning,
    mss::attr::get_pmic1_swc_current_warning
};

static constexpr pmic_attr_ptr get_swd_current_warning[] =
{
    mss::attr::get_pmic0_swd_current_warning,
    mss::attr::get_pmic1_swd_current_warning
};

// These arrays allow us to dynamically choose the right attribute getter at runtime based on the rail and mss::pmic::id
static constexpr const pmic_attr_ptr* get_volt_setting[] =
{
    get_swa_voltage_setting,
    get_swb_voltage_setting,
    get_swc_voltage_setting,
    get_swd_voltage_setting
};

static constexpr const pmic_attr_ptr* get_volt_range_select[] =
{
    get_swa_voltage_range_select,
    get_swb_voltage_range_select,
    get_swc_voltage_range_select,
    get_swd_voltage_range_select
};

static constexpr const pmic_attr_ptr_signed* get_volt_offset[] =
{
    get_swa_voltage_offset,
    get_swb_voltage_offset,
    get_swc_voltage_offset,
    get_swd_voltage_offset
};

// EFD Offset + Direction functions
static constexpr const pmic_attr_ptr_signed* get_efd_volt_offset[] =
{
    get_efd_swa_voltage_offset,
    get_efd_swb_voltage_offset,
    get_efd_swc_voltage_offset,
    get_efd_swd_voltage_offset
};

// Current limiter warning threshold
static constexpr const pmic_attr_ptr* get_current_warning[] =
{
    get_swa_current_warning,
    get_swb_current_warning,
    get_swc_current_warning,
    get_swd_current_warning
};

// PMIC0/1 sequence order
static constexpr pmic_attr_ptr get_sequence[] =
{
    mss::attr::get_pmic0_sequence,
    mss::attr::get_pmic1_sequence
};

// Sequence Delay
static constexpr pmic_attr_ptr get_swa_sequence_delay[] =
{
    mss::attr::get_pmic0_swa_sequence_delay,
    mss::attr::get_pmic1_swa_sequence_delay
};
static constexpr pmic_attr_ptr get_swb_sequence_delay[] =
{
    mss::attr::get_pmic0_swb_sequence_delay,
    mss::attr::get_pmic1_swb_sequence_delay
};
static constexpr pmic_attr_ptr get_swc_sequence_delay[] =
{
    mss::attr::get_pmic0_swc_sequence_delay,
    mss::attr::get_pmic1_swc_sequence_delay
};
static constexpr pmic_attr_ptr get_swd_sequence_delay[] =
{
    mss::attr::get_pmic0_swd_sequence_delay,
    mss::attr::get_pmic1_swd_sequence_delay
};

// Sequence Order
static constexpr pmic_attr_ptr get_swa_sequence_order[] =
{
    mss::attr::get_pmic0_swa_sequence_order,
    mss::attr::get_pmic1_swa_sequence_order
};
static constexpr pmic_attr_ptr get_swb_sequence_order[] =
{
    mss::attr::get_pmic0_swb_sequence_order,
    mss::attr::get_pmic1_swb_sequence_order
};
static constexpr pmic_attr_ptr get_swc_sequence_order[] =
{
    mss::attr::get_pmic0_swc_sequence_order,
    mss::attr::get_pmic1_swc_sequence_order
};
static constexpr pmic_attr_ptr get_swd_sequence_order[] =
{
    mss::attr::get_pmic0_swd_sequence_order,
    mss::attr::get_pmic1_swd_sequence_order
};

static constexpr const pmic_attr_ptr* get_sequence_order[] =
{
    get_swa_sequence_order,
    get_swb_sequence_order,
    get_swc_sequence_order,
    get_swd_sequence_order
};

static constexpr const pmic_attr_ptr* get_sequence_delay[] =
{
    get_swa_sequence_delay,
    get_swb_sequence_delay,
    get_swc_sequence_delay,
    get_swd_sequence_delay
};

// Phase Combination
static constexpr pmic_attr_ptr get_phase_comb[] =
{
    mss::attr::get_pmic0_phase_comb,
    mss::attr::get_pmic1_phase_comb
};

///
/// @brief Get pmic n mode state for the given PMIC ID
///
/// @param[in] i_ocmb OCMB target
/// @param[in] i_pmic_id PMIC ID [0-3]
/// @param[out] o_n_mode N-Mode state
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode get_n_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
    const uint8_t i_pmic_id,
    mss::pmic::n_mode& o_n_mode);

///
/// @brief Set pmic n mode state for the given PMIC ID
///
/// @param[in] i_ocmb OCMB target
/// @param[in] i_pmic_id PMIC ID [0-3]
/// @param[in] i_n_mode N-Mode state
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode set_n_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
    const uint8_t i_pmic_id,
    const mss::pmic::n_mode i_n_mode);

} // ns attr
} // ns mss

#endif
