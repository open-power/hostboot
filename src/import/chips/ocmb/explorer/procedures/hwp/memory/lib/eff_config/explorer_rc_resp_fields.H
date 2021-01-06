/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_rc_resp_fields.H $ */
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

#include <fapi2.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/mss_field.H>

namespace mss
{
namespace exp
{

///
/// @class rc_resp_adaptor
/// @brief Adaptor to plug into mss::gen::attr_engine::set(...) algorithm
///
struct rc_resp_adaptor
{
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
    user_response_rc_msdg_t iv_rc_resp;

    ///
    /// @brief Construct a new rc resp adaptor object - default
    ///
    rc_resp_adaptor() = default;

    ///
    /// @brief Construct a new rc resp adaptor object
    /// @param[in] i_target the OCMB target associated with this rc response
    /// @param[in] i_rc_resp the explorer rc resp structure
    ///
    rc_resp_adaptor(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                    const user_response_rc_msdg_t& i_rc_resp) : iv_target(i_target), iv_rc_resp(i_rc_resp) {}

    ///
    /// @brief default copy constructor
    ///
    rc_resp_adaptor(const rc_resp_adaptor&) = default;

    ///
    /// @brief default assignment constructor
    /// @return rc_resp_adaptor&
    ///
    rc_resp_adaptor& operator=(const rc_resp_adaptor&) = default;

    ///
    /// @brief Destroy the rc resp adaptor object
    ///
    ~rc_resp_adaptor() = default;

    ///
    /// @brief target getter
    /// @return fapi2::Target<fapi2::TARGET_TYPE_DIMM> by value
    ///
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> get_target() const
    {
        return iv_target;
    }
};

///
/// @class rc_rsp_fields
/// @brief Explorer rc response fields
///
struct rc_rsp_fields
{
    enum
    {
        // F0RC00
        F0RC00_IDX = 0x00,
        F0RC00_START = 4,
        F0RC00_LEN = 4,

        // F0RC01
        F0RC01_IDX = 0x01,
        F0RC01_START = 4,
        F0RC01_LEN = 4,

        // F0RC03
        F0RC03_IDX = 0x03,
        F0RC03_START = 4,
        F0RC03_LEN = 4,

        // F0RC04
        F0RC04_IDX = 0x04,
        F0RC04_START = 4,
        F0RC04_LEN = 4,

        // F0RC05
        F0RC05_IDX = 0x05,
        F0RC05_START = 4,
        F0RC05_LEN = 4,

        // F0RC0B
        F0RC0B_IDX = 0x0B,
        F0RC0B_START = 4,
        F0RC0B_LEN = 4,

        // F0RC0E
        F0RC0E_IDX = 0x0E,
        F0RC0E_START = 4,
        F0RC0E_LEN = 4,

        // F0RC0F
        F0RC0F_IDX = 0x0F,
        F0RC0F_START = 4,
        F0RC0F_LEN = 4,

        // F0RC1X
        F0RC1X_IDX = 0x10,
        F0RC1X_START = 0,
        F0RC1X_LEN = 8,

        // F0RC7X
        F0RC7X_IDX = 0x17,
        F0RC7X_START = 0,
        F0RC7X_LEN = 8,

        // F1RC00
        F1RC00_IDX = 0x00,
        F1RC00_START = 4,
        F1RC00_LEN = 4,

        // F1RC02
        F1RC02_IDX = 0x01,
        F1RC02_START = 4,
        F1RC02_LEN = 4,

        // F1RC03
        F1RC03_IDX = 0x03,
        F1RC03_START = 4,
        F1RC03_LEN = 4,

        // F1RC04
        F1RC04_IDX = 0x04,
        F1RC04_START = 4,
        F1RC04_LEN = 4,

        // F1RC05
        F1RC05_IDX = 0x05,
        F1RC05_START = 4,
        F1RC05_LEN = 4,
    };

    // First value is byte index, then buffer extract start bit, and extract data length
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC00{F0RC00_IDX, F0RC00_START, F0RC00_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC01{F0RC01_IDX, F0RC01_START, F0RC01_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC03{F0RC03_IDX, F0RC03_START, F0RC03_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC04{F0RC04_IDX, F0RC04_START, F0RC04_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC05{F0RC05_IDX, F0RC05_START, F0RC05_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC0B{F0RC0B_IDX, F0RC0B_START, F0RC0B_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC0E{F0RC0E_IDX, F0RC0E_START, F0RC0E_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC0F{F0RC0F_IDX, F0RC0F_START, F0RC0F_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC1X{F0RC1X_IDX, F0RC1X_START, F0RC1X_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F0RC7X{F0RC7X_IDX, F0RC7X_START, F0RC7X_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F1RC00{F1RC00_IDX, F1RC00_START, F1RC00_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F1RC02{F1RC02_IDX, F1RC02_START, F1RC02_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F1RC03{F1RC03_IDX, F1RC03_START, F1RC03_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F1RC04{F1RC04_IDX, F1RC04_START, F1RC04_LEN};
    static constexpr mss::field_t<mss::endian::LITTLE> F1RC05{F1RC05_IDX, F1RC05_START, F1RC05_LEN};
};

using attr_setter = fapi2::ReturnCode (*)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, uint8_t);

///
/// @brief Helper function to retrieve the F0RC_D0 data
/// @param[in] i_rc_resp explorer RC response adapter
/// @param[out] o_output copy of response in vector form
/// @note DIMM0 data
///
inline void get_data_F0RC_D0(const rc_resp_adaptor& i_rc_resp,
                             std::vector<uint8_t>& o_output)
{
    o_output.assign(MAX_RCW_RESP_ARRAY_SIZE, 0);
    std::copy(std::begin(i_rc_resp.iv_rc_resp.F0RC_D0), std::end(i_rc_resp.iv_rc_resp.F0RC_D0), std::begin(o_output));
}

///
/// @brief Helper function to retrieve the F0RC_D1 data
/// @param[in] i_rc_resp explorer RC response adapter
/// @param[out] o_output copy of response in vector form
/// @note DIMM1 data
///
inline void get_data_F0RC_D1(const rc_resp_adaptor& i_rc_resp,
                             std::vector<uint8_t>& o_output)
{
    o_output.assign(MAX_RCW_RESP_ARRAY_SIZE, 0);
    std::copy(std::begin(i_rc_resp.iv_rc_resp.F0RC_D1), std::end(i_rc_resp.iv_rc_resp.F0RC_D1), std::begin(o_output));
}

///
/// @brief Helper function to retrieve the F1RC_D0 data
/// @param[in] i_rc_resp explorer RC response adapter
/// @param[out] o_output copy of response in vector form
/// @note DIMM0 data
///
inline void get_data_F1RC_D0(const rc_resp_adaptor& i_rc_resp,
                             std::vector<uint8_t>& o_output)
{
    o_output.assign(MAX_RCW_RESP_ARRAY_SIZE, 0);
    std::copy(std::begin(i_rc_resp.iv_rc_resp.F1RC_D0), std::end(i_rc_resp.iv_rc_resp.F1RC_D0), std::begin(o_output));
}

///
/// @brief Helper function to retrieve the F1RC_D1 data
/// @param[in] i_rc_resp explorer RC response adapter
/// @param[out] o_output copy of response in vector form
/// @note DIMM1 data
///
inline void get_data_F1RC_D1(const rc_resp_adaptor& i_rc_resp,
                             std::vector<uint8_t>& o_output)
{
    o_output.assign(MAX_RCW_RESP_ARRAY_SIZE, 0);
    std::copy(std::begin(i_rc_resp.iv_rc_resp.F1RC_D1), std::end(i_rc_resp.iv_rc_resp.F1RC_D1), std::begin(o_output));
}

///
/// @brief Set the rc resp field object
///
/// @param[in] i_dimm DIMM target
/// @param[in] i_pair Pair of field to matching attr setter
/// @param[in] i_cw_binary CW binary vector
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
inline fapi2::ReturnCode set_rc_resp_field(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::pair<mss::field_t<mss::endian::LITTLE>, attr_setter>& i_pair,
    const std::vector<uint8_t>& i_cw_binary)
{
    uint8_t l_field = 0;
    const auto& FIELD = i_pair.first;

    {
        // Extracting desired bits
        // API enforces uint8_t vector data, so no conversion check needed to uint8_t buffer
        const fapi2::buffer<uint8_t> BYTE(i_cw_binary[FIELD.get_byte(i_cw_binary)]);
        FAPI_TRY(BYTE.extractToRight(l_field, FIELD.get_start(), FIELD.get_length()));

        // Finally, call the attribute setter
        FAPI_TRY(i_pair.second(i_dimm, l_field));
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the rc resp attrs
/// @param[in] i_rc_resp explorer RC response adapter
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
inline fapi2::ReturnCode rc_resp_engine(const rc_resp_adaptor& i_rc_resp)
{
    std::vector<uint8_t> l_f0rc;
    std::vector<uint8_t> l_f1rc;

    // Grab dimm target
    const auto& l_dimm = i_rc_resp.get_target();

    // And grab the correct data depending on the dimm index
    if (mss::index(l_dimm) == 0)
    {
        get_data_F0RC_D0(i_rc_resp, l_f0rc);
        get_data_F1RC_D0(i_rc_resp, l_f1rc);
    }
    else
    {
        get_data_F0RC_D1(i_rc_resp, l_f0rc);
        get_data_F1RC_D1(i_rc_resp, l_f1rc);
    }

    // F0RCXX fields
    const std::vector<std::pair<mss::field_t<mss::endian::LITTLE>, attr_setter>> l_f0_fields =
    {
        {exp::rc_rsp_fields::F0RC00, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc00)},
        {exp::rc_rsp_fields::F0RC01, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc01)},
        {exp::rc_rsp_fields::F0RC03, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc03)},
        {exp::rc_rsp_fields::F0RC04, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc04)},
        {exp::rc_rsp_fields::F0RC05, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc05)},
        {exp::rc_rsp_fields::F0RC0B, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc0b)},
        {exp::rc_rsp_fields::F0RC0E, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc0e)},
        {exp::rc_rsp_fields::F0RC0F, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc0f)},
        {exp::rc_rsp_fields::F0RC1X, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc1x)},
        {exp::rc_rsp_fields::F0RC7X, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f0rc7x)},
    };

    // F1RCXX fields
    const std::vector<std::pair<mss::field_t<mss::endian::LITTLE>, attr_setter>> l_f1_fields =
    {
        {exp::rc_rsp_fields::F1RC00, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f1rc00)},
        {exp::rc_rsp_fields::F1RC02, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f1rc02)},
        {exp::rc_rsp_fields::F1RC03, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f1rc03)},
        {exp::rc_rsp_fields::F1RC04, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f1rc04)},
        {exp::rc_rsp_fields::F1RC05, static_cast<attr_setter>(&mss::attr::set_exp_resp_ddr4_f1rc05)},
    };

    // Now grab the F0RCXX fields
    for (const auto& l_pair : l_f0_fields)
    {
        FAPI_TRY(set_rc_resp_field(l_dimm, l_pair, l_f0rc));
    }

    // And next, the F1RCXX fields
    for (const auto& l_pair : l_f1_fields)
    {
        FAPI_TRY(set_rc_resp_field(l_dimm, l_pair, l_f1rc));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace exp
} // namespace mss
