/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/check.C $   */
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
/// @file check.C
/// @brief Subroutines for checking MSS FIR
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <generic/memory/lib/utils/scom.H>
#include <lib/fir/fir.H>
#include <lib/fir/check.H>
#include <lib/utils/assert_noexit.H>
#include <generic/memory/lib/utils/find.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

namespace mss
{

namespace check
{

///
/// @brief A small, local, class to hold some of the FFDC information we need from the ports
///
struct fir_ffdc
{
    ///
    /// @brief fir_ffdc ctor
    /// @param[in] the MCA target the FFDC was collected from
    /// @param[in] the cal FIR information
    /// @param[in] the phy FIR information
    ///
    fir_ffdc( const fapi2::Target<TARGET_TYPE_MCA>& i_target, const uint64_t i_calfir, const uint64_t i_phyfir ):
        iv_target(i_target),
        iv_calfir(i_calfir),
        iv_phyfir(i_phyfir)
    {}

    ~fir_ffdc() = default;
    fir_ffdc() = delete;

    fapi2::Target<TARGET_TYPE_MCA> iv_target;
    uint64_t iv_calfir;
    uint64_t iv_phyfir;
};

///
/// @brief Check FIR bits during PHY reset
/// @note For DDRPHYFIR and some MBACALFIR errors, up to and including phy reset, need to
/// handle within the phy reset procedure, since we may get errors from a 'non-functional'
/// magic port, which PRD can't analyze.
/// @param[in] i_target the fapi2::Target MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode during_phy_reset( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    // Save off the current current_err
    fapi2::ReturnCode l_current_err(fapi2::current_err);

    // Error path: if we hit error before FIR check (we can see that in current_err), and FIR check also
    // finds something, commit first error and exit phy reset with new error from FIR check
    // If bit on, call out MCA with deconfig and gard, including DDRPHYFIR and MBACALFIR in FFDC
    // Do FIR check on all ports, so we can log errors from multiple ports that happen to have FIR bits on

    // Create a mask from the bits Marc wants us to check
    fapi2::buffer<uint64_t> l_calfir_mask;
    l_calfir_mask.setBit<MCA_MBACALFIRQ_MBA_RECOVERABLE_ERROR>()
    .setBit<MCA_MBACALFIRQ_MBA_NONRECOVERABLE_ERROR>()
    .setBit<MCA_MBACALFIRQ_SM_1HOT_ERR>();

    fapi2::buffer<uint64_t> l_phyfir_mask;
    l_phyfir_mask.setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_0>()
    .setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_1>()
    .setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_3>()
    .setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_4>()
    .setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_5>()
    .setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_6>()
    .setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_7>();


    // Go grab the MCA_MBACALFIRQ for each port. We only save off some of the FFDC information for the ports which
    // have FIR set. This allows us to 1) see if we have any thing to do (empty vector means we don't) and 2) gives us
    // all the information we need to log all the proper errors.
    std::vector< fir_ffdc> l_fir_ffdc;

    for (const auto& p : mss::find_targets_with_magic<TARGET_TYPE_MCA>(i_target))
    {
        fapi2::buffer<uint64_t> l_calfir_data;
        fapi2::buffer<uint64_t> l_phyfir_data;
        fapi2::buffer<uint64_t> l_calfir_masked;
        fapi2::buffer<uint64_t> l_phyfir_masked;

        FAPI_TRY( mss::getScom(p, MCA_MBACALFIRQ, l_calfir_data) );
        FAPI_TRY( mss::getScom(p, MCA_IOM_PHY0_DDRPHY_FIR_REG, l_phyfir_data) );

        l_calfir_masked = l_calfir_data & l_calfir_mask;
        l_phyfir_masked = l_phyfir_data & l_phyfir_mask;

        // If either has set bits we make a little record in the vector
        if ((l_calfir_masked != 0) || (l_phyfir_masked != 0))
        {
            l_fir_ffdc.push_back( fir_ffdc(p, l_calfir_data, l_phyfir_data) );
        }

        // Clear the FIR
        FAPI_TRY( mss::putScom(p, MCA_MBACALFIRQ_AND, l_calfir_masked.invert()) );
        FAPI_TRY( mss::putScom(p, MCA_IOM_PHY0_DDRPHY_FIR_REG_AND, l_phyfir_masked.invert()) );
    }

    FAPI_INF("seeing FIRs set on %d ports", l_fir_ffdc.size());

    // Ok, we know if l_fir_ffdc is empty that we had no FIR bits set. In this case we just return fapi2::current_err
    // as it represents the error state of our caller. If there were no errors seen by the caller, this will be
    // SUCCESS, and our caller will return SUCCESS. If there was an error, we don't disturb it, we just return
    // is so the caller can pass it back to it's caller (if there are FIR we'll disrupt current_err ...)
    if (l_fir_ffdc.size() == 0)
    {
        return l_current_err;
    }

    // Ok so if we're here we have FIR bits set. Not sure it matters what they are, we're returning them in the FFDC
    // and calling out/deconfig the port. First thing we do is commit whatever was in fapi2::current_err, if it's not
    // success.
    if (l_current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        fapi2::logError(l_current_err);
    }

    // Now log all the errors which represent all the errors found from the ports.
    for (const fir_ffdc& f : l_fir_ffdc)
    {
        MSS_ASSERT_NOEXIT(false,
                          fapi2::MSS_DDR_PHY_RESET_PORT_FIR()
                          .set_CAL_FIR(f.iv_calfir)
                          .set_PHY_FIR(f.iv_phyfir)
                          .set_MCA_TARGET(f.iv_target),
                          "Reporting FIR bits set for %s (cal: 0x%016lx phy: 0x%016lx",
                          mss::c_str(f.iv_target), f.iv_calfir, f.iv_phyfir);
    }

    // The last thing we want to do is to create a new error code noting there were FIR set for any of the ports
    // during PHY reset and pass that back so it goes upstream. This will jump right to the label ...
    FAPI_ASSERT(false, fapi2::MSS_DDR_PHY_RESET_PORT_FIRS_REPORTED().set_MCBIST_TARGET(i_target));

fapi_try_exit:
    return fapi2::current_err;
}


}
}
