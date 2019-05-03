/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00052.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include "fapi2.H"

#ifndef __OMI_REG00052_H_
#define __OMI_REG00052_H_

namespace scomt
{
namespace omi
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CONFIG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CONFIG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CONFIG1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CONFIG1;
#endif
    return fapi2::getScom(i_target, CONFIG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CONFIG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return fapi2::putScom(i_target, CONFIG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CONFIG1_CFG1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_CFG1_SPARE,
           CONFIG1_CFG1_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_CFG1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_CFG1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_CFG1_SPARE,
           CONFIG1_CFG1_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_CFG1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_CFG1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_CFG1_SPARE,
           CONFIG1_CFG1_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_CFG1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_LANE_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_LANE_WIDTH,
           CONFIG1_LANE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_LANE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_LANE_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_LANE_WIDTH,
           CONFIG1_LANE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_LANE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_LANE_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_LANE_WIDTH,
           CONFIG1_LANE_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_LANE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_PREIPL_PRBS_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_PREIPL_PRBS_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_PREIPL_PRBS_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_PREIPL_PRBS_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_PREIPL_PRBS_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_PREIPL_PRBS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_PREIPL_PRBS_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_PREIPL_PRBS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_PREIPL_PRBS_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_PREIPL_PRBS_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CONFIG1_PREIPL_PRBS_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_PREIPL_PRBS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_PREIPL_PRBS_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_PREIPL_PRBS_TIME,
           CONFIG1_PREIPL_PRBS_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_PREIPL_PRBS_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_PREIPL_PRBS_TIME,
           CONFIG1_PREIPL_PRBS_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_PREIPL_PRBS_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_PREIPL_PRBS_TIME,
           CONFIG1_PREIPL_PRBS_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_PREIPL_PRBS_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_B_HYSTERESIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_B_HYSTERESIS,
           CONFIG1_B_HYSTERESIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_B_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_B_HYSTERESIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_B_HYSTERESIS,
           CONFIG1_B_HYSTERESIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_B_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_B_HYSTERESIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_B_HYSTERESIS,
           CONFIG1_B_HYSTERESIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_B_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_A_HYSTERESIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_A_HYSTERESIS,
           CONFIG1_A_HYSTERESIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_A_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_A_HYSTERESIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_A_HYSTERESIS,
           CONFIG1_A_HYSTERESIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_A_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_A_HYSTERESIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_A_HYSTERESIS,
           CONFIG1_A_HYSTERESIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_A_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_B_PATTERN_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_B_PATTERN_LENGTH,
           CONFIG1_B_PATTERN_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_B_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_B_PATTERN_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_B_PATTERN_LENGTH,
           CONFIG1_B_PATTERN_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_B_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_B_PATTERN_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_B_PATTERN_LENGTH,
           CONFIG1_B_PATTERN_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_B_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_A_PATTERN_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_A_PATTERN_LENGTH,
           CONFIG1_A_PATTERN_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_A_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_A_PATTERN_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_A_PATTERN_LENGTH,
           CONFIG1_A_PATTERN_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_A_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_A_PATTERN_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_A_PATTERN_LENGTH,
           CONFIG1_A_PATTERN_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_A_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_TX_PERF_DEGRADED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_TX_PERF_DEGRADED,
           CONFIG1_TX_PERF_DEGRADED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_TX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_TX_PERF_DEGRADED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_TX_PERF_DEGRADED,
           CONFIG1_TX_PERF_DEGRADED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_TX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_TX_PERF_DEGRADED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_TX_PERF_DEGRADED,
           CONFIG1_TX_PERF_DEGRADED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_TX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RX_PERF_DEGRADED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RX_PERF_DEGRADED,
           CONFIG1_RX_PERF_DEGRADED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RX_PERF_DEGRADED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RX_PERF_DEGRADED,
           CONFIG1_RX_PERF_DEGRADED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_RX_PERF_DEGRADED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_RX_PERF_DEGRADED,
           CONFIG1_RX_PERF_DEGRADED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_TX_LANES_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_TX_LANES_DISABLE,
           CONFIG1_TX_LANES_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_TX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_TX_LANES_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_TX_LANES_DISABLE,
           CONFIG1_TX_LANES_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_TX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_TX_LANES_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_TX_LANES_DISABLE,
           CONFIG1_TX_LANES_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_TX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RX_LANES_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RX_LANES_DISABLE,
           CONFIG1_RX_LANES_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RX_LANES_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RX_LANES_DISABLE,
           CONFIG1_RX_LANES_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_RX_LANES_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_RX_LANES_DISABLE,
           CONFIG1_RX_LANES_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_MACRO_DBG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_MACRO_DBG_SEL,
           CONFIG1_MACRO_DBG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_MACRO_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_MACRO_DBG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_MACRO_DBG_SEL,
           CONFIG1_MACRO_DBG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_MACRO_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_MACRO_DBG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_MACRO_DBG_SEL,
           CONFIG1_MACRO_DBG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_MACRO_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_ERR_HLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RESET_ERR_HLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_ERR_HLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RESET_ERR_HLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_ERR_HLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_RESET_ERR_HLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_RESET_ERR_HLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_RESET_ERR_HLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_RESET_ERR_HLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_RESET_ERR_HLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CONFIG1_RESET_ERR_HLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_RESET_ERR_HLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_ERR_CAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RESET_ERR_CAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_ERR_CAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RESET_ERR_CAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_ERR_CAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_RESET_ERR_CAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_RESET_ERR_CAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_RESET_ERR_CAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_RESET_ERR_CAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_RESET_ERR_CAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CONFIG1_RESET_ERR_CAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_RESET_ERR_CAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_TSHD_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RESET_TSHD_REG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_TSHD_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RESET_TSHD_REG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_TSHD_REG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_RESET_TSHD_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_RESET_TSHD_REG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_RESET_TSHD_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_RESET_TSHD_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_RESET_TSHD_REG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CONFIG1_RESET_TSHD_REG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_RESET_TSHD_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_RMT_MSG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RESET_RMT_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_RMT_MSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_RESET_RMT_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_RMT_MSG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_RESET_RMT_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_RESET_RMT_MSG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_RESET_RMT_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_RESET_RMT_MSG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_RESET_RMT_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CONFIG1_RESET_RMT_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_RESET_RMT_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_DIRECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_INJECT_CRC_DIRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_DIRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_INJECT_CRC_DIRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_DIRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_INJECT_CRC_DIRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_INJECT_CRC_DIRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_INJECT_CRC_DIRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_INJECT_CRC_DIRECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_INJECT_CRC_DIRECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CONFIG1_INJECT_CRC_DIRECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_INJECT_CRC_DIRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_INJECT_CRC_RATE,
           CONFIG1_INJECT_CRC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_INJECT_CRC_RATE,
           CONFIG1_INJECT_CRC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_INJECT_CRC_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_INJECT_CRC_RATE,
           CONFIG1_INJECT_CRC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_LANE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_INJECT_CRC_LANE,
           CONFIG1_INJECT_CRC_LANE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_LANE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_LANE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_INJECT_CRC_LANE,
           CONFIG1_INJECT_CRC_LANE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_LANE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_INJECT_CRC_LANE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_INJECT_CRC_LANE,
           CONFIG1_INJECT_CRC_LANE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_LANE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_INJECT_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_INJECT_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_INJECT_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_INJECT_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_INJECT_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_INJECT_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_INJECT_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CONFIG1_INJECT_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_INJECT_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_EDPL_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_EDPL_TIME,
           CONFIG1_EDPL_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_EDPL_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_EDPL_TIME,
           CONFIG1_EDPL_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_EDPL_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_EDPL_TIME,
           CONFIG1_EDPL_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_EDPL_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_EDPL_THRESHOLD,
           CONFIG1_EDPL_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_EDPL_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_EDPL_THRESHOLD,
           CONFIG1_EDPL_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_EDPL_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_EDPL_THRESHOLD,
           CONFIG1_EDPL_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_EDPL_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_EDPL_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_EDPL_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.insertFromRight<CONFIG1_EDPL_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CONFIG1_EDPL_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_EDPL_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_EDPL_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_EDPL_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CONFIG1_EDPL_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.extractToRight<CONFIG1_EDPL_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CONFIG1_EDPL_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_EDPL_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PM_REGS_DLR_APCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PM_REGS_DLR_APCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PM_REGS_DLR_APCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PM_REGS_DLR_APCR;
#endif
    return fapi2::getScom(i_target, PM_REGS_DLR_APCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PM_REGS_DLR_APCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PM_REGS_DLR_APCR));
#endif
    return fapi2::putScom(i_target, PM_REGS_DLR_APCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_CNTL3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_CNTL3_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_CTL_REGS_RX_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_CTL_REGS_RX_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.setBit<RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.clearBit<RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return i_data.getBit<RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.setBit<RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.clearBit<RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_CNTL3_PG));
#endif
    return i_data.getBit<RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_MODE11_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_MODE11_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_CTL_REGS_RX_MODE11_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_CTL_REGS_RX_MODE11_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.setBit<RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.clearBit<RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return i_data.getBit<RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE11_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_MODE21_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_MODE21_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_CTL_REGS_RX_MODE21_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE21_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_CTL_REGS_RX_MODE21_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE21_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE21_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE21_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_MODE5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_MODE5_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_CTL_REGS_RX_MODE5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_CTL_REGS_RX_MODE5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1,
           RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1,
           RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1,
           RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2,
           RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2,
           RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_MODE5_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2,
           RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_FIR1_MASK_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_FIR1_MASK_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_CTL_REGS_RX_FIR1_MASK_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_FIR1_MASK_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_CTL_REGS_RX_FIR1_MASK_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_FIR1_MASK_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_FIR1_MASK_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_FIR1_MASK_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_SPARE_MODE_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_CTL_REGS_RX_SPARE_MODE_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_CTL_REGS_RX_SPARE_MODE_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_CTL_REGS_RX_SPARE_MODE_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_CNT13_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_CNT13_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_REGS_RX_CNT13_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_REGS_RX_CNT13_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.setBit<RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.clearBit<RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.extractToRight<RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.getBit<RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.setBit<RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.clearBit<RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.extractToRight<RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.getBit<RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.setBit<RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.clearBit<RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.extractToRight<RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.getBit<RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_CNT23_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_CNT23_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_REGS_RX_CNT23_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT23_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_REGS_RX_CNT23_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT23_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT23_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT23_PG));
#endif
    return i_data.extractToRight<RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_CNT33_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_CNT33_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_REGS_RX_CNT33_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT33_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_REGS_RX_CNT33_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT33_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT33_PG));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_CNT33_PG));
#endif
    return i_data.extractToRight<RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_STAT18_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_STAT18_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_REGS_RX_STAT18_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_STAT18_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_REGS_RX_STAT18_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_STAT28_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_REGS_RX_STAT28_PG;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_REGS_RX_STAT28_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_REGS_RX_STAT28_PG));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_REGS_RX_STAT28_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_1_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_1_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_1_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_1_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_1_PLREGS_RX_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_1_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_1_PLREGS_RX_STAT1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_1_PLREGS_RX_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_17_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_17_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_17_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_17_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_18_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_18_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_18_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_18_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_18_PLREGS_RX_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_18_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_18_PLREGS_RX_STAT1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_18_PLREGS_RX_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_21_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_21_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_21_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_21_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_2_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA,
           0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA,
           0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA,
           0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE,
           0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE,
           0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE,
           0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
