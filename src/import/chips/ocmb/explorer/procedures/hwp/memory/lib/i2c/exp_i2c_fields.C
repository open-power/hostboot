/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/exp_i2c_fields.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
#include <lib/i2c/exp_i2c_fields.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{
namespace exp
{
namespace i2c
{

// If a constexpr static data member (since C++11) is odr-used,
// a definition at namespace scope is still required, but it cannot have an initializer.
constexpr mss::field_t<mss::endian::BIG> fields::DFE_DISABLE;
constexpr mss::field_t<mss::endian::BIG> fields::LANE_MODE;
constexpr mss::field_t<mss::endian::BIG> fields::SERDES_FREQ;
constexpr mss::field_t<mss::endian::BIG> fields::FW_MODE;
constexpr mss::field_t<mss::endian::BIG> fields::LOOPBACK_TEST;
constexpr mss::field_t<mss::endian::BIG> fields::TRANSPORT_LAYER;
constexpr mss::field_t<mss::endian::BIG> fields::DL_LAYER_BOOT_MODE;
constexpr mss::field_t<mss::endian::BIG> fields::CMD_ID;
constexpr mss::field_t<mss::endian::BIG> fields::STATUS_CODE;
constexpr mss::field_t<mss::endian::BIG> fields::BOOT_STAGE;
constexpr mss::field_t<mss::endian::BIG> fields::FW_API_VERSION;

namespace boot_cfg
{

///
/// @brief SERDES_FREQ setter
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the buffer as a reference to a vector
/// @param[in] i_freq frequency to set
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_serdes_freq(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  std::vector<uint8_t>& io_data,
                                  const uint32_t i_freq)
{
    static const std::vector< std::pair<uint32_t, uint8_t> > OMI_FREQ_MAP =
    {
        {fapi2::ENUM_ATTR_FREQ_OMI_MHZ_21330, 1},
        {fapi2::ENUM_ATTR_FREQ_OMI_MHZ_23460, 2},
        {fapi2::ENUM_ATTR_FREQ_OMI_MHZ_25600, 3},
        // All others reserved or not supported
    };

    uint8_t l_setting = 0;
    const bool l_is_val_found = mss::find_value_from_key(OMI_FREQ_MAP, i_freq, l_setting);

    FAPI_ASSERT( l_is_val_found,
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(i_freq)
                 .set_DATA(l_setting)
                 .set_FUNCTION(SET_SERDES_FREQ)
                 .set_TARGET(i_target),
                 "Failed to find a BOOT_CONFIG setting for OMI value %d on %s",
                 i_freq,
                 mss::c_str(i_target) );

    return set_field<fields::SERDES_FREQ>(i_target, io_data, l_setting);

fapi_try_exit:
    return fapi2::current_err;
}

}// boot_cfg

}// i2c
}// exp
}// mss
