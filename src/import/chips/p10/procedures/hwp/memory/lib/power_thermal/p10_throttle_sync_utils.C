/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/power_thermal/p10_throttle_sync_utils.C $ */
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
/// @file p10_throttle_sync_utils.C
/// @brief throttle_sync function implementations for P10
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB

#include <lib/power_thermal/p10_throttle_sync_utils.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <p10_scom_mc_c.H>
#include <p10_scom_mc_5.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/workarounds/p10_mc_workarounds.H>

namespace mss
{

///
/// @brief Configure sync operations on the ocmb's for a given MI
/// @param[in] i_target the target to be programmed
/// @param[in] i_enable ON if enabled, OFF to disable
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode configure_ocmb_sync_operations(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
        const mss::states i_enable)
{
    fapi2::buffer<uint64_t> l_scomData;
    fapi2::buffer<uint64_t> l_scomMask;

    // Force bit to the proper state
    l_scomData.writeBit<EXPLR_SRQ_MBA_SYNCCNTLQ_SYNC_REF_EN>(i_enable);
    l_scomMask.setBit<EXPLR_SRQ_MBA_SYNCCNTLQ_SYNC_REF_EN>();

    // Iterate through OCMBs to make sure refresh SYNC bit is set
    for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target))
    {
        if(mss::count_dimm(l_ocmb) == 0)
        {
            FAPI_INF("No DIMMs on %s -- skipping", mss::c_str(l_ocmb));
            continue;
        }

        FAPI_DBG("Writing EXPLR_SRQ_MBA_SYNCCNTLQ 0x%016llX: Data 0x%016llX Mask 0x%016llX on %s",
                 EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomData, l_scomMask, mss::c_str(l_ocmb));

        FAPI_TRY(fapi2::putScomUnderMask(l_ocmb, EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomData, l_scomMask),
                 "putScomUnderMask() failed on EXPLR_SRQ_MBA_SYNCCNTLQ 0x%016llX for %s",
                 EXPLR_SRQ_MBA_SYNCCNTLQ, mss::c_str(l_ocmb));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure sync operations on the MI
/// @param[in] i_target the target to be programmed
/// @param[in] i_enable ON if enabled, OFF to disable
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode configure_sync_operations(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
        const mss::states i_enable)
{
    using namespace scomt::mc;

    fapi2::buffer<uint64_t> l_scomData;
    FAPI_TRY(PREP_SCOMFIR_MCMODE0(i_target));
    FAPI_TRY(GET_SCOMFIR_MCMODE0(i_target, l_scomData));
    SET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(i_enable, l_scomData);

    FAPI_TRY(PUT_SCOMFIR_MCMODE0(i_target, l_scomData),
             "Failed PUT_SCOMFIR_MCMODE0() on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setting up sync mode in the MI
/// @param[in] i_target the target to be programmed
/// @param[in] i_primary true if this is the primary MI to program, otherwise false
/// @return FAPI2_RC_SUCCESS iff okay
/// @note Writes SCOMFIR_MCSYNC reg to set the input MI with configuration for primary vs secondary MI
///
fapi2::ReturnCode setup_sync(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target, const bool i_primary)
{
    using namespace scomt::mc;

    fapi2::ATTR_CHIP_EC_FEATURE_THROTTLE_SYNC_HW550549_Type l_ec_workaround = 0;
    mss::states l_sync_val = mss::states::OFF;
    fapi2::buffer<uint64_t> l_scomData;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_THROTTLE_SYNC_HW550549,
                           mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target),
                           l_ec_workaround),
             "%s Failed to read ATTR_CHIP_EC_FEATURE_THROTTLE_SYNC_HW550549",
             mss::c_str(i_target));

    // -------------------------------------------------------------------
    // 1. Setup MCMODE0 register
    // -------------------------------------------------------------------
    l_sync_val = mss::workarounds::mc::get_mc_sync_value(i_primary, l_ec_workaround);
    FAPI_TRY(configure_sync_operations(i_target, l_sync_val));

    // -------------------------------------------------------------------
    // 2. Setup MCSYNC register. Do not initiate a sync yet!
    // -------------------------------------------------------------------
    // Set GO bit
    FAPI_TRY(PREP_SCOMFIR_MCSYNC(i_target));
    FAPI_TRY(GET_SCOMFIR_MCSYNC(i_target, l_scomData),
             "Failed GET_SCOMFIR_MCSYNC() on %s", mss::c_str(i_target));
    CLEAR_SCOMFIR_MCSYNC_SYNC_GO(l_scomData);
    SET_SCOMFIR_MCSYNC_EN_SYNC_IN(l_sync_val, l_scomData);
    FAPI_TRY(PUT_SCOMFIR_MCSYNC(i_target, l_scomData),
             "Failed PUT_SCOMFIR_MCSYNC() on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Programming the MI
/// @param[in] i_target the target to be programmed - the primary MI
/// @return FAPI2_RC_SUCCESS iff okay
/// @note Writes SCOMFIR_MCSYNC reg to issue the sync commands
///
fapi2::ReturnCode issue_sync(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target)
{
    using namespace scomt::mc;
    fapi2::buffer<uint64_t> l_scomData;

    // -------------------------------------------------------------------
    // Issue sync command - set to a 1
    // -------------------------------------------------------------------
    // Set GO bit
    FAPI_TRY(PREP_SCOMFIR_MCSYNC(i_target));
    FAPI_TRY(GET_SCOMFIR_MCSYNC(i_target, l_scomData),
             "Failed GET_SCOMFIR_MCSYNC() on %s", mss::c_str(i_target));
    SET_SCOMFIR_MCSYNC_SYNC_GO(l_scomData);
    FAPI_TRY(PUT_SCOMFIR_MCSYNC(i_target, l_scomData),
             "Failed PUT_SCOMFIR_MCSYNC() on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

}//mss
