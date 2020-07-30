/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/exp_i2c_fields.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file exp_i2c_fields.H
/// @brief explorer I2C field definition and operations
///
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EXP_I2C_FIELDS_H_
#define _MSS_EXP_I2C_FIELDS_H_

#include <functional>
#ifdef __PPE__
    #include <mss_field.H>
    #include <exp_consts.H>
#else
    #include <generic/memory/lib/utils/mss_field.H>
    #include <lib/shared/exp_consts.H>
#endif

namespace mss
{
namespace exp
{
namespace i2c
{

///
/// @class fields
/// @brief Explorer I2C command fields
/// @tparam E Endian type
///
struct fields
{
    // First value is byte index, then buffer extract start bit, and extract data length

    // Part of EXP_FW_BOOT_CONFIG
    static constexpr mss::field_t<mss::endian::BIG> DFE_DISABLE{0, 0, 1};
    static constexpr mss::field_t<mss::endian::BIG> LANE_MODE{0, 1, 3};
    static constexpr mss::field_t<mss::endian::BIG> SERDES_FREQ{0, 4, 4};
    static constexpr mss::field_t<mss::endian::BIG> ADAPTATION_MODE{1, 0, 1};
    static constexpr mss::field_t<mss::endian::BIG> FW_MODE{1, 1, 2};
    static constexpr mss::field_t<mss::endian::BIG> LOOPBACK_TEST{1, 3, 1};
    static constexpr mss::field_t<mss::endian::BIG> TRANSPORT_LAYER{1, 4, 2};
    static constexpr mss::field_t<mss::endian::BIG> DL_LAYER_BOOT_MODE{1, 6, 2};

    // Part of EXP_FW_STATUS
    static constexpr mss::field_t<mss::endian::BIG> CMD_ID{0, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> STATUS_CODE{1, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> BOOT_STAGE{2, 6, 2};
#ifndef __PPE__
    // Part of EXP_FW_TWI_FFE_SETTINGS
    static constexpr mss::field_t<mss::endian::BIG> FFE_POST_CURSOR_BYTE0{0, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> FFE_POST_CURSOR_BYTE1{1, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> FFE_POST_CURSOR_BYTE2{2, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> FFE_POST_CURSOR_BYTE3{3, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> FFE_PRE_CURSOR_BYTE0{4, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> FFE_PRE_CURSOR_BYTE1{5, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> FFE_PRE_CURSOR_BYTE2{6, 0, 8};
    static constexpr mss::field_t<mss::endian::BIG> FFE_PRE_CURSOR_BYTE3{7, 0, 8};
#endif
};

///
/// @class fieldTraits
/// @brief Traits assoiated with the Explorer I2C commands
/// @tparam F the Explorer I2C field
///
template < const mss::field_t<endian::BIG>& F >
struct fieldTraits;

///
/// @class fieldTraits - SERDES_FREQ specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template <>
struct fieldTraits<fields::SERDES_FREQ>
{
    static constexpr uint8_t COMPARISON_VAL = 0x0F;
    static constexpr const char* FIELD_STR = "SerDes Frequency";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - LANE_MODE specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template <>
struct fieldTraits<fields::LANE_MODE>
{
    static constexpr uint8_t COMPARISON_VAL = 0x02;
    static constexpr const char* FIELD_STR = "Lane mode";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - DFE_DISABLE specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template <>
struct fieldTraits<fields::DFE_DISABLE>
{
    static constexpr uint8_t COMPARISON_VAL = 0x01;
    static constexpr const char* FIELD_STR = "DFE Disable";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - DL_LAYER_BOOT_MODE specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template <>
struct fieldTraits<fields::DL_LAYER_BOOT_MODE>
{
    static constexpr uint8_t COMPARISON_VAL = 0x01;
    static constexpr const char* FIELD_STR = "DL Layer Boot mode";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - TRANSPORT_LAYER specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template <>
struct fieldTraits<fields::TRANSPORT_LAYER>
{
    static constexpr uint8_t COMPARISON_VAL = 0x02;
    static constexpr const char* FIELD_STR = "Transport Layer";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - LOOPBACK_TEST specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template <>
struct fieldTraits<fields::LOOPBACK_TEST>
{
    static constexpr uint8_t COMPARISON_VAL = 0x01;
    static constexpr const char* FIELD_STR = "OpenCapi looptest test";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - FW_MODE specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template <>
struct fieldTraits<fields::FW_MODE>
{
    static constexpr uint8_t COMPARISON_VAL = 0x02;
    static constexpr const char* FIELD_STR = "FW Mode";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - ADAPTATION_MODE specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template <>
struct fieldTraits<fields::ADAPTATION_MODE>
{
    static constexpr uint8_t COMPARISON_VAL = 0x01;
    static constexpr const char* FIELD_STR = "Adaptation Mode";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - CMD_ID specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::CMD_ID>
{
    static constexpr uint8_t COMPARISON_VAL = 0xFF;
    static constexpr const char* FIELD_STR = "Command ID";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - STATUS_CODE specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::STATUS_CODE>
{
    static constexpr uint8_t COMPARISON_VAL = 0xFF;
    static constexpr const char* FIELD_STR = "Status Code";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - BOOT_STAGE specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::BOOT_STAGE>
{
    static constexpr uint8_t COMPARISON_VAL = 0x03;
    static constexpr const char* FIELD_STR = "Boot Stage";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

#ifndef __PPE__
///
/// @class fieldTraits - FFE_PRE_CURSOR_BYTE0 specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::FFE_PRE_CURSOR_BYTE0>
{
    static constexpr uint8_t COMPARISON_VAL = 0x00;
    static constexpr const char* FIELD_STR = "FFE Pre-cursor, byte 0";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - FFE_PRE_CURSOR_BYTE1 specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::FFE_PRE_CURSOR_BYTE1>
{
    static constexpr uint8_t COMPARISON_VAL = 0x00;
    static constexpr const char* FIELD_STR = "FFE Pre-cursor, byte 1";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - FFE_PRE_CURSOR_BYTE2 specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::FFE_PRE_CURSOR_BYTE2>
{
    static constexpr uint8_t COMPARISON_VAL = 0x00;
    static constexpr const char* FIELD_STR = "FFE Pre-cursor, byte 2";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - FFE_PRE_CURSOR_BYTE3 specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::FFE_PRE_CURSOR_BYTE3>
{
    static constexpr uint8_t COMPARISON_VAL = 0x20;
    static constexpr const char* FIELD_STR = "FFE Pre-cursor, byte 3";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - FFE_POST_CURSOR_BYTE0 specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::FFE_POST_CURSOR_BYTE0>
{
    static constexpr uint8_t COMPARISON_VAL = 0x00;
    static constexpr const char* FIELD_STR = "FFE Post-cursor, byte 0";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - FFE_POST_CURSOR_BYTE1 specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::FFE_POST_CURSOR_BYTE1>
{
    static constexpr uint8_t COMPARISON_VAL = 0x00;
    static constexpr const char* FIELD_STR = "FFE Post-cursor, byte 1";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - FFE_POST_CURSOR_BYTE2 specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::FFE_POST_CURSOR_BYTE2>
{
    static constexpr uint8_t COMPARISON_VAL = 0x00;
    static constexpr const char* FIELD_STR = "FFE Post-cursor, byte 2";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class fieldTraits - FFE_POST_CURSOR_BYTE3 specialization
/// @brief Traits assoiated with the Explorer I2C commands
///
template<>
struct fieldTraits<fields::FFE_POST_CURSOR_BYTE3>
{
    static constexpr uint8_t COMPARISON_VAL = 0x20;
    static constexpr const char* FIELD_STR = "FFE Post-cursor, byte 3";

    template <typename T>
    using COMPARISON_OP = std::less_equal<T>;
};
#endif

///
/// @brief Explorer I2C field getter
/// @tparam F the explorer I2C field
/// @tparam IT Input type
/// @tparam OT Output type
/// @tparam TT Traits associated with exp I2C - defaults to fieldTraits<F>
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_value the output value received
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const mss::field_t<endian::BIG>& F,
          typename IT,
          typename OT,
          typename TT = fieldTraits<F> >
inline fapi2::ReturnCode get_field(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   const std::vector<IT>& i_data,
                                   OT& o_value)
{
    return mss::get_field<endian::BIG, F, TT>(i_target, i_data, EXP_I2C_GET_FIELD, o_value);
}

#ifndef __PPE__
///
/// @brief Explorer I2C field setter
/// @tparam IT Input type
/// @tparam OT Output type
/// @tparam TT Traits associated with exp I2C - defaults to fieldTraits<F>
/// @param[in] i_target the OCMB target
/// @param[in] i_value the input value to set
/// @param[in,out] io_data the buffer as a reference to a vector
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const mss::field_t<endian::BIG>& F,
          typename IT,
          typename OT,
          typename TT = fieldTraits<F> >
inline fapi2::ReturnCode set_field(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   std::vector<OT>& io_data,
                                   const IT i_value)

{
    return mss::set_field<endian::BIG, F, TT>(i_target, i_value, EXP_I2C_SET_FIELD, io_data);
}

namespace boot_cfg
{

///
/// @brief SERDES_FREQ getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_serdes_freq(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        uint8_t& o_setting)
{
    return get_field<fields::SERDES_FREQ>(i_target, i_data, o_setting);
}

///
/// @brief SERDES_FREQ setter
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the buffer as a reference to a vector
/// @param[in] i_freq frequency to set
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_serdes_freq(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  std::vector<uint8_t>& io_data,
                                  const uint32_t i_freq);

///
/// @brief LANE_MODE getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_lane_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const std::vector<uint8_t>& i_data,
                                       uint8_t& o_setting)
{
    return get_field<fields::LANE_MODE>(i_target, i_data, o_setting);
}

///
/// @brief LANE_MODE setter
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the buffer as a reference to a vector
/// @param[in] i_setting the value to set
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_lane_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       std::vector<uint8_t>& io_data,
                                       const uint8_t i_setting)
{
    return set_field<fields::LANE_MODE>(i_target, io_data, i_setting);
}

///
/// @brief DFE_DISABLE getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_dfe_disable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        uint8_t& o_setting)
{
    return get_field<fields::DFE_DISABLE>(i_target, i_data, o_setting);
}

///
/// @brief DFE_DISABLE setter
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the buffer as a reference to a vector
/// @param[in] i_setting the value to set
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_dfe_disable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<uint8_t>& io_data,
        const uint8_t i_setting)
{
    return set_field<fields::DFE_DISABLE>(i_target, io_data, i_setting);
}

/// @brief DL_LAYER_BOOT_MODE getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_dl_layer_boot_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        uint8_t& o_setting)
{
    return get_field<fields::DL_LAYER_BOOT_MODE>(i_target, i_data, o_setting);
}

///
/// @brief DL_LAYER_BOOT_MODE setter
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the buffer as a reference to a vector
/// @param[in] i_setting the value to set
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_dl_layer_boot_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<uint8_t>& io_data,
        const uint8_t i_setting)
{
    return set_field<fields::DL_LAYER_BOOT_MODE>(i_target, io_data, i_setting);
}

/// @brief ADAPTATION_MODE getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_adaptation_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        uint8_t& o_setting)
{
    return get_field<fields::ADAPTATION_MODE>(i_target, i_data, o_setting);
}

///
/// @brief ADAPTATION_MODE setter
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the buffer as a reference to a vector
/// @param[in] i_setting the value to set
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_adaptation_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<uint8_t>& io_data,
        const uint8_t i_setting)
{
    return set_field<fields::ADAPTATION_MODE>(i_target, io_data, i_setting);
}

///
/// @brief DL_LAYER_BOOT_MODE getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_transport_layer(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        uint8_t& o_setting)
{
    return get_field<fields::TRANSPORT_LAYER>(i_target, i_data, o_setting);
}


///
/// @brief TRANSPORT_LAYER setter
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the buffer as a reference to a vector
/// @param[in] i_setting the value to set
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_transport_layer(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<uint8_t>& io_data,
        const uint8_t i_setting)
{
    return set_field<fields::TRANSPORT_LAYER>(i_target, io_data, i_setting);
}

///
/// @brief LOOPBACK_TEST getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_loopback_test(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        uint8_t& o_setting)
{
    return get_field<fields::LOOPBACK_TEST>(i_target, i_data, o_setting);
}

///
/// @brief LOOPBACK_TEST setter
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the buffer as a reference to a vector
/// @param[in] i_setting the value to set
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_loopback_test(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<uint8_t>& io_data,
        const uint8_t i_setting)
{
    return set_field<fields::LOOPBACK_TEST>(i_target, io_data, i_setting);
}

///
/// @brief FW_MODE getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_fw_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const std::vector<uint8_t>& i_data,
                                     uint8_t& o_setting)
{
    return get_field<fields::FW_MODE>(i_target, i_data, o_setting);
}

///
/// @brief FW_MODE setter
/// @param[in] i_target the OCMB target
/// @param[in] i_setting the value to set
/// @param[in,out] io_data the buffer as a reference to a vector
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_fw_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     std::vector<uint8_t>& io_data,
                                     const uint8_t i_setting)
{
    return set_field<fields::FW_MODE>(i_target, io_data, i_setting);
}

}// boot_cfg


namespace ffe_settings
{

///
/// @brief FFE_PRE_CURSOR getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_pre_cursor(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        const std::vector<uint8_t>& i_data,
                                        uint32_t& o_setting)
{
    uint8_t l_byte0 = 0;
    uint8_t l_byte1 = 0;
    uint8_t l_byte2 = 0;
    uint8_t l_byte3 = 0;
    fapi2::buffer<uint32_t> l_output;

    FAPI_TRY(get_field<fields::FFE_PRE_CURSOR_BYTE0>(i_target, i_data, l_byte0));
    FAPI_TRY(get_field<fields::FFE_PRE_CURSOR_BYTE1>(i_target, i_data, l_byte1));
    FAPI_TRY(get_field<fields::FFE_PRE_CURSOR_BYTE2>(i_target, i_data, l_byte2));
    FAPI_TRY(get_field<fields::FFE_PRE_CURSOR_BYTE3>(i_target, i_data, l_byte3));

    l_output.insertFromRight<0, BITS_PER_BYTE>(l_byte0);
    l_output.insertFromRight<8, BITS_PER_BYTE>(l_byte1);
    l_output.insertFromRight<16, BITS_PER_BYTE>(l_byte2);
    l_output.insertFromRight<24, BITS_PER_BYTE>(l_byte3);

    o_setting = l_output;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief FFE_PRE_CURSOR setter
/// @param[in] i_target the OCMB target
/// @param[in] i_setting the value to set
/// @param[in,out] io_data the buffer as a reference to a vector
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_pre_cursor(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        std::vector<uint8_t>& io_data,
                                        const uint32_t i_setting)
{
    uint8_t l_byte = 0;
    fapi2::buffer<uint32_t> l_input(i_setting);

    l_input.extractToRight<0, BITS_PER_BYTE>(l_byte);
    FAPI_TRY(set_field<fields::FFE_PRE_CURSOR_BYTE0>(i_target, io_data, l_byte));
    l_input.extractToRight<8, BITS_PER_BYTE>(l_byte);
    FAPI_TRY(set_field<fields::FFE_PRE_CURSOR_BYTE1>(i_target, io_data, l_byte));
    l_input.extractToRight<16, BITS_PER_BYTE>(l_byte);
    FAPI_TRY(set_field<fields::FFE_PRE_CURSOR_BYTE2>(i_target, io_data, l_byte));
    l_input.extractToRight<24, BITS_PER_BYTE>(l_byte);
    FAPI_TRY(set_field<fields::FFE_PRE_CURSOR_BYTE3>(i_target, io_data, l_byte));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief FFE_POST_CURSOR getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_post_cursor(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        uint32_t& o_setting)
{
    uint8_t l_byte0 = 0;
    uint8_t l_byte1 = 0;
    uint8_t l_byte2 = 0;
    uint8_t l_byte3 = 0;
    fapi2::buffer<uint32_t> l_output;

    FAPI_TRY(get_field<fields::FFE_POST_CURSOR_BYTE0>(i_target, i_data, l_byte0));
    FAPI_TRY(get_field<fields::FFE_POST_CURSOR_BYTE1>(i_target, i_data, l_byte1));
    FAPI_TRY(get_field<fields::FFE_POST_CURSOR_BYTE2>(i_target, i_data, l_byte2));
    FAPI_TRY(get_field<fields::FFE_POST_CURSOR_BYTE3>(i_target, i_data, l_byte3));

    l_output.insertFromRight<0, BITS_PER_BYTE>(l_byte0);
    l_output.insertFromRight<8, BITS_PER_BYTE>(l_byte1);
    l_output.insertFromRight<16, BITS_PER_BYTE>(l_byte2);
    l_output.insertFromRight<24, BITS_PER_BYTE>(l_byte3);

    o_setting = l_output;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief FFE_POST_CURSOR setter
/// @param[in] i_target the OCMB target
/// @param[in] i_setting the value to set
/// @param[in,out] io_data the buffer as a reference to a vector
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_post_cursor(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<uint8_t>& io_data,
        const uint32_t i_setting)
{
    uint8_t l_byte = 0;
    fapi2::buffer<uint32_t> l_input(i_setting);

    l_input.extractToRight<0, BITS_PER_BYTE>(l_byte);
    FAPI_TRY(set_field<fields::FFE_POST_CURSOR_BYTE0>(i_target, io_data, l_byte));
    l_input.extractToRight<8, BITS_PER_BYTE>(l_byte);
    FAPI_TRY(set_field<fields::FFE_POST_CURSOR_BYTE1>(i_target, io_data, l_byte));
    l_input.extractToRight<16, BITS_PER_BYTE>(l_byte);
    FAPI_TRY(set_field<fields::FFE_POST_CURSOR_BYTE2>(i_target, io_data, l_byte));
    l_input.extractToRight<24, BITS_PER_BYTE>(l_byte);
    FAPI_TRY(set_field<fields::FFE_POST_CURSOR_BYTE3>(i_target, io_data, l_byte));

fapi_try_exit:
    return fapi2::current_err;
}

}// ffe_settings

#endif
namespace status
{

///
/// @brief BOOT_STAGE getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_boot_stage(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        const std::vector<uint8_t>& i_data,
                                        uint8_t& o_setting)
{
    return get_field<fields::BOOT_STAGE>(i_target, i_data, o_setting);
}


///
/// @brief STATUS_CODE getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_status_code(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        uint8_t& o_setting)
{
    return get_field<fields::STATUS_CODE>(i_target, i_data, o_setting);
}

#ifndef __PPE__
///
/// @brief CMD_ID getter
/// @param[in] i_target the OCMB target
/// @param[in] i_data the buffer as a reference to a vector
/// @param[out] o_setting
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_cmd_id(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const std::vector<uint8_t>& i_data,
                                    uint8_t& o_setting)
{
    return get_field<fields::CMD_ID>(i_target, i_data, o_setting);
}
#endif

}// status
}// i2c
}// exp
}// mss

#endif
