/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/memdiags_fir.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file memdiags_fir.C
/// @brief Subroutines for memdiags/prd FIR
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/fir/fir.H>
#include <lib/fir/memdiags_fir.H>
#include <lib/mc/port.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

namespace mss
{

namespace unmask
{

///
/// @brief Unmask and setup actions for memdiags related FIR
/// @param[in] i_target the fapi2::Target MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_memdiags( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> dsm0_buffer;
    uint64_t rd_tag_delay = 0;
    uint64_t wr_done_delay = 0;
    uint64_t mnfg_flag = 0;
    fapi2::buffer<uint64_t> l_aue_buffer;
    fapi2::ATTR_CHIP_EC_FEATURE_HW414700_Type l_checkstop_flag;

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_FIR> l_ecc64_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_FIR);

        fir::reg<MCA_MBACALFIRQ> l_cal_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_MBACALFIRQ);

        // Read out the wr_done and rd_tag delays and find min
        // and set the RCD Protect Time to this value
        FAPI_TRY (mss::read_dsm0q_register(p, dsm0_buffer) );
        mss::get_wrdone_delay(dsm0_buffer, wr_done_delay);
        mss::get_rdtag_delay(dsm0_buffer, rd_tag_delay);
        const auto rcd_protect_time = std::min(wr_done_delay, rd_tag_delay);
        FAPI_TRY (mss::change_rcd_protect_time(p, rcd_protect_time) );

        l_ecc64_fir_reg.checkstop<MCA_FIR_MAINLINE_AUE>()
        .recoverable_error<MCA_FIR_MAINLINE_UE>()
        .checkstop<MCA_FIR_MAINLINE_IAUE>()
        .recoverable_error<MCA_FIR_MAINLINE_IUE>();

        // If ATTR_CHIP_EC_FEATURE_HW414700 is enabled set checkstops
        auto l_chip_target = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, l_chip_target, l_checkstop_flag) );

        if (l_checkstop_flag)
        {
            l_ecc64_fir_reg.checkstop<MCA_FIR_MAINLINE_UE>()
            .checkstop<MCA_FIR_MAINLINE_RCD>();
        }

        // If MNFG FLAG Threshhold is enabled skip IUE unflagging
        FAPI_TRY (mss::mnfg_flags(mnfg_flag) );

        if (mnfg_flag != fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_THRESHOLDS)
        {
            l_ecc64_fir_reg.recoverable_error<MCA_FIR_MAINTENANCE_IUE>();
        }

        l_cal_fir_reg.recoverable_error<MCA_MBACALFIRQ_PORT_FAIL>();

        FAPI_TRY(l_ecc64_fir_reg.write(), "unable to write fir::reg %d", MCA_FIR);
        FAPI_TRY(l_cal_fir_reg.write(), "unable to write fir::reg %d", MCA_MBACALFIRQ);

        // Change Maint AUE and IAUE to checkstop without unmasking
        // Normal setup modifies masked bits in addition to setting checkstop
        // This causes issues if error has occured, manually scoming to avoid this
        FAPI_TRY( mss::getScom(p, MCA_ACTION1, l_aue_buffer) );
        l_aue_buffer.clearBit<MCA_FIR_MAINTENANCE_AUE>();
        l_aue_buffer.clearBit<MCA_FIR_MAINTENANCE_IAUE>();
        FAPI_TRY( mss::putScom(p, MCA_ACTION1, l_aue_buffer) );

        // Note: We also want to include the following setup RCD recovery and port fail
        FAPI_TRY( mss::change_port_fail_disable(p, mss::LOW) );
        FAPI_TRY( mss::change_rcd_recovery_disable(p, mss::LOW) );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions for scrub related FIR
/// @param[in] i_target the fapi2::Target MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_background_scrub( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fapi2::ReturnCode l_rc;
        fir::reg<MCA_FIR> l_ecc64_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_FIR);

        l_ecc64_fir_reg.recoverable_error<MCA_FIR_MAINLINE_MPE_RANK_0_TO_7,
                                          MCA_FIR_MAINLINE_MPE_RANK_0_TO_7_LEN>()
                                          .recoverable_error<MCA_FIR_MAINLINE_NCE>()
                                          .recoverable_error<MCA_FIR_MAINLINE_TCE>()
                                          .recoverable_error<MCA_FIR_MAINLINE_IMPE>()
                                          .recoverable_error<MCA_FIR_MAINTENANCE_IMPE>();

        FAPI_TRY(l_ecc64_fir_reg.write(), "unable to write fir::reg %d", MCA_FIR);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}
}
