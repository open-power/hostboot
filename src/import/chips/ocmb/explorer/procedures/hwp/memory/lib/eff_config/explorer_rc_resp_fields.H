/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_rc_resp_fields.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#include <generic/memory/lib/data_engine/data_engine_utils.H>

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

} // namespace exp

namespace gen
{

///
/// @class get - TARGET_TYPE_MEM_PORT, rc_resp_adaptor specialization
/// @brief get target helper class for attr_engine
///
template <>
struct get<fapi2::TARGET_TYPE_MEM_PORT, exp::rc_resp_adaptor>
{
    ///
    /// @brief Get target for TARGET_TYPE_MEM_PORT and rc_resp_adaptor
    ///
    /// @param[in] i_data rc_resp_adaptor
    /// @return fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> Attribute target type
    ///
    static fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> target(const exp::rc_resp_adaptor& i_data)
    {
        return mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_data.iv_target);
    }
};

} // namespace gen

namespace exp
{

enum rcw_max_val : uint8_t
{
    RCW_4BIT_MAX = 0x0F,
    RCW_8BIT_MAX = 0xFF,
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
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam F holds RCW field info
///
template <const field_t<endian::LITTLE> &F>
class readerTraits;

///
/// @brief RCW reader
/// @tparam F the SPD field to read
/// @tparam OT data output type
/// @tparam TT traits associated with reader, defaulted to readerTraits<F, T>
/// @param[in] i_target the fapi2 target
/// @param[in] i_data the SPD data
/// @param[out] o_value raw value for this SPD field
/// @return FAPI2_RC_SUCCESS iff okay
/// @warning reader for F0RC_D0 and F0RC_D1 (DIMM0 vs DIMM1) are equivalent.
/// Will need to be updated if the array from the RC response structure varies.
///
template <const field_t<endian::LITTLE> &F,
          typename OT,
          typename TT = readerTraits<F>>
fapi2::ReturnCode reader(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                         const std::vector<uint8_t>& i_data,
                         OT& o_value)
{
    FAPI_TRY((mss::get_field<endian::LITTLE, F, TT>(i_target, i_data, READ_RC_RSP_FIELD, o_value)),
             "Failed read_field() for %s", spd::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC00 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC00>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Global Features Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC01 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC01>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Clock Driver Enable Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC03 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC03>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "CA and CS Signals Driver Characteristics Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC04 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC04>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "ODT and CKE Signals Driver Characteristics Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC05 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC05>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Clock Driver Characteristics Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC0B field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC0B>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Operating Voltage VDD and VREFCA Source Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC0E field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC0E>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Parity, NV Mode Enable, and ALERT Configuration Control Word ";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC0F field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC0F>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Command Latency Adder Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC1X field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC1X>
{
    static constexpr size_t COMPARISON_VAL = RCW_8BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Internal VrefCA Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F0RC7X field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F0RC7X>
{
    static constexpr size_t COMPARISON_VAL = RCW_8BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "IBT Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F1RC00 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F1RC00>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Data Buffer Interface Driver Characteristics Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F1RC02 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F1RC02>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "CA and CS Output Slew Rate Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F1RC03 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F1RC03>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "ODT and CKEn Output Slew Rate Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F1RC04 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F1RC04>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Clock Driver Output Slew Rate Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static explorer RC response information
/// @note F1RC05 field specialization
///
template <>
struct readerTraits<rc_rsp_fields::F1RC05>
{
    static constexpr size_t COMPARISON_VAL = RCW_4BIT_MAX; ///< Largest valid explorer RC resp encoding
    static constexpr const char* FIELD_STR = "Data Buffer Interface Output Slew Rate Control Word";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

} // namespace exp
} // namespace mss
