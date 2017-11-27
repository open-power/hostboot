/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/check.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>

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
    .setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_2>()
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

///
/// @brief Check FIR bits during draminit training
/// @param[in] i_target the dimm that was trained
/// @note We check for fir errors after training each rank
/// to see if there was a problem with the engine.
/// FFDC errors returned from this will be handled similar to other training errors:
/// Logged as informational if it affects less than a nibble and a bit.
/// Reported if it affects more than that
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode during_draminit_training( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Creating a mask to check for FIR errors.
    // These are DP16 parity errors that would be triggered in case of an init cal error
    // During draminit_training, this would mean a training error dealing with the PHY
    fapi2::buffer<uint64_t> l_phyfir_mask;
    l_phyfir_mask.setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_2>();

    fapi2::buffer<uint64_t> l_phyfir_data;
    fapi2::buffer<uint64_t> l_phyfir_masked;

    // If we have a FIR that is lit up, we want to see if it could have been caused by a more drastic FIR
    bool l_check_fir = false;

    FAPI_TRY( mss::getScom(l_mca, MCA_IOM_PHY0_DDRPHY_FIR_REG, l_phyfir_data) );

    l_phyfir_masked = l_phyfir_data & l_phyfir_mask;

    // Clear the PHY FIR ERROR 2 bit so we don't keep failing training and training advance on this port
    // We'll have the error log to know what fir bit triggered and when, so we should be fine clearing here
    FAPI_TRY( mss::putScom(l_mca, MCA_IOM_PHY0_DDRPHY_FIR_REG_AND, l_phyfir_mask.invert()) );

    // Check the FIR here
    l_check_fir = true;
    FAPI_ASSERT( l_phyfir_masked == 0,
                 fapi2::MSS_DRAMINIT_TRAINING_PORT_FIR()
                 .set_PHY_FIR(l_phyfir_masked)
                 .set_DIMM_TARGET(i_target)
                 .set_MCA_TARGET(l_mca),
                 "Initial CAL failed: Reporting FIR bits set for %s ( phy: 0x%016lx )",
                 mss::c_str(i_target), l_phyfir_masked);

fapi_try_exit:

    // Handle any fails seen above accordingly
    return mss::check::fir_or_pll_fail( i_target, fapi2::current_err, l_check_fir);
}

// Declares FIR registers that are re-used between multiple functions
// Vectors of FIR and mask registers to read through
// As check_fir can be called in multiple places, we don't know what the mask may hold
// In order to tell if a FIR is legit or not, we read the FIR and check it against the mask reg
// Note: using a vector here in case we need to expand
static const std::vector<std::pair<uint64_t, uint64_t>> MCBIST_FIR_REGS =
{
    // MCBIST FIR
    {MCBIST_MCBISTFIRQ, MCBIST_MCBISTFIRMASK},
};

static const std::vector<std::pair<uint64_t, uint64_t>> MCA_FIR_REGS =
{
    // MCA ECC FIR
    {MCA_FIR, MCA_MASK},
    // MCA CAL FIR
    {MCA_MBACALFIRQ, MCA_MBACALFIR_MASK},
    // DDRPHY FIR
    {MCA_IOM_PHY0_DDRPHY_FIR_REG, MCA_IOM_PHY0_DDRPHY_FIR_MASK_REG},
};

///
/// @brief Checks whether any of the PLL unlock values are set
/// @param[in] i_local_fir - the overall FIR register
/// @param[in] i_perv_fir - the pervasive PLL FIR
/// @param[in] i_mc_fir - the memory controller FIR
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
bool pll_unlock( const fapi2::buffer<uint64_t>& i_local_fir,
                 const fapi2::buffer<uint64_t>& i_perv_fir,
                 const fapi2::buffer<uint64_t>& i_mc_fir )
{
    // Note: the following registers did not have the scom fields defined, so we're constexpr'ing them here
    constexpr uint64_t PERV_TP_ERROR_START = 25;
    constexpr uint64_t PERV_TP_ERROR_LEN = 4;
    constexpr uint64_t PERV_MC_ERROR_START = 25;

    // No overall FIR (bit 21) was set, so just exit
    if(!i_local_fir.getBit<PERV_1_LOCAL_FIR_IN21>())
    {
        FAPI_INF("Did not have the PERV_LOCAL_FIR bit set. No PLL error, exiting");
        return false;
    }

    // Now, identify whether a PLL unlock caused the FIR bit to fail
    FAPI_INF("PERV_TP_ERROR_REG %s PERV_MC01_ERROR_REG %s",
             i_perv_fir.getBit<PERV_TP_ERROR_START, PERV_TP_ERROR_LEN>() ? "PLL lock fail" : "PLL ok",
             i_mc_fir.getBit<PERV_MC_ERROR_START>() ? "PLL lock fail" : "PLL ok");

    // We have a PLL unlock if the MC PLL unlock FIR bit is on or any of the TP PLL unlock bits are on
    return (i_mc_fir.getBit<PERV_MC_ERROR_START>()) || (i_perv_fir.getBit<PERV_TP_ERROR_START, PERV_TP_ERROR_LEN>());
}

///
/// @brief Checks whether any PLL FIRs have been set on a target
/// @param[in] i_target - the target on which to operate
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pll_fir( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target, bool& o_fir_error )
{
    // Sets o_fir_error to false to begin with, just in case we have scom issues
    o_fir_error = false;

    // Gets the processor target
    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);

    // Gets the register data
    fapi2::buffer<uint64_t> l_local_fir;
    fapi2::buffer<uint64_t> l_perv_fir;
    fapi2::buffer<uint64_t> l_mc_fir;

    FAPI_TRY(mss::getScom(l_proc, PERV_TP_LOCAL_FIR, l_local_fir), "%s failed to get 0x%016llx", mss::c_str(i_target),
             PERV_TP_LOCAL_FIR);
    FAPI_TRY(mss::getScom(l_proc, PERV_TP_ERROR_REG, l_perv_fir), "%s failed to get 0x%016llx", mss::c_str(i_target),
             PERV_TP_ERROR_REG);
    FAPI_TRY(mss::getScom(i_target, PERV_MC01_ERROR_REG, l_mc_fir), "%s failed to get 0x%016llx", mss::c_str(i_target),
             PERV_MC01_ERROR_REG);

    // Checks the data
    o_fir_error = pll_unlock(l_local_fir, l_perv_fir, l_mc_fir);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether any FIR have lit up
/// @param[in] i_target - the target on which to operate - MCBIST specialization
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode bad_fir_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target, bool& o_fir_error )
{
    // Start by assuming we do not have a FIR
    o_fir_error = false;

    // Loop, check the scoms, and check the FIR
    // Note: we return out if any FIR is bad
    for(const auto& l_fir_reg : MCBIST_FIR_REGS)
    {
        FAPI_TRY(fir_with_mask(i_target, l_fir_reg, o_fir_error));

        // Exit if we found a FIR
        if(o_fir_error)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

    // Loop through all MCA's and all MCA FIR's
    for(const auto& l_mca : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        for(const auto& l_fir_reg : MCA_FIR_REGS)
        {
            FAPI_TRY(fir_with_mask(l_mca, l_fir_reg, o_fir_error));

            // Exit if we found a FIR
            if(o_fir_error)
            {
                return fapi2::FAPI2_RC_SUCCESS;
            }
        }
    }

    // Lastly, check for PLL unlocks
    FAPI_TRY(pll_fir(i_target, o_fir_error));

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Checks whether any FIR have lit up
/// @param[in] i_target - the target on which to operate - MCA specialization
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode bad_fir_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, bool& o_fir_error )
{
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    // Start by assuming we do not have a FIR
    o_fir_error = false;

    // Loop, check the scoms, and check the FIR
    // Note: we return out if any FIR is bad
    for(const auto& l_fir_reg : MCBIST_FIR_REGS)
    {
        FAPI_TRY(fir_with_mask(l_mcbist, l_fir_reg, o_fir_error));

        // Exit if we found a FIR
        if(o_fir_error)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

    // Loop through all MCA FIR's
    for(const auto& l_fir_reg : MCA_FIR_REGS)
    {
        FAPI_TRY(fir_with_mask(i_target, l_fir_reg, o_fir_error));

        // Exit if we found a FIR
        if(o_fir_error)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

    // Lastly, check for PLL unlocks
    FAPI_TRY(pll_fir(l_mcbist, o_fir_error));

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Checks whether any FIR have lit up
/// @param[in] i_target - the target on which to operate - DIMM specialization
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode bad_fir_bits( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, bool& o_fir_error )
{
    const auto l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    return bad_fir_bits(l_mca, o_fir_error);
}

}
}
