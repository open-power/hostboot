/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/power_thermal/p10_throttle_sync_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
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

namespace mss
{

///
/// @brief Enable sync operations
/// @param[in] i_target the target to be programmed
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode enable_sync_operations(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target)
{
    using namespace scomt::mc;
    FAPI_DBG("Entering enable_sync_operations on target %s", mss::c_str(i_target));

    fapi2::buffer<uint64_t> l_scomData(0);
    FAPI_TRY(PREP_SCOMFIR_MCMODE0(i_target));
    SET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(l_scomData);

    FAPI_DBG("Writing SCOMFIR_MCSYNC 0x%016llX: Data 0x%016llX for %s",
             SCOMFIR_MCSYNC, l_scomData, mss::c_str(i_target));

    FAPI_TRY(PUT_SCOMFIR_MCMODE0(i_target, l_scomData),
             "Failed PUT_SCOMFIR_MCMODE0() on %s", mss::c_str(i_target));

fapi_try_exit:
    FAPI_DBG("Exiting enable_sync_operations on target %s", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief Programming master MI
/// @param[in] i_target the target to be programmed as master.
/// @return FAPI2_RC_SUCCESS iff okay
/// @note Writes SCOMFIR_MCSYNC reg to set the input MI as the master.
///
fapi2::ReturnCode setup_master(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target)
{
    using namespace scomt::mc;
    FAPI_DBG("Entering setup_master with target %s", mss::c_str(i_target));
    fapi2::buffer<uint64_t> l_scomData(0);
    fapi2::buffer<uint64_t> l_scomMask(0);

    // -------------------------------------------------------------------
    // 1. Reset sync command
    // -------------------------------------------------------------------

    // Set GO bit
    FAPI_TRY(PREP_SCOMFIR_MCSYNC(i_target));
    SET_SCOMFIR_MCSYNC_SYNC_GO(l_scomData);
    FAPI_TRY(PUT_SCOMFIR_MCSYNC(i_target, l_scomData),
             "Failed PUT_SCOMFIR_MCSYNC() on %s", mss::c_str(i_target));

    // --------------------------------------------------------------
    // 2. Setup MC Sync Command Register data for master or MI
    // --------------------------------------------------------------

    // Clear buffers
    l_scomData.flush<0>();
    l_scomMask.flush<0>();

    // Force bit set in case cleared from last procedure run
    l_scomData.setBit<EXPLR_SRQ_MBA_SYNCCNTLQ_SYNC_REF_EN>();
    l_scomMask.setBit<EXPLR_SRQ_MBA_SYNCCNTLQ_SYNC_REF_EN>();

    // Iterate through OCMBs to make sure refresh SYNC bit is set
    for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target))
    {
        FAPI_DBG("Writing EXPLR_SRQ_MBA_SYNCCNTLQ 0x%016llX: Data 0x%016llX Mask 0x%016llX on %s",
                 EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomData, l_scomMask, mss::c_str(l_ocmb));

        FAPI_TRY(fapi2::putScomUnderMask(l_ocmb, EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomData, l_scomMask),
                 "putScomUnderMask() failed on EXPLR_SRQ_MBA_SYNCCNTLQ 0x%016llX for %s",
                 EXPLR_SRQ_MBA_SYNCCNTLQ, mss::c_str(l_ocmb));
    }

    // Clear buffers
    l_scomData.flush<0>();
    l_scomMask.flush<0>();

    // --------------------------------------------------------------
    // 3. Write to MC Sync Command Register of master MI
    // --------------------------------------------------------------

    // Setup SYNC_GO
    FAPI_TRY(PREP_SCOMFIR_MCSYNC(i_target));
    SET_SCOMFIR_MCSYNC_SYNC_GO(l_scomData);

    // Write to MCSYNC reg
    FAPI_DBG("Writing SCOMFIR_MCSYNC 0x%016llX: Data 0x%016llX for %s",
             SCOMFIR_MCSYNC, l_scomData, mss::c_str(i_target));

    FAPI_TRY(PUT_SCOMFIR_MCSYNC(i_target, l_scomData),
             "Failed PUT_SCOMFIR_MCSYNC() on %s", mss::c_str(i_target));

    // --------------------------------------------------------------
    // 4. Clear refresh sync bit
    // --------------------------------------------------------------
    l_scomData.flush<0>();
    l_scomMask.flush<0>().setBit<EXPLR_SRQ_MBA_SYNCCNTLQ_SYNC_REF_EN>();

    // Iterate through OCMBs to clear refresh sync bit
    for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target))
    {
        FAPI_DBG("Writing EXPLR_SRQ_MBA_SYNCCNTLQ 0x%016llX: Mask 0x%016llX , Data 0x%016llX on %s",
                 EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomMask, l_scomData, mss::c_str(l_ocmb));

        FAPI_TRY(fapi2::putScomUnderMask(l_ocmb, EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomData, l_scomMask),
                 "putScomUnderMask() failed on EXPLR_SRQ_MBA_SYNCCNTLQ 0x%016llX for %s",
                 EXPLR_SRQ_MBA_SYNCCNTLQ, mss::c_str(l_ocmb));
    }

fapi_try_exit:
    FAPI_DBG("Exiting setup_master with target %s", mss::c_str(i_target));
    return fapi2::current_err;
}

}//mss
