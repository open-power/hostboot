/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00014.H $         */
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

#ifndef __NMMU_REG00014_H_
#define __NMMU_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_DBG_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_DBG_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_DBG_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_DBG_MODE;
#endif
    return fapi2::getScom(i_target, NMMU_DBG_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_DBG_MODE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return fapi2::putScom(i_target, NMMU_DBG_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_PRV_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_SLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS0_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.setBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.clearBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.getBit<NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TLB_BUS1_STG1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_RESERVED_27_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_RESERVED_27_31,
           NMMU_DBG_MODE_RESERVED_27_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_RESERVED_27_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_RESERVED_27_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_RESERVED_27_31,
           NMMU_DBG_MODE_RESERVED_27_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_RESERVED_27_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_RESERVED_27_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_RESERVED_27_31,
           NMMU_DBG_MODE_RESERVED_27_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_RESERVED_27_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_FBC_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_MSC_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_TW_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return o_data.insertFromRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_DBG_MODE));
#endif
    return i_data.extractToRight<NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL,
           NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_DBG_MODE_MM_DBG_MODE_RDX_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_FLT_STAT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_FLT_STAT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_FLT_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_FLT_STAT_REG;
#endif
    return fapi2::getScom(i_target, NMMU_FLT_STAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_FLT_STAT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_FLT_STAT_REG));
#endif
    return fapi2::putScom(i_target, NMMU_FLT_STAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NMMU_FLT_STAT_REG_MM_FLT_STAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_FLT_STAT_REG));
#endif
    return o_data.insertFromRight<NMMU_FLT_STAT_REG_MM_FLT_STAT,
           NMMU_FLT_STAT_REG_MM_FLT_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_FLT_STAT_REG_MM_FLT_STAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_FLT_STAT_REG_MM_FLT_STAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_FLT_STAT_REG));
#endif
    return o_data.insertFromRight<NMMU_FLT_STAT_REG_MM_FLT_STAT,
           NMMU_FLT_STAT_REG_MM_FLT_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_FLT_STAT_REG_MM_FLT_STAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_FLT_STAT_REG_MM_FLT_STAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_FLT_STAT_REG));
#endif
    return i_data.extractToRight<NMMU_FLT_STAT_REG_MM_FLT_STAT,
           NMMU_FLT_STAT_REG_MM_FLT_STAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_FLT_STAT_REG_MM_FLT_STAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_PMU1_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_PMU1_CTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_PMU1_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_PMU1_CTL_REG;
#endif
    return fapi2::getScom(i_target, NMMU_PMU1_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_PMU1_CTL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_PMU1_CTL_REG));
#endif
    return fapi2::putScom(i_target, NMMU_PMU1_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NMMU_PMU1_CTL_REG_MM_PMU1_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU1_CTL_REG));
#endif
    return o_data.insertFromRight<NMMU_PMU1_CTL_REG_MM_PMU1_CTL,
           NMMU_PMU1_CTL_REG_MM_PMU1_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU1_CTL_REG_MM_PMU1_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_PMU1_CTL_REG_MM_PMU1_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU1_CTL_REG));
#endif
    return o_data.insertFromRight<NMMU_PMU1_CTL_REG_MM_PMU1_CTL,
           NMMU_PMU1_CTL_REG_MM_PMU1_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU1_CTL_REG_MM_PMU1_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_PMU1_CTL_REG_MM_PMU1_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU1_CTL_REG));
#endif
    return i_data.extractToRight<NMMU_PMU1_CTL_REG_MM_PMU1_CTL,
           NMMU_PMU1_CTL_REG_MM_PMU1_CTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU1_CTL_REG_MM_PMU1_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
