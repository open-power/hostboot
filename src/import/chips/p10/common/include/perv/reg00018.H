/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00018.H $         */
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

#ifndef __PERV_REG00018_H_
#define __PERV_REG00018_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.setBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.clearBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return i_data.getBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.setBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.clearBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return i_data.getBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL,
           CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL,
           CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL,
           CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL,
           CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL,
           CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL,
           CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE,
           CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE,
           CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE,
           CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE,
           CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE,
           CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE,
           CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS));
#endif
    return o_data.setBit<CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS));
#endif
    return o_data.clearBit<CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS));
#endif
    return i_data.extractToRight<CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS));
#endif
    return i_data.getBit<CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL4_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL4_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL4_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL4_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL4_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL4_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_0_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_1_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_2_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_3_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_4_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_5_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_6_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_7_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_8_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_9_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_10_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_11_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_12_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_13_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_14_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_CLKSTOP_ON_XSTOP_MASK3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_CLKSTOP_ON_XSTOP_MASK3;
#endif
    return fapi2::getScom(i_target, EPS_FIR_CLKSTOP_ON_XSTOP_MASK3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return fapi2::putScom(i_target, EPS_FIR_CLKSTOP_ON_XSTOP_MASK3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK3));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_DTS_RESULT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_DTS_RESULT1;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_DTS_RESULT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_DTS_RESULT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_SKITTER_DATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_SKITTER_DATA2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_SKITTER_DATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_SKITTER_DATA2;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_SKITTER_DATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_SKITTER_DATA2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_SKITTER_DATA2));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_SKITTER_DATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_SKITTER_FORCE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_SKITTER_FORCE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_SKITTER_FORCE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_SKITTER_FORCE_REG;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_SKITTER_FORCE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_SKITTER_FORCE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_SKITTER_FORCE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB2_SKITTER_FORCE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_SKITTER_FORCE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB2_SKITTER_FORCE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_SKITTER_FORCE_REG;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB2_SKITTER_FORCE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB2_SKITTER_FORCE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_SKITTER_FORCE_REG));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB2_SKITTER_FORCE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_SKITTER_FORCE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_SKITTER_FORCE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_SKITTER_FORCE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_SKITTER_FORCE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_SKITTER_FORCE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_SKITTER_FORCE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_ENVSTAT_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_ENVSTAT_RO;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_ENVSTAT_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_ENVSTAT_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER,
           FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER,
           FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE,
                           FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER,
           FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_9_MDA_M1A_DATA_AREA_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_12_MDA_M1B_DATA_AREA_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_3_MDA_M1B_DATA_AREA_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5,
           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5,
           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5,
           FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_M2A_DATA_AREA_5_MDA_M2A_DATA_AREA_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG,
           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG,
           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG,
           FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IGNORE_PAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IGNORE_PAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IGNORE_PAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IGNORE_PAR_REG;
#endif
    return fapi2::getScom(i_target, IGNORE_PAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IGNORE_PAR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return fapi2::putScom(i_target, IGNORE_PAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_IGNORE_PARITY_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_IGNORE_PARITY_REG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_IGNORE_PARITY_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_IGNORE_PARITY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_IGNORE_PARITY_REG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_IGNORE_PARITY_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_IGNORE_PARITY_REG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.setBit<IGNORE_PAR_REG_IGNORE_PARITY_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_IGNORE_PARITY_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IGNORE_PAR_REG_IGNORE_PARITY_REG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.clearBit<IGNORE_PAR_REG_IGNORE_PARITY_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_IGNORE_PARITY_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IGNORE_PAR_REG_IGNORE_PARITY_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.extractToRight<IGNORE_PAR_REG_IGNORE_PARITY_REG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_IGNORE_PARITY_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IGNORE_PAR_REG_IGNORE_PARITY_REG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.getBit<IGNORE_PAR_REG_IGNORE_PARITY_REG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_IGNORE_PARITY_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_DISABLE_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_DISABLE_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_DISABLE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_DISABLE_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_DISABLE_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_DISABLE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_DISABLE_ECC_CORRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.setBit<IGNORE_PAR_REG_DISABLE_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_DISABLE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IGNORE_PAR_REG_DISABLE_ECC_CORRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.clearBit<IGNORE_PAR_REG_DISABLE_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_DISABLE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IGNORE_PAR_REG_DISABLE_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.extractToRight<IGNORE_PAR_REG_DISABLE_ECC_CORRECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_DISABLE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IGNORE_PAR_REG_DISABLE_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.getBit<IGNORE_PAR_REG_DISABLE_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_DISABLE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ECC_S_BIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_ECC_S_BIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ECC_S_BIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ECC_S_BIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_ECC_S_BIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ECC_S_BIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ECC_S_BIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.setBit<IGNORE_PAR_REG_ECC_S_BIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ECC_S_BIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IGNORE_PAR_REG_ECC_S_BIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.clearBit<IGNORE_PAR_REG_ECC_S_BIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ECC_S_BIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IGNORE_PAR_REG_ECC_S_BIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.extractToRight<IGNORE_PAR_REG_ECC_S_BIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ECC_S_BIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IGNORE_PAR_REG_ECC_S_BIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.getBit<IGNORE_PAR_REG_ECC_S_BIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ECC_S_BIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ENABLE_BNDY_LATS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_ENABLE_BNDY_LATS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_BNDY_LATS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ENABLE_BNDY_LATS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_ENABLE_BNDY_LATS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_BNDY_LATS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ENABLE_BNDY_LATS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.setBit<IGNORE_PAR_REG_ENABLE_BNDY_LATS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_BNDY_LATS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IGNORE_PAR_REG_ENABLE_BNDY_LATS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.clearBit<IGNORE_PAR_REG_ENABLE_BNDY_LATS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_BNDY_LATS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IGNORE_PAR_REG_ENABLE_BNDY_LATS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.extractToRight<IGNORE_PAR_REG_ENABLE_BNDY_LATS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_BNDY_LATS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IGNORE_PAR_REG_ENABLE_BNDY_LATS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.getBit<IGNORE_PAR_REG_ENABLE_BNDY_LATS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_BNDY_LATS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ENABLE_EXTENDED_RSP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_ENABLE_EXTENDED_RSP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_EXTENDED_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ENABLE_EXTENDED_RSP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.insertFromRight<IGNORE_PAR_REG_ENABLE_EXTENDED_RSP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_EXTENDED_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IGNORE_PAR_REG_ENABLE_EXTENDED_RSP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.setBit<IGNORE_PAR_REG_ENABLE_EXTENDED_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_EXTENDED_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IGNORE_PAR_REG_ENABLE_EXTENDED_RSP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return o_data.clearBit<IGNORE_PAR_REG_ENABLE_EXTENDED_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_EXTENDED_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IGNORE_PAR_REG_ENABLE_EXTENDED_RSP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.extractToRight<IGNORE_PAR_REG_ENABLE_EXTENDED_RSP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_EXTENDED_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IGNORE_PAR_REG_ENABLE_EXTENDED_RSP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IGNORE_PAR_REG));
#endif
    return i_data.getBit<IGNORE_PAR_REG_ENABLE_EXTENDED_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IGNORE_PAR_REG_ENABLE_EXTENDED_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3TRA0_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA0_TR0_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3TRA0_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA0_TR0_CONFIG_0;
#endif
    return fapi2::getScom(i_target, L3TRA0_TR0_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3TRA0_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3TRA0_TR0_CONFIG_0));
#endif
    return fapi2::putScom(i_target, L3TRA0_TR0_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR0_CONFIG_0));
#endif
    return i_data.extractToRight<L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3TRA0_TR1_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA0_TR1_CONFIG_9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3TRA0_TR1_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA0_TR1_CONFIG_9;
#endif
    return fapi2::getScom(i_target, L3TRA0_TR1_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3TRA0_TR1_CONFIG_9(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return fapi2::putScom(i_target, L3TRA0_TR1_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL,
           L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK,
           L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE,
           L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE,
           L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE,
           L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_SPARE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.setBit<L3TRA0_TR1_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3TRA0_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L3TRA0_TR1_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_9_SPARE_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3TRA0_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_9));
#endif
    return i_data.getBit<L3TRA0_TR1_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA0_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3TRA2_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA2_TR1_CONFIG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3TRA2_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA2_TR1_CONFIG_1;
#endif
    return fapi2::getScom(i_target, L3TRA2_TR1_CONFIG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3TRA2_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3TRA2_TR1_CONFIG_1));
#endif
    return fapi2::putScom(i_target, L3TRA2_TR1_CONFIG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR1_CONFIG_1));
#endif
    return o_data.insertFromRight<L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR1_CONFIG_1));
#endif
    return o_data.insertFromRight<L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR1_CONFIG_1));
#endif
    return i_data.extractToRight<L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MULTICAST_GROUP_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MULTICAST_GROUP_2;
#endif
    return fapi2::getScom(i_target, MULTICAST_GROUP_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_2));
#endif
    return fapi2::putScom(i_target, MULTICAST_GROUP_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MULTICAST_GROUP_2_MULTICAST2_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<MULTICAST_GROUP_2_MULTICAST2_GROUP,
           MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MULTICAST_GROUP_2_MULTICAST2_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<MULTICAST_GROUP_2_MULTICAST2_GROUP,
           MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MULTICAST_GROUP_2_MULTICAST2_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_2));
#endif
    return i_data.extractToRight<MULTICAST_GROUP_2_MULTICAST2_GROUP,
           MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTPC_M_DATA_REGISTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_DATA_REGISTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTPC_M_DATA_REGISTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_DATA_REGISTER;
#endif
    return fapi2::getScom(i_target, OTPC_M_DATA_REGISTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTPC_M_DATA_REGISTER(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OTPC_M_DATA_REGISTER));
#endif
    return fapi2::putScom(i_target, OTPC_M_DATA_REGISTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_DATA_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER,
           OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_DATA_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER,
           OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_DATA_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER,
           OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTPC_M_MEASURE_REG12(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_MEASURE_REG12;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTPC_M_MEASURE_REG12(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_MEASURE_REG12;
#endif
    return fapi2::getScom(i_target, OTPC_M_MEASURE_REG12, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTPC_M_MEASURE_REG12(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG12));
#endif
    return fapi2::putScom(i_target, OTPC_M_MEASURE_REG12, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG12));
#endif
    return o_data.insertFromRight<OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA,
           OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG12));
#endif
    return o_data.insertFromRight<OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA,
           OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG12));
#endif
    return i_data.extractToRight<OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA,
           OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTPC_M_MEASURE_REG9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_MEASURE_REG9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTPC_M_MEASURE_REG9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_MEASURE_REG9;
#endif
    return fapi2::getScom(i_target, OTPC_M_MEASURE_REG9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTPC_M_MEASURE_REG9(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG9));
#endif
    return fapi2::putScom(i_target, OTPC_M_MEASURE_REG9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG9));
#endif
    return o_data.insertFromRight<OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA,
           OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG9));
#endif
    return o_data.insertFromRight<OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA,
           OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG9));
#endif
    return i_data.extractToRight<OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA,
           OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QMETRA0_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QMETRA0_TR0_CONFIG_9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QMETRA0_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QMETRA0_TR0_CONFIG_9;
#endif
    return fapi2::getScom(i_target, QMETRA0_TR0_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QMETRA0_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return fapi2::putScom(i_target, QMETRA0_TR0_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL,
           QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK,
           QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE,
           QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE,
           QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE,
           QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_SPARE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.setBit<QMETRA0_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QMETRA0_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return o_data.clearBit<QMETRA0_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_9_SPARE_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QMETRA0_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_9));
#endif
    return i_data.getBit<QMETRA0_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QMETRA0_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QMETRA0_TR1_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QMETRA0_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QMETRA0_TR1_CONFIG_0;
#endif
    return fapi2::getScom(i_target, QMETRA0_TR1_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QMETRA0_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QMETRA0_TR1_CONFIG_0));
#endif
    return fapi2::putScom(i_target, QMETRA0_TR1_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR1_CONFIG_0));
#endif
    return o_data.insertFromRight<QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR1_CONFIG_0));
#endif
    return o_data.insertFromRight<QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR1_CONFIG_0));
#endif
    return i_data.extractToRight<QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_MST3_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST3_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_MST3_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST3_REG1;
#endif
    return fapi2::getScom(i_target, REC_ERR_MST3_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_MST3_REG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return fapi2::putScom(i_target, REC_ERR_MST3_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_16_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_16_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_16_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_16_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_16_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_16_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_16_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_16_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_16_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_16_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_17_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_17_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_17_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_17_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_17_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_17_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_17_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_17_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_17_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_17_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_18_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_18_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_18_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_18_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_18_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_18_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_18_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_18_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_18_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_18_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_19_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_19_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_19_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_19_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_19_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_19_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_19_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_19_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_19_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_19_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_20_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_20_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_20_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_20_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_20_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_20_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_20_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_20_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_20_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_20_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_21_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_21_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_21_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_21_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_21_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_21_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_21_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_21_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_21_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_21_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_22_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_22_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_22_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_22_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_22_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_22_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_22_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_22_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_22_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_22_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_23_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_23_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_23_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_23_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_23_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_23_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_23_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_23_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_23_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_23_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_24_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_24_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_24_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_24_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_24_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_24_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_24_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_24_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_24_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_24_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_25_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_25_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_25_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_25_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_25_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_25_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_25_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_25_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_25_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_25_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_26_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_26_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_26_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_26_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_26_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_26_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_26_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_26_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_26_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_26_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_27_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_27_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_27_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_27_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_27_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_27_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_27_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_27_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_27_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_27_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_28_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_28_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_28_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_28_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_28_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_28_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_28_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_28_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_28_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_28_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_29_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_29_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_29_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_29_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_29_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_29_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_29_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_29_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_29_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_29_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_30_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_30_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_30_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_30_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_30_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_30_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_30_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_30_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_30_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_30_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.setBit<REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.getBit<REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_31_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_31_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_31_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST3_REG1_31_MST3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST3_REG1_31_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_31_MST3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST3_REG1_31_MST3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST3_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST3_REG1_31_MST3_ERROR_CODE,
           REC_ERR_MST3_REG1_31_MST3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST3_REG1_31_MST3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_MST7_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST7_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_MST7_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST7_REG0;
#endif
    return fapi2::getScom(i_target, REC_ERR_MST7_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_MST7_REG0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return fapi2::putScom(i_target, REC_ERR_MST7_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.setBit<REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.getBit<REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST7_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE,
           REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_MST9_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST9_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_MST9_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST9_REG0;
#endif
    return fapi2::getScom(i_target, REC_ERR_MST9_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_MST9_REG0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return fapi2::putScom(i_target, REC_ERR_MST9_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.setBit<REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.getBit<REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST9_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE,
           REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG114(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG114;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG114(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG114;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG114, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG114(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG114));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG114, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG114));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114,
           SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG114));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114,
           SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG114));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114,
           SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG123(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG123;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG123(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG123;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG123, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG123(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG123));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG123, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG123));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123,
           SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG123));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123,
           SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG123));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123,
           SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG32(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG32;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG32(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG32;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG32, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG32(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG32));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG32, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG32));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32,
           SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG32));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32,
           SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG32));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32,
           SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG53(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG53;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG53(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG53;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG53, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG53(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG53));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG53, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG53));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53,
           SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG53));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53,
           SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG53));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53,
           SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG64(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG64;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG64(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG64;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG64, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG64(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG64));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG64, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG64));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64,
           SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG64));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64,
           SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG64));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64,
           SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG91(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG91;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG91(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG91;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG91, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG91(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG91));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG91, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG91));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91,
           SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG91));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91,
           SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG91));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91,
           SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_TRACE_DATA_1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TRACE_DATA_1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_TRACE_DATA_1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TRACE_DATA_1_REG;
#endif
    return fapi2::getScom(i_target, TOD_TRACE_DATA_1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_TRACE_DATA_1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_1_REG));
#endif
    return fapi2::putScom(i_target, TOD_TRACE_DATA_1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_1_REG));
#endif
    return o_data.insertFromRight<TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1,
           TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_1_REG));
#endif
    return o_data.insertFromRight<TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1,
           TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_1_REG));
#endif
    return i_data.extractToRight<TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1,
           TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_TRACE_DATA_2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TRACE_DATA_2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_TRACE_DATA_2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TRACE_DATA_2_REG;
#endif
    return fapi2::getScom(i_target, TOD_TRACE_DATA_2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_TRACE_DATA_2_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_2_REG));
#endif
    return fapi2::putScom(i_target, TOD_TRACE_DATA_2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_2_REG));
#endif
    return o_data.insertFromRight<TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2,
           TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_2_REG));
#endif
    return o_data.insertFromRight<TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2,
           TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_2_REG));
#endif
    return i_data.extractToRight<TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2,
           TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_TRACE_DATA_3_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TRACE_DATA_3_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_TRACE_DATA_3_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TRACE_DATA_3_REG;
#endif
    return fapi2::getScom(i_target, TOD_TRACE_DATA_3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_TRACE_DATA_3_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_3_REG));
#endif
    return fapi2::putScom(i_target, TOD_TRACE_DATA_3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_3_REG));
#endif
    return o_data.insertFromRight<TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3,
           TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_3_REG));
#endif
    return o_data.insertFromRight<TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3,
           TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TRACE_DATA_3_REG));
#endif
    return i_data.extractToRight<TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3,
           TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_CONFIG_0;
#endif
    return fapi2::getScom(i_target, TRA0_TR0_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_0));
#endif
    return fapi2::putScom(i_target, TRA0_TR0_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_0));
#endif
    return i_data.extractToRight<TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
