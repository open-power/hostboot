/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/memdiags_fir.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/scom.H>
#include <lib/utils/find.H>
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

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_FIR> l_ecc64_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_FIR);

        fir::reg<MCA_MBACALFIRQ> l_cal_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_MBACALFIRQ);

        l_ecc64_fir_reg.checkstop<MCA_FIR_MAINLINE_AUE>()
        .recoverable_error<MCA_FIR_MAINLINE_UE>()
        .checkstop<MCA_FIR_MAINLINE_IAUE>()
        .recoverable_error<MCA_FIR_MAINLINE_IUE>();

        // TODO RTC:165157 check for manufacturing flags and don't unmask this if
        // thresholds policy is enabled.
        l_ecc64_fir_reg.recoverable_error<MCA_FIR_MAINTENANCE_IUE>();

        l_cal_fir_reg.recoverable_error<MCA_MBACALFIRQ_PORT_FAIL>();

        FAPI_TRY(l_ecc64_fir_reg.write(), "unable to write fir::reg %d", MCA_FIR);
        FAPI_TRY(l_cal_fir_reg.write(), "unable to write fir::reg %d", MCA_MBACALFIRQ);

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
