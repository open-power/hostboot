/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dqs_align_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#include <fapi2.H>
#include <lib/workarounds/dqs_align_workarounds.H>
#include <p9_mc_scom_addresses.H>
#include <mss_attribute_accessors.H>
#include <lib/phy/seq.H>
#include <lib/phy/phy_cntrl.H>

namespace mss
{

namespace workarounds
{

namespace dqs_align
{

///
/// @brief Sets tRFC cyles for sequencer
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode set_timing0_trfc(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    // May need to add freq/tRFI attr dependency later but for now use this value
    // Provided by Ryan King
    constexpr size_t TRFC_CYCLES = 9;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY( mss::seq::read_timing0(i_target, l_data) );

    mss::seq::set_trfc_cycles(l_data, TRFC_CYCLES);
    FAPI_TRY( mss::seq::write_timing0(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set PHY sequencer to trigger refresh during init cal
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode set_init_cal_refresh(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    // Hard coded settings provided by Ryan King for this workaround
    constexpr size_t REF_COUNT = 0xF;
    constexpr size_t REF_CNTL = 0b11;
    constexpr size_t REF_INTERVAL = 0b0010011;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY( mss::pc::read_init_cal_config1(i_target, l_data) );

    mss::pc::set_refresh_count(l_data, REF_COUNT);
    mss::pc::set_refresh_control(l_data, REF_CNTL);
    mss::pc::set_refresh_all_ranks(l_data, mss::HIGH);
    mss::pc::set_snoop_dis(l_data, mss::LOW);
    mss::pc::set_refresh_interval(l_data, REF_INTERVAL);

    FAPI_TRY( mss::pc::write_init_cal_config1(i_target, l_data) )

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clear the PHY sequencer refresh
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode clear_init_cal_refresh(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    // Turns off refresh
    constexpr size_t REF_CNTL = 0b00;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY( mss::pc::read_init_cal_config1(i_target, l_data) );

    mss::pc::set_refresh_control(l_data, REF_CNTL);

    FAPI_TRY( mss::pc::write_init_cal_config1(i_target, l_data) )

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set PHY sequencer to trigger refresh during init cal
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode turn_on_refresh(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    uint8_t l_attr = 0;
    FAPI_TRY( mss::phy_seq_refresh(i_target, l_attr) );

    if( l_attr == fapi2::ENUM_ATTR_MSS_PHY_SEQ_REFRESH_DISABLE )
    {
        FAPI_INF("Skipping workaround to trigger refresh for the PHY sequencer %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( set_timing0_trfc(i_target),
              "set_timing0_trfc() failed for %s", mss::c_str(i_target) );

    FAPI_TRY( set_init_cal_refresh(i_target),
              "set_init_cal_refresh() failed for %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Turn off refresh after dqs training has been run
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode turn_off_refresh(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    uint8_t l_attr = 0;
    FAPI_TRY( mss::phy_seq_refresh(i_target, l_attr) );

    if( l_attr == fapi2::ENUM_ATTR_MSS_PHY_SEQ_REFRESH_DISABLE )
    {
        FAPI_INF("Refresh for PHY sequencer is already off %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( clear_init_cal_refresh(i_target),
              "set_init_cal_refresh() failed for %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

}
}
}
