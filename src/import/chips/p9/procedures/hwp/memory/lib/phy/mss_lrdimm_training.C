/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file lib/phy/mss_lrdimm_training.C
/// @brief LRDIMM training implementation
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <lib/phy/mss_lrdimm_training.H>

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrep::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                             const uint64_t i_rp,
                             const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrep::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                 const uint64_t i_rp,
                                 const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mrep::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dwl::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const uint64_t i_rp,
                            const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dwl::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t dwl::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrd::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const uint64_t i_rp,
                            const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrd::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mrd::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const uint64_t i_rp,
                            const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mwd::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Deconfigures calibration steps depending upon LRDIMM type
/// @param[in] i_dimm_type - DIMM type
/// @param[in] i_sim - simulation mode or not
/// @param[in,out] io_cal_steps - the bit mask of calibration steps
/// @return a vector of the calibration steps to run
///
void deconfigure_steps(const uint8_t i_dimm_type, const bool i_sim, fapi2::buffer<uint32_t>& io_cal_steps)
{
    // If the DIMM type is an LRDIMM, configure for LRDIMM
    if(i_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)
    {
        FAPI_INF("LRDIMM: deconfigure WR VREF 2D");
        // We clear WRITE_CTR_2D_VREF as the HW calibration algorithm will not work with LRDIMM
        io_cal_steps.clearBit<WRITE_CTR_2D_VREF>();
        return;
    }

    FAPI_INF("Not LRDIMM: deconfigure all LRDIMM specific steps");
    // Otherwise, clear all LRDIMM calibration steps
    io_cal_steps.clearBit<DB_ZQCAL>()
    .clearBit<MREP>()
    .clearBit<MRD_COARSE>()
    .clearBit<MRD_FINE>()
    .clearBit<DWL>()
    .clearBit<MWD_COARSE>()
    .clearBit<MWD_FINE>()
    .clearBit<HWL>();
}


} // ns lrdimm

} // ns training

} // ns mss
