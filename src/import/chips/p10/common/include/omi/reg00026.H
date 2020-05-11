/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00026.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __OMI_REG00026_H_
#define __OMI_REG00026_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[CONFIG1]
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
//<< PREP_[CONFIG1]

//>> GET_[CONFIG1]
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
//<< GET_[CONFIG1]

//>> PUT_[CONFIG1]
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
//<< PUT_[CONFIG1]


//>> SET_[CONFIG1_CFG1_SPARE]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_CFG1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_CFG1_SPARE]

//>> SET_[CONFIG1_CFG1_SPARE]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_CFG1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_CFG1_SPARE]

//>> GET_[CONFIG1_CFG1_SPARE]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_CFG1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_CFG1_SPARE]

//>> SET_[CONFIG1_LANE_WIDTH]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_LANE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_LANE_WIDTH]

//>> SET_[CONFIG1_LANE_WIDTH]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_LANE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_LANE_WIDTH]

//>> GET_[CONFIG1_LANE_WIDTH]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_LANE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_LANE_WIDTH]

//>> SET_[CONFIG1_PREIPL_PRBS_ENA]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_PREIPL_PRBS_ENA]

//>> SET_[CONFIG1_PREIPL_PRBS_ENA]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_PREIPL_PRBS_ENA]

//>> SET_[CONFIG1_PREIPL_PRBS_ENA]
static inline fapi2::buffer<uint64_t>& SET_CONFIG1_PREIPL_PRBS_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_PREIPL_PRBS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_PREIPL_PRBS_ENA]

//>> CLEAR_[CONFIG1_PREIPL_PRBS_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_PREIPL_PRBS_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_PREIPL_PRBS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG1_PREIPL_PRBS_ENA]

//>> GET_[CONFIG1_PREIPL_PRBS_ENA]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_PREIPL_PRBS_ENA]

//>> GET_[CONFIG1_PREIPL_PRBS_ENA]
static inline bool GET_CONFIG1_PREIPL_PRBS_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_PREIPL_PRBS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_PREIPL_PRBS_ENA]

//>> SET_[CONFIG1_PREIPL_PRBS_TIME]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_PREIPL_PRBS_TIME]

//>> SET_[CONFIG1_PREIPL_PRBS_TIME]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_PREIPL_PRBS_TIME]

//>> GET_[CONFIG1_PREIPL_PRBS_TIME]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_PREIPL_PRBS_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_PREIPL_PRBS_TIME]

//>> SET_[CONFIG1_B_HYSTERESIS]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_B_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_B_HYSTERESIS]

//>> SET_[CONFIG1_B_HYSTERESIS]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_B_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_B_HYSTERESIS]

//>> GET_[CONFIG1_B_HYSTERESIS]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_B_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_B_HYSTERESIS]

//>> SET_[CONFIG1_A_HYSTERESIS]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_A_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_A_HYSTERESIS]

//>> SET_[CONFIG1_A_HYSTERESIS]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_A_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_A_HYSTERESIS]

//>> GET_[CONFIG1_A_HYSTERESIS]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_A_HYSTERESIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_A_HYSTERESIS]

//>> SET_[CONFIG1_B_PATTERN_LENGTH]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_B_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_B_PATTERN_LENGTH]

//>> SET_[CONFIG1_B_PATTERN_LENGTH]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_B_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_B_PATTERN_LENGTH]

//>> GET_[CONFIG1_B_PATTERN_LENGTH]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_B_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_B_PATTERN_LENGTH]

//>> SET_[CONFIG1_A_PATTERN_LENGTH]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_A_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_A_PATTERN_LENGTH]

//>> SET_[CONFIG1_A_PATTERN_LENGTH]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_A_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_A_PATTERN_LENGTH]

//>> GET_[CONFIG1_A_PATTERN_LENGTH]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_A_PATTERN_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_A_PATTERN_LENGTH]

//>> SET_[CONFIG1_TX_PERF_DEGRADED]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_TX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_TX_PERF_DEGRADED]

//>> SET_[CONFIG1_TX_PERF_DEGRADED]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_TX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_TX_PERF_DEGRADED]

//>> GET_[CONFIG1_TX_PERF_DEGRADED]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_TX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_TX_PERF_DEGRADED]

//>> SET_[CONFIG1_RX_PERF_DEGRADED]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_RX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RX_PERF_DEGRADED]

//>> SET_[CONFIG1_RX_PERF_DEGRADED]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_RX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RX_PERF_DEGRADED]

//>> GET_[CONFIG1_RX_PERF_DEGRADED]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_RX_PERF_DEGRADED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RX_PERF_DEGRADED]

//>> SET_[CONFIG1_TX_LANES_DISABLE]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_TX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_TX_LANES_DISABLE]

//>> SET_[CONFIG1_TX_LANES_DISABLE]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_TX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_TX_LANES_DISABLE]

//>> GET_[CONFIG1_TX_LANES_DISABLE]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_TX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_TX_LANES_DISABLE]

//>> SET_[CONFIG1_RX_LANES_DISABLE]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_RX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RX_LANES_DISABLE]

//>> SET_[CONFIG1_RX_LANES_DISABLE]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_RX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RX_LANES_DISABLE]

//>> GET_[CONFIG1_RX_LANES_DISABLE]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_RX_LANES_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RX_LANES_DISABLE]

//>> SET_[CONFIG1_MACRO_DBG_SEL]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_MACRO_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_MACRO_DBG_SEL]

//>> SET_[CONFIG1_MACRO_DBG_SEL]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_MACRO_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_MACRO_DBG_SEL]

//>> GET_[CONFIG1_MACRO_DBG_SEL]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_MACRO_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_MACRO_DBG_SEL]

//>> SET_[CONFIG1_RESET_ERR_HLD]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_ERR_HLD]

//>> SET_[CONFIG1_RESET_ERR_HLD]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_ERR_HLD]

//>> SET_[CONFIG1_RESET_ERR_HLD]
static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_ERR_HLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_RESET_ERR_HLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_ERR_HLD]

//>> CLEAR_[CONFIG1_RESET_ERR_HLD]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_RESET_ERR_HLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_RESET_ERR_HLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG1_RESET_ERR_HLD]

//>> GET_[CONFIG1_RESET_ERR_HLD]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RESET_ERR_HLD]

//>> GET_[CONFIG1_RESET_ERR_HLD]
static inline bool GET_CONFIG1_RESET_ERR_HLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_RESET_ERR_HLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG1_RESET_ERR_HLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RESET_ERR_HLD]

//>> SET_[CONFIG1_RESET_ERR_CAP]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_ERR_CAP]

//>> SET_[CONFIG1_RESET_ERR_CAP]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_ERR_CAP]

//>> SET_[CONFIG1_RESET_ERR_CAP]
static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_ERR_CAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_RESET_ERR_CAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_ERR_CAP]

//>> CLEAR_[CONFIG1_RESET_ERR_CAP]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_RESET_ERR_CAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_RESET_ERR_CAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG1_RESET_ERR_CAP]

//>> GET_[CONFIG1_RESET_ERR_CAP]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RESET_ERR_CAP]

//>> GET_[CONFIG1_RESET_ERR_CAP]
static inline bool GET_CONFIG1_RESET_ERR_CAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_RESET_ERR_CAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG1_RESET_ERR_CAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RESET_ERR_CAP]

//>> SET_[CONFIG1_RESET_TSHD_REG]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_TSHD_REG]

//>> SET_[CONFIG1_RESET_TSHD_REG]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_TSHD_REG]

//>> SET_[CONFIG1_RESET_TSHD_REG]
static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_TSHD_REG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_RESET_TSHD_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_TSHD_REG]

//>> CLEAR_[CONFIG1_RESET_TSHD_REG]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_RESET_TSHD_REG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_RESET_TSHD_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG1_RESET_TSHD_REG]

//>> GET_[CONFIG1_RESET_TSHD_REG]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RESET_TSHD_REG]

//>> GET_[CONFIG1_RESET_TSHD_REG]
static inline bool GET_CONFIG1_RESET_TSHD_REG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_RESET_TSHD_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG1_RESET_TSHD_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RESET_TSHD_REG]

//>> SET_[CONFIG1_RESET_RMT_MSG]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_RMT_MSG]

//>> SET_[CONFIG1_RESET_RMT_MSG]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_RMT_MSG]

//>> SET_[CONFIG1_RESET_RMT_MSG]
static inline fapi2::buffer<uint64_t>& SET_CONFIG1_RESET_RMT_MSG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_RESET_RMT_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_RESET_RMT_MSG]

//>> CLEAR_[CONFIG1_RESET_RMT_MSG]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_RESET_RMT_MSG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_RESET_RMT_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG1_RESET_RMT_MSG]

//>> GET_[CONFIG1_RESET_RMT_MSG]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RESET_RMT_MSG]

//>> GET_[CONFIG1_RESET_RMT_MSG]
static inline bool GET_CONFIG1_RESET_RMT_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_RESET_RMT_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG1_RESET_RMT_MSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_RESET_RMT_MSG]

//>> SET_[CONFIG1_INJECT_CRC_DIRECTION]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_DIRECTION]

//>> SET_[CONFIG1_INJECT_CRC_DIRECTION]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_DIRECTION]

//>> SET_[CONFIG1_INJECT_CRC_DIRECTION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_DIRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_INJECT_CRC_DIRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_DIRECTION]

//>> CLEAR_[CONFIG1_INJECT_CRC_DIRECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_INJECT_CRC_DIRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_INJECT_CRC_DIRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG1_INJECT_CRC_DIRECTION]

//>> GET_[CONFIG1_INJECT_CRC_DIRECTION]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_INJECT_CRC_DIRECTION]

//>> GET_[CONFIG1_INJECT_CRC_DIRECTION]
static inline bool GET_CONFIG1_INJECT_CRC_DIRECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_INJECT_CRC_DIRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG1_INJECT_CRC_DIRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_INJECT_CRC_DIRECTION]

//>> SET_[CONFIG1_INJECT_CRC_RATE]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_INJECT_CRC_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_RATE]

//>> SET_[CONFIG1_INJECT_CRC_RATE]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_INJECT_CRC_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_RATE]

//>> GET_[CONFIG1_INJECT_CRC_RATE]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_INJECT_CRC_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_INJECT_CRC_RATE]

//>> SET_[CONFIG1_INJECT_CRC_LANE]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_INJECT_CRC_LANE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_LANE]

//>> SET_[CONFIG1_INJECT_CRC_LANE]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_INJECT_CRC_LANE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_LANE]

//>> GET_[CONFIG1_INJECT_CRC_LANE]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_INJECT_CRC_LANE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_INJECT_CRC_LANE]

//>> SET_[CONFIG1_INJECT_CRC_ERROR]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_ERROR]

//>> SET_[CONFIG1_INJECT_CRC_ERROR]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_ERROR]

//>> SET_[CONFIG1_INJECT_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_CONFIG1_INJECT_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_INJECT_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_INJECT_CRC_ERROR]

//>> CLEAR_[CONFIG1_INJECT_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_INJECT_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_INJECT_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG1_INJECT_CRC_ERROR]

//>> GET_[CONFIG1_INJECT_CRC_ERROR]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_INJECT_CRC_ERROR]

//>> GET_[CONFIG1_INJECT_CRC_ERROR]
static inline bool GET_CONFIG1_INJECT_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_INJECT_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG1_INJECT_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_INJECT_CRC_ERROR]

//>> SET_[CONFIG1_EDPL_TIME]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_EDPL_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_EDPL_TIME]

//>> SET_[CONFIG1_EDPL_TIME]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_EDPL_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_EDPL_TIME]

//>> GET_[CONFIG1_EDPL_TIME]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_EDPL_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_EDPL_TIME]

//>> SET_[CONFIG1_EDPL_THRESHOLD]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_EDPL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_EDPL_THRESHOLD]

//>> SET_[CONFIG1_EDPL_THRESHOLD]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_EDPL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_EDPL_THRESHOLD]

//>> GET_[CONFIG1_EDPL_THRESHOLD]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_EDPL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_EDPL_THRESHOLD]

//>> SET_[CONFIG1_EDPL_ENA]
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
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_EDPL_ENA]

//>> SET_[CONFIG1_EDPL_ENA]
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
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_EDPL_ENA]

//>> SET_[CONFIG1_EDPL_ENA]
static inline fapi2::buffer<uint64_t>& SET_CONFIG1_EDPL_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.setBit<CONFIG1_EDPL_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG1_EDPL_ENA]

//>> CLEAR_[CONFIG1_EDPL_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG1_EDPL_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return o_data.clearBit<CONFIG1_EDPL_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG1_EDPL_ENA]

//>> GET_[CONFIG1_EDPL_ENA]
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
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_EDPL_ENA]

//>> GET_[CONFIG1_EDPL_ENA]
static inline bool GET_CONFIG1_EDPL_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG1));
#endif
    return i_data.getBit<CONFIG1_EDPL_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG1_EDPL_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG1_EDPL_ENA]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
