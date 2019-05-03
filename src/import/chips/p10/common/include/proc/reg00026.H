/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00026.H $         */
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

#ifndef __PROC_REG00026_H_
#define __PROC_REG00026_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_ACTION1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_ACTION1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_ACTION1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_ACTION1;
#endif
    return fapi2::getScom(i_target, INT_CQ_ACTION1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_ACTION1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_ACTION1));
#endif
    return fapi2::putScom(i_target, INT_CQ_ACTION1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ACTION1_INT_CQ_ACTION1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ACTION1));
#endif
    return o_data.insertFromRight<INT_CQ_ACTION1_INT_CQ_ACTION1,
           INT_CQ_ACTION1_INT_CQ_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ACTION1_INT_CQ_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ACTION1_INT_CQ_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ACTION1));
#endif
    return o_data.insertFromRight<INT_CQ_ACTION1_INT_CQ_ACTION1,
           INT_CQ_ACTION1_INT_CQ_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ACTION1_INT_CQ_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ACTION1_INT_CQ_ACTION1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ACTION1));
#endif
    return i_data.extractToRight<INT_CQ_ACTION1_INT_CQ_ACTION1,
           INT_CQ_ACTION1_INT_CQ_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ACTION1_INT_CQ_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_CFG_LDQ2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_CFG_LDQ2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_CFG_LDQ2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_CFG_LDQ2;
#endif
    return fapi2::getScom(i_target, INT_CQ_CFG_LDQ2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_CFG_LDQ2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_LDQ2));
#endif
    return fapi2::putScom(i_target, INT_CQ_CFG_LDQ2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_LDQ2_IN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_LDQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_LDQ2_IN_0_2,
           INT_CQ_CFG_LDQ2_IN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_LDQ2_IN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_LDQ2_IN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_LDQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_LDQ2_IN_0_2,
           INT_CQ_CFG_LDQ2_IN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_LDQ2_IN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_LDQ2_IN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_LDQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_LDQ2_IN_0_2,
           INT_CQ_CFG_LDQ2_IN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_LDQ2_IN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_LDQ2_AX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_LDQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_LDQ2_AX_0_4,
           INT_CQ_CFG_LDQ2_AX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_LDQ2_AX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_LDQ2_AX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_LDQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_LDQ2_AX_0_4,
           INT_CQ_CFG_LDQ2_AX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_LDQ2_AX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_LDQ2_AX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_LDQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_LDQ2_AX_0_4,
           INT_CQ_CFG_LDQ2_AX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_LDQ2_AX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_ERR_INFO3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_ERR_INFO3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_ERR_INFO3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_ERR_INFO3;
#endif
    return fapi2::getScom(i_target, INT_CQ_ERR_INFO3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_ERR_INFO3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return fapi2::putScom(i_target, INT_CQ_ERR_INFO3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INFO_CAPTURED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_INFO_CAPTURED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INFO_CAPTURED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INFO_CAPTURED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_INFO_CAPTURED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INFO_CAPTURED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INFO_CAPTURED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_INFO_CAPTURED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INFO_CAPTURED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_INFO_CAPTURED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_INFO_CAPTURED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INFO_CAPTURED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_INFO_CAPTURED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_INFO_CAPTURED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INFO_CAPTURED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_INFO_CAPTURED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_INFO_CAPTURED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INFO_CAPTURED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_STQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_STQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_STQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_STQ_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_STQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_STQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_STQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_STQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_STQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_STQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_STQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_STQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_STQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_STQ_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_STQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_STQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_STQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_STQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_LDQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_LDQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_LDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_LDQ_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_LDQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_LDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_LDQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_LDQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_LDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_LDQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_LDQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_LDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_LDQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_LDQ_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_LDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_LDQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_LDQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_LDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_WRQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_WRQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_WRQ_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_WRQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_WRQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_WRQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_WRQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_WRQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_WRQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_WRQ_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_WRQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_WRQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_RDQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_RDQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_RDQ_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_RDQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_RDQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_RDQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_RDQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_RDQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_RDQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_RDQ_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_RDQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_RDQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INTQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_INTQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INTQ_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_INTQ_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INTQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_INTQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_INTQ_FSM_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_INTQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_INTQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_INTQ_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_INTQ_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_INTQ_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_WRQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_WRQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_WRQ_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_WRQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_WRQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_WRQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_WRQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_WRQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_WRQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_WRQ_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_WRQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_WRQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_WRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_RDQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_RDQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_RDQ_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_RDQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_RDQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_RDQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_RDQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_RDQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_RDQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_RDQ_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_RDQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_RDQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_RDQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INTQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_INTQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INTQ_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.insertFromRight<INT_CQ_ERR_INFO3_INTQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_ERR_INFO3_INTQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.setBit<INT_CQ_ERR_INFO3_INTQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_ERR_INFO3_INTQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return o_data.clearBit<INT_CQ_ERR_INFO3_INTQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_ERR_INFO3_INTQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.extractToRight<INT_CQ_ERR_INFO3_INTQ_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_ERR_INFO3_INTQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_ERR_INFO3));
#endif
    return i_data.getBit<INT_CQ_ERR_INFO3_INTQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_ERR_INFO3_INTQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_MC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_MC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_MC(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_MC;
#endif
    return fapi2::getScom(i_target, INT_CQ_MC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_MC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return fapi2::putScom(i_target, INT_CQ_MC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MC_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return o_data.insertFromRight<INT_CQ_MC_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MC_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return o_data.insertFromRight<INT_CQ_MC_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MC_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return o_data.setBit<INT_CQ_MC_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_MC_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return o_data.clearBit<INT_CQ_MC_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_MC_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return i_data.extractToRight<INT_CQ_MC_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_MC_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return i_data.getBit<INT_CQ_MC_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MC_BLOCK_ID_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return o_data.insertFromRight<INT_CQ_MC_BLOCK_ID_0_3,
           INT_CQ_MC_BLOCK_ID_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_BLOCK_ID_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MC_BLOCK_ID_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return o_data.insertFromRight<INT_CQ_MC_BLOCK_ID_0_3,
           INT_CQ_MC_BLOCK_ID_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_BLOCK_ID_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_MC_BLOCK_ID_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return i_data.extractToRight<INT_CQ_MC_BLOCK_ID_0_3,
           INT_CQ_MC_BLOCK_ID_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_BLOCK_ID_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MC_ESB_OFFSET_0_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return o_data.insertFromRight<INT_CQ_MC_ESB_OFFSET_0_25,
           INT_CQ_MC_ESB_OFFSET_0_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_ESB_OFFSET_0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MC_ESB_OFFSET_0_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return o_data.insertFromRight<INT_CQ_MC_ESB_OFFSET_0_25,
           INT_CQ_MC_ESB_OFFSET_0_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_ESB_OFFSET_0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_MC_ESB_OFFSET_0_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MC));
#endif
    return i_data.extractToRight<INT_CQ_MC_ESB_OFFSET_0_25,
           INT_CQ_MC_ESB_OFFSET_0_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MC_ESB_OFFSET_0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_MSGSND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_MSGSND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_MSGSND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_MSGSND;
#endif
    return fapi2::getScom(i_target, INT_CQ_MSGSND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_MSGSND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_MSGSND));
#endif
    return fapi2::putScom(i_target, INT_CQ_MSGSND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MSGSND));
#endif
    return o_data.insertFromRight<INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31,
           INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MSGSND));
#endif
    return o_data.insertFromRight<INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31,
           INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_MSGSND));
#endif
    return i_data.extractToRight<INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31,
           INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_DEBUG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_DEBUG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_DEBUG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_DEBUG;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_DEBUG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_DEBUG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_DEBUG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_PMC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_PMC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_PMC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_PMC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_PMC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_PMC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_PMC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_DEBUG_PMC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_PMC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_DEBUG_PMC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_DEBUG_PMC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_PMC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_PMC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_PMC_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_PMC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_DEBUG_PMC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_DEBUG_PMC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_PMC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_2_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_2_10,
           INT_PC_NXC_REGS_DEBUG_RESERVED_2_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_2_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_2_10,
           INT_PC_NXC_REGS_DEBUG_RESERVED_2_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_RESERVED_2_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_RESERVED_2_10,
           INT_PC_NXC_REGS_DEBUG_RESERVED_2_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_12_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_12_15,
           INT_PC_NXC_REGS_DEBUG_RESERVED_12_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_12_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_12_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_12_15,
           INT_PC_NXC_REGS_DEBUG_RESERVED_12_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_12_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_RESERVED_12_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_RESERVED_12_15,
           INT_PC_NXC_REGS_DEBUG_RESERVED_12_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_12_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_28_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_28_29,
           INT_PC_NXC_REGS_DEBUG_RESERVED_28_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_28_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_28_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_28_29,
           INT_PC_NXC_REGS_DEBUG_RESERVED_28_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_28_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_RESERVED_28_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_RESERVED_28_29,
           INT_PC_NXC_REGS_DEBUG_RESERVED_28_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_28_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_32_33,
           INT_PC_NXC_REGS_DEBUG_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_32_33,
           INT_PC_NXC_REGS_DEBUG_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_RESERVED_32_33,
           INT_PC_NXC_REGS_DEBUG_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_DEBUG_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_DEBUG_RESERVED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_DEBUG_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_RESERVED_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_RESERVED_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_DEBUG_RESERVED_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_DEBUG_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION,
           INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_44_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_44_45,
           INT_PC_NXC_REGS_DEBUG_RESERVED_44_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_44_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_44_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_44_45,
           INT_PC_NXC_REGS_DEBUG_RESERVED_44_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_44_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_RESERVED_44_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_RESERVED_44_45,
           INT_PC_NXC_REGS_DEBUG_RESERVED_44_45_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_44_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL,
           INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL,
           INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL,
           INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL,
           INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL,
           INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL,
           INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_58_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_58_63,
           INT_PC_NXC_REGS_DEBUG_RESERVED_58_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_58_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_DEBUG_RESERVED_58_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_DEBUG_RESERVED_58_63,
           INT_PC_NXC_REGS_DEBUG_RESERVED_58_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_58_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_DEBUG_RESERVED_58_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_DEBUG));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_DEBUG_RESERVED_58_63,
           INT_PC_NXC_REGS_DEBUG_RESERVED_58_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_DEBUG_RESERVED_58_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH1_DATA0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WATCH1_DATA0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH1_DATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WATCH1_DATA0;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH1_DATA0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH1_DATA0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WATCH1_DATA0));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH1_DATA0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH2_SPEC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WATCH2_SPEC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH2_SPEC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WATCH2_SPEC;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH2_SPEC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH2_SPEC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WATCH2_SPEC));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH2_SPEC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_ERR0_CFG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_ERR0_CFG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_ERR0_CFG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_ERR0_CFG0;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_ERR0_CFG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_ERR0_CFG0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_CFG0));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_ERR0_CFG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_CFG0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0,
           INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_CFG0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0,
           INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_CFG0));
#endif
    return i_data.extractToRight<INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0,
           INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_ERR0_INFO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_ERR0_INFO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_ERR0_INFO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_ERR0_INFO;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_ERR0_INFO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_ERR0_INFO(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_INFO));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_ERR0_INFO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_INFO));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR,
           INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_INFO));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR,
           INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_INFO));
#endif
    return i_data.extractToRight<INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR,
           INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_FLUSH_INJECT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_FLUSH_INJECT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_FLUSH_INJECT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_FLUSH_INJECT;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_FLUSH_INJECT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_FLUSH_INJECT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_FLUSH_INJECT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3,
           INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3,
           INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3,
           INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_BLOCKID,
           INT_VC_ENDC_FLUSH_INJECT_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_BLOCKID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_BLOCKID,
           INT_VC_ENDC_FLUSH_INJECT_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_INJECT_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_INJECT_BLOCKID,
           INT_VC_ENDC_FLUSH_INJECT_BLOCKID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_OFFSET,
           INT_VC_ENDC_FLUSH_INJECT_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_OFFSET,
           INT_VC_ENDC_FLUSH_INJECT_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_INJECT_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_INJECT_OFFSET,
           INT_VC_ENDC_FLUSH_INJECT_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35,
           INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35,
           INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35,
           INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK,
           INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK,
           INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK,
           INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK,
           INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK,
           INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_INJECT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK,
           INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH2_DATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_WATCH2_DATA2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH2_DATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_WATCH2_DATA2;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH2_DATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH2_DATA2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH2_DATA2));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH2_DATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EQA_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_EQA_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EQA_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_EQA_CFG;
#endif
    return fapi2::getScom(i_target, INT_VC_EQA_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EQA_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return fapi2::putScom(i_target, INT_VC_EQA_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_RESERVED_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_RESERVED_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_RESERVED_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_RESERVED_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_RESERVED_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_RESERVED_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_RESERVED_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_RESERVED_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_RESERVED_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_RESERVED_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_RESERVED_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_INT_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_INT_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_INT_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_INT_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_INT_QUEUE_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_INT_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_INT_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_INT_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_INT_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_INT_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_INT_QUEUE_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_INT_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_RESERVED_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_RESERVED_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_OS_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_OS_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_OS_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_OS_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_OS_QUEUE_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_OS_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_OS_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_OS_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_OS_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_OS_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_OS_QUEUE_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_OS_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_RESERVED_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_RESERVED_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_RESERVED_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_RESERVED_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_RESERVED_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_RESERVED_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_RESERVED_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_RESERVED_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY,
           INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_ERQ_WR_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_ERQ_WR_DISABLE,
           INT_VC_EQA_CFG_ERQ_WR_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_ERQ_WR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_ERQ_WR_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_ERQ_WR_DISABLE,
           INT_VC_EQA_CFG_ERQ_WR_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_ERQ_WR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_ERQ_WR_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_ERQ_WR_DISABLE,
           INT_VC_EQA_CFG_ERQ_WR_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_ERQ_WR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_ERQ_RD_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_ERQ_RD_DISABLE,
           INT_VC_EQA_CFG_ERQ_RD_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_ERQ_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_ERQ_RD_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_ERQ_RD_DISABLE,
           INT_VC_EQA_CFG_ERQ_RD_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_ERQ_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_ERQ_RD_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_ERQ_RD_DISABLE,
           INT_VC_EQA_CFG_ERQ_RD_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_ERQ_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_48_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_48_50,
           INT_VC_EQA_CFG_RESERVED_48_50_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_48_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_48_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_48_50,
           INT_VC_EQA_CFG_RESERVED_48_50_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_48_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_48_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_48_50,
           INT_VC_EQA_CFG_RESERVED_48_50_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_48_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_NXC_FWD_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_NXC_FWD_TO_ENDC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_FWD_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_NXC_FWD_TO_ENDC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_NXC_FWD_TO_ENDC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_FWD_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_NXC_FWD_TO_ENDC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.setBit<INT_VC_EQA_CFG_NXC_FWD_TO_ENDC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_FWD_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EQA_CFG_NXC_FWD_TO_ENDC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.clearBit<INT_VC_EQA_CFG_NXC_FWD_TO_ENDC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_FWD_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_NXC_FWD_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_NXC_FWD_TO_ENDC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_FWD_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EQA_CFG_NXC_FWD_TO_ENDC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.getBit<INT_VC_EQA_CFG_NXC_FWD_TO_ENDC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_NXC_FWD_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_52_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_52_55,
           INT_VC_EQA_CFG_RESERVED_52_55_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_52_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EQA_CFG_RESERVED_52_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return o_data.insertFromRight<INT_VC_EQA_CFG_RESERVED_52_55,
           INT_VC_EQA_CFG_RESERVED_52_55_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_52_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EQA_CFG_RESERVED_52_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EQA_CFG));
#endif
    return i_data.extractToRight<INT_VC_EQA_CFG_RESERVED_52_55,
           INT_VC_EQA_CFG_RESERVED_52_55_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EQA_CFG_RESERVED_52_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ERR_CFG_G1R0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ERR_CFG_G1R0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ERR_CFG_G1R0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ERR_CFG_G1R0;
#endif
    return fapi2::getScom(i_target, INT_VC_ERR_CFG_G1R0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ERR_CFG_G1R0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ERR_CFG_G1R0));
#endif
    return fapi2::putScom(i_target, INT_VC_ERR_CFG_G1R0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ERR_CFG_G1R0));
#endif
    return o_data.insertFromRight<INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG,
           INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ERR_CFG_G1R0));
#endif
    return o_data.insertFromRight<INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG,
           INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ERR_CFG_G1R0));
#endif
    return i_data.extractToRight<INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG,
           INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ESBC_SOFTWR_ADDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ESBC_SOFTWR_ADDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ESBC_SOFTWR_ADDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ESBC_SOFTWR_ADDR;
#endif
    return fapi2::getScom(i_target, INT_VC_ESBC_SOFTWR_ADDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ESBC_SOFTWR_ADDR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return fapi2::putScom(i_target, INT_VC_ESBC_SOFTWR_ADDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_SOFTWR_ADDR_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_SOFTWR_ADDR_BLOCKID,
           INT_VC_ESBC_SOFTWR_ADDR_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_SOFTWR_ADDR_BLOCKID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_SOFTWR_ADDR_BLOCKID,
           INT_VC_ESBC_SOFTWR_ADDR_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_SOFTWR_ADDR_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return i_data.extractToRight<INT_VC_ESBC_SOFTWR_ADDR_BLOCKID,
           INT_VC_ESBC_SOFTWR_ADDR_BLOCKID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35,
           INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35,
           INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return i_data.extractToRight<INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35,
           INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_SOFTWR_ADDR_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_SOFTWR_ADDR_OFFSET,
           INT_VC_ESBC_SOFTWR_ADDR_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_SOFTWR_ADDR_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_SOFTWR_ADDR_OFFSET,
           INT_VC_ESBC_SOFTWR_ADDR_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_SOFTWR_ADDR_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_SOFTWR_ADDR));
#endif
    return i_data.extractToRight<INT_VC_ESBC_SOFTWR_ADDR_OFFSET,
           INT_VC_ESBC_SOFTWR_ADDR_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_SOFTWR_ADDR_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_FATAL_ERR_G1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_FATAL_ERR_G1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_FATAL_ERR_G1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_FATAL_ERR_G1;
#endif
    return fapi2::getScom(i_target, INT_VC_FATAL_ERR_G1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_FATAL_ERR_G1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_FATAL_ERR_G1));
#endif
    return fapi2::putScom(i_target, INT_VC_FATAL_ERR_G1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_FATAL_ERR_G1));
#endif
    return o_data.insertFromRight<INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR,
           INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_FATAL_ERR_G1));
#endif
    return o_data.insertFromRight<INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR,
           INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_FATAL_ERR_G1));
#endif
    return i_data.extractToRight<INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR,
           INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_INFO_ERR_G2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_INFO_ERR_G2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_INFO_ERR_G2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_INFO_ERR_G2;
#endif
    return fapi2::getScom(i_target, INT_VC_INFO_ERR_G2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_INFO_ERR_G2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_INFO_ERR_G2));
#endif
    return fapi2::putScom(i_target, INT_VC_INFO_ERR_G2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_INFO_ERR_G2));
#endif
    return o_data.insertFromRight<INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR,
           INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_INFO_ERR_G2));
#endif
    return o_data.insertFromRight<INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR,
           INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_INFO_ERR_G2));
#endif
    return i_data.extractToRight<INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR,
           INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_CFG_LOC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_QUEUES_CFG_LOC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_CFG_LOC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_QUEUES_CFG_LOC;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_CFG_LOC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_CFG_LOC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_CFG_LOC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_LOC_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_LOC_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_LOC_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_LOC_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_LOC_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_RESERVED_16_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_RESERVED_16_19,
           INT_VC_QUEUES_CFG_LOC_RESERVED_16_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_16_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_RESERVED_16_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_RESERVED_16_19,
           INT_VC_QUEUES_CFG_LOC_RESERVED_16_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_16_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_RESERVED_16_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_RESERVED_16_19,
           INT_VC_QUEUES_CFG_LOC_RESERVED_16_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_RESERVED_16_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_LOC_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_LOC_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_LOC_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_IRQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_LOC_IRQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_LOC_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_LOC_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_LOC_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_LOC_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_IRQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_LOC_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_LOC_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_ERQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_LOC_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_LOC_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_LOC_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_ERQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_LOC_ERQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_LOC_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_ERQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_LOC_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_LOC_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_LOC_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_LOC_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_LOC_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_LOC_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_LOC_ERQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_LOC_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_LOC));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_LOC_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_LOC_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_WOF_ERR_G0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_WOF_ERR_G0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_WOF_ERR_G0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_WOF_ERR_G0;
#endif
    return fapi2::getScom(i_target, INT_VC_WOF_ERR_G0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_WOF_ERR_G0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return fapi2::putScom(i_target, INT_VC_WOF_ERR_G0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IRQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IRQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IRQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IRQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IRQ_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IRQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IRQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ERQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ERQ_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ERQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ERQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ERQ_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ERQ_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ERQ_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ATXC_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ATXC_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ATXC_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ATXC_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ATXC_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ATXC_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ATXC_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ATXC_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ATXC_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ATXC_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.setBit<INT_VC_WOF_ERR_G0_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_WOF_ERR_G0_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return o_data.clearBit<INT_VC_WOF_ERR_G0_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_RESERVED_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_WOF_ERR_G0_RESERVED_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_WOF_ERR_G0));
#endif
    return i_data.getBit<INT_VC_WOF_ERR_G0_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_MUON(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_MUON;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_MUON(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_MUON;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_MUON, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_MUON(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_MUON, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.setBit<MCD_BANK0_MUON_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_MUON_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.clearBit<MCD_BANK0_MUON_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_MUON_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return i_data.extractToRight<MCD_BANK0_MUON_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_MUON_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return i_data.getBit<MCD_BANK0_MUON_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_CHIP_CONTAINED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_CHIP_CONTAINED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_CHIP_CONTAINED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.setBit<MCD_BANK0_MUON_CHIP_CONTAINED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_MUON_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.clearBit<MCD_BANK0_MUON_CHIP_CONTAINED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_MUON_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return i_data.extractToRight<MCD_BANK0_MUON_CHIP_CONTAINED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_MUON_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return i_data.getBit<MCD_BANK0_MUON_CHIP_CONTAINED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.setBit<MCD_BANK0_MUON_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_MUON_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.clearBit<MCD_BANK0_MUON_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_MUON_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return i_data.extractToRight<MCD_BANK0_MUON_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_MUON_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return i_data.getBit<MCD_BANK0_MUON_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_GRP_SIZE,
           MCD_BANK0_MUON_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_GRP_SIZE,
           MCD_BANK0_MUON_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_MUON_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return i_data.extractToRight<MCD_BANK0_MUON_GRP_SIZE,
           MCD_BANK0_MUON_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_GRP_BASE,
           MCD_BANK0_MUON_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_MUON_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return o_data.insertFromRight<MCD_BANK0_MUON_GRP_BASE,
           MCD_BANK0_MUON_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_MUON_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_MUON));
#endif
    return i_data.extractToRight<MCD_BANK0_MUON_GRP_BASE,
           MCD_BANK0_MUON_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_MUON_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_DBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_DBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_DBG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_DBG;
#endif
    return fapi2::getScom(i_target, MCD_DBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_DBG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return fapi2::putScom(i_target, MCD_DBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.setBit<MCD_DBG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.clearBit<MCD_DBG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.getBit<MCD_DBG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_TRACE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_TRACE_SELECT,
           MCD_DBG_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_TRACE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_TRACE_SELECT,
           MCD_DBG_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_TRACE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_TRACE_SELECT,
           MCD_DBG_TRACE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_TRACE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.setBit<MCD_DBG_ERR_INJ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_DBG_ERR_INJ_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.clearBit<MCD_DBG_ERR_INJ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_ERR_INJ_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_ERR_INJ_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_DBG_ERR_INJ_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.getBit<MCD_DBG_ERR_INJ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.setBit<MCD_DBG_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_DBG_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.clearBit<MCD_DBG_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_ERR_INJ_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_DBG_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.getBit<MCD_DBG_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_ACTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_ACTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_ACTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.setBit<MCD_DBG_ERR_INJ_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_DBG_ERR_INJ_ACTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.clearBit<MCD_DBG_ERR_INJ_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_ERR_INJ_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_ERR_INJ_ACTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_DBG_ERR_INJ_ACTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.getBit<MCD_DBG_ERR_INJ_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_ARRAY_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_ARRAY_SEL,
           MCD_DBG_ERR_INJ_ARRAY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_ARRAY_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_ARRAY_SEL,
           MCD_DBG_ERR_INJ_ARRAY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_ERR_INJ_ARRAY_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_ERR_INJ_ARRAY_SEL,
           MCD_DBG_ERR_INJ_ARRAY_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_ERR_INJ_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_ERR_INJ_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.setBit<MCD_DBG_ERR_INJ_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_DBG_ERR_INJ_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.clearBit<MCD_DBG_ERR_INJ_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_ERR_INJ_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_ERR_INJ_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_DBG_ERR_INJ_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.getBit<MCD_DBG_ERR_INJ_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_ERR_INJ_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_PMU_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_PMU_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.setBit<MCD_DBG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_DBG_PMU_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.clearBit<MCD_DBG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_PMU_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_PMU_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_DBG_PMU_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.getBit<MCD_DBG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_SELECT_LOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_PMU_SELECT_LOW,
           MCD_DBG_PMU_SELECT_LOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_SELECT_LOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_SELECT_LOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_PMU_SELECT_LOW,
           MCD_DBG_PMU_SELECT_LOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_SELECT_LOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_PMU_SELECT_LOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_PMU_SELECT_LOW,
           MCD_DBG_PMU_SELECT_LOW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_SELECT_LOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_SELECT_HIGH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_PMU_SELECT_HIGH,
           MCD_DBG_PMU_SELECT_HIGH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_SELECT_HIGH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_SELECT_HIGH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_PMU_SELECT_HIGH,
           MCD_DBG_PMU_SELECT_HIGH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_SELECT_HIGH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_PMU_SELECT_HIGH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_PMU_SELECT_HIGH,
           MCD_DBG_PMU_SELECT_HIGH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_SELECT_HIGH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_BUS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_PMU_BUS_ENABLE,
           MCD_DBG_PMU_BUS_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_BUS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_PMU_BUS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_PMU_BUS_ENABLE,
           MCD_DBG_PMU_BUS_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_BUS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_PMU_BUS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_PMU_BUS_ENABLE,
           MCD_DBG_PMU_BUS_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_PMU_BUS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_RECOVER_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_RECOVER_ADDR,
           MCD_DBG_RECOVER_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_RECOVER_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_DBG_RECOVER_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return o_data.insertFromRight<MCD_DBG_RECOVER_ADDR,
           MCD_DBG_RECOVER_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_RECOVER_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_DBG_RECOVER_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_DBG));
#endif
    return i_data.extractToRight<MCD_DBG_RECOVER_ADDR,
           MCD_DBG_RECOVER_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_DBG_RECOVER_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_ECAP2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_ECAP2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_ECAP2(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_ECAP2;
#endif
    return fapi2::getScom(i_target, MCD_ECAP2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_ECAP2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return fapi2::putScom(i_target, MCD_ECAP2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TOP_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_TOP_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOP_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TOP_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_TOP_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOP_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TOP_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_TOP_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOP_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_TOP_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_TOP_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOP_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_TOP_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_TOP_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOP_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_TOP_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_TOP_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOP_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_STR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_STR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_STR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_STR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_STR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_STR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_STR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_STR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_STR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_STR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_STR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_STR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_STR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_STR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_STR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_STR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_STR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_STR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_BOT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_BOT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_BOT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_BOT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_BOT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_BOT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_BOT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_BOT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_BOT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_BOT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_BOT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_BOT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_CHA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_CHA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_CHA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_CHA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_CHA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_CHA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_CHA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_CHA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_CHA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_CHA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_CHA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_CHA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_MUON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_MUON_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_MUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_MUON_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_MUON_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_MUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_MUON_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_MUON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_MUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_MUON_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_MUON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_MUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_MUON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_MUON_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_MUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_MUON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_MUON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_MUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TAU_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_TAU_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TAU_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TAU_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_TAU_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TAU_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TAU_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_TAU_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TAU_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_TAU_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_TAU_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TAU_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_TAU_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_TAU_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TAU_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_TAU_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_TAU_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TAU_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_GLUON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_GLUON_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_GLUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_GLUON_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_GLUON_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_GLUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_GLUON_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_GLUON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_GLUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_GLUON_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_GLUON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_GLUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_GLUON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_GLUON_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_GLUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_GLUON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_GLUON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_GLUON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_BOSON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_BOSON_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOSON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_BOSON_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_BOSON_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOSON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_BOSON_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_BOSON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOSON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_BOSON_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_BOSON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOSON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_BOSON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_BOSON_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOSON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_BOSON_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_BOSON_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_BOSON_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TOPOID_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_TOPOID_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOPOID_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TOPOID_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_TOPOID_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOPOID_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_TOPOID_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_TOPOID_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOPOID_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_TOPOID_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_TOPOID_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOPOID_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_TOPOID_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_TOPOID_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOPOID_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_TOPOID_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_TOPOID_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_TOPOID_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_CHKSET_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_CHKSET_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHKSET_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_CHKSET_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_CHKSET_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHKSET_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_CHKSET_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_CHKSET_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHKSET_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_CHKSET_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_CHKSET_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHKSET_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_CHKSET_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_CHKSET_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHKSET_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_CHKSET_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_CHKSET_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_CHKSET_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_VGC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_VGC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_VGC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_VGC_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_VGC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_VGC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_VGC_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_VGC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_VGC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_VGC_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_VGC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_VGC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_VGC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_VGC_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_VGC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_VGC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_VGC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_VGC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_REC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_REC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_REC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_REC_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.insertFromRight<MCD_ECAP2_REC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_REC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_ECAP2_REC_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.setBit<MCD_ECAP2_REC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_REC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_ECAP2_REC_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return o_data.clearBit<MCD_ECAP2_REC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_REC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_ECAP2_REC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.extractToRight<MCD_ECAP2_REC_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_REC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_ECAP2_REC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_ECAP2));
#endif
    return i_data.getBit<MCD_ECAP2_REC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_ECAP2_REC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_ADDR_1_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_ADDR_1_HASH_FUNCTION_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_ADDR_1_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_ADDR_1_HASH_FUNCTION_REG;
#endif
    return fapi2::getScom(i_target, NX_CH4_ADDR_1_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_ADDR_1_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_1_HASH_FUNCTION_REG));
#endif
    return fapi2::putScom(i_target, NX_CH4_ADDR_1_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_1_HASH_FUNCTION_REG));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION,
           NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_1_HASH_FUNCTION_REG));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION,
           NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_1_HASH_FUNCTION_REG));
#endif
    return i_data.extractToRight<NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION,
           NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_DATATAG_5_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_DATATAG_5_HASH_FUNCTION_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_DATATAG_5_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_DATATAG_5_HASH_FUNCTION_REG;
#endif
    return fapi2::getScom(i_target, NX_CH4_DATATAG_5_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_DATATAG_5_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_CH4_DATATAG_5_HASH_FUNCTION_REG));
#endif
    return fapi2::putScom(i_target, NX_CH4_DATATAG_5_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_DATATAG_5_HASH_FUNCTION_REG));
#endif
    return o_data.insertFromRight<NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION,
           NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_DATATAG_5_HASH_FUNCTION_REG));
#endif
    return o_data.insertFromRight<NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION,
           NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_DATATAG_5_HASH_FUNCTION_REG));
#endif
    return i_data.extractToRight<NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION,
           NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DBG_DMA_ENG_FIR_ACTION1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DBG_DMA_ENG_FIR_ACTION1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DBG_DMA_ENG_FIR_ACTION1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DBG_DMA_ENG_FIR_ACTION1;
#endif
    return fapi2::getScom(i_target, NX_DBG_DMA_ENG_FIR_ACTION1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DBG_DMA_ENG_FIR_ACTION1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DBG_DMA_ENG_FIR_ACTION1));
#endif
    return fapi2::putScom(i_target, NX_DBG_DMA_ENG_FIR_ACTION1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_DMA_ENG_FIR_ACTION1));
#endif
    return o_data.insertFromRight<NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS,
           NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_DMA_ENG_FIR_ACTION1));
#endif
    return o_data.insertFromRight<NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS,
           NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_DMA_ENG_FIR_ACTION1));
#endif
    return i_data.extractToRight<NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS,
           NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DBG_DMA_ENG_FIR_WOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DBG_DMA_ENG_FIR_WOF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DBG_DMA_ENG_FIR_WOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DBG_DMA_ENG_FIR_WOF;
#endif
    return fapi2::getScom(i_target, NX_DBG_DMA_ENG_FIR_WOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DBG_DMA_ENG_FIR_WOF(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DBG_DMA_ENG_FIR_WOF));
#endif
    return fapi2::putScom(i_target, NX_DBG_DMA_ENG_FIR_WOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_DMA_ENG_FIR_WOF));
#endif
    return o_data.insertFromRight<NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS,
           NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_DMA_ENG_FIR_WOF));
#endif
    return o_data.insertFromRight<NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS,
           NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_DMA_ENG_FIR_WOF));
#endif
    return i_data.extractToRight<NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS,
           NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_SU_CRB_KILL_REQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_SU_CRB_KILL_REQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_SU_CRB_KILL_REQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_SU_CRB_KILL_REQ;
#endif
    return fapi2::getScom(i_target, NX_DMA_SU_CRB_KILL_REQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_SU_CRB_KILL_REQ(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return fapi2::putScom(i_target, NX_DMA_SU_CRB_KILL_REQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.setBit<NX_DMA_SU_CRB_KILL_REQ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.clearBit<NX_DMA_SU_CRB_KILL_REQ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.getBit<NX_DMA_SU_CRB_KILL_REQ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.setBit<NX_DMA_SU_CRB_KILL_REQ_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.clearBit<NX_DMA_SU_CRB_KILL_REQ_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.getBit<NX_DMA_SU_CRB_KILL_REQ_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_SUMMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_SUMMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.setBit<NX_DMA_SU_CRB_KILL_REQ_SUMMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.clearBit<NX_DMA_SU_CRB_KILL_REQ_SUMMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_SUMMARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.getBit<NX_DMA_SU_CRB_KILL_REQ_SUMMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT,
           NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT,
           NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT,
           NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE,
           NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE,
           NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE,
           NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_VAS_MMIO_BASE_ADDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_VAS_MMIO_BASE_ADDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_VAS_MMIO_BASE_ADDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_VAS_MMIO_BASE_ADDR;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_VAS_MMIO_BASE_ADDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_VAS_MMIO_BASE_ADDR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_VAS_MMIO_BASE_ADDR));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_VAS_MMIO_BASE_ADDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_VAS_MMIO_BASE_ADDR));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR,
           NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_VAS_MMIO_BASE_ADDR));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR,
           NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_VAS_MMIO_BASE_ADDR));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR,
           NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_ES3_GP_CMD_RATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_ES3_GP_CMD_RATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_ES3_GP_CMD_RATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_ES3_GP_CMD_RATE;
#endif
    return fapi2::getScom(i_target, PB_COM_ES3_GP_CMD_RATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_ES3_GP_CMD_RATE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return fapi2::putScom(i_target, PB_COM_ES3_GP_CMD_RATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_0_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_0_ES3,
           PB_COM_ES3_GP_CMD_RATE_0_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_0_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_0_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_0_ES3,
           PB_COM_ES3_GP_CMD_RATE_0_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_0_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_GP_CMD_RATE_0_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_GP_CMD_RATE_0_ES3,
           PB_COM_ES3_GP_CMD_RATE_0_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_0_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_1_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_1_ES3,
           PB_COM_ES3_GP_CMD_RATE_1_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_1_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_1_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_1_ES3,
           PB_COM_ES3_GP_CMD_RATE_1_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_1_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_GP_CMD_RATE_1_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_GP_CMD_RATE_1_ES3,
           PB_COM_ES3_GP_CMD_RATE_1_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_1_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_2_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_2_ES3,
           PB_COM_ES3_GP_CMD_RATE_2_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_2_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_2_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_2_ES3,
           PB_COM_ES3_GP_CMD_RATE_2_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_2_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_GP_CMD_RATE_2_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_GP_CMD_RATE_2_ES3,
           PB_COM_ES3_GP_CMD_RATE_2_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_2_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_3_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_3_ES3,
           PB_COM_ES3_GP_CMD_RATE_3_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_3_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_3_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_3_ES3,
           PB_COM_ES3_GP_CMD_RATE_3_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_3_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_GP_CMD_RATE_3_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_GP_CMD_RATE_3_ES3,
           PB_COM_ES3_GP_CMD_RATE_3_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_3_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_4_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_4_ES3,
           PB_COM_ES3_GP_CMD_RATE_4_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_4_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_4_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_4_ES3,
           PB_COM_ES3_GP_CMD_RATE_4_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_4_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_GP_CMD_RATE_4_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_GP_CMD_RATE_4_ES3,
           PB_COM_ES3_GP_CMD_RATE_4_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_4_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_5_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_5_ES3,
           PB_COM_ES3_GP_CMD_RATE_5_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_5_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_5_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_5_ES3,
           PB_COM_ES3_GP_CMD_RATE_5_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_5_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_GP_CMD_RATE_5_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_GP_CMD_RATE_5_ES3,
           PB_COM_ES3_GP_CMD_RATE_5_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_5_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_6_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_6_ES3,
           PB_COM_ES3_GP_CMD_RATE_6_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_6_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_6_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_6_ES3,
           PB_COM_ES3_GP_CMD_RATE_6_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_6_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_GP_CMD_RATE_6_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_GP_CMD_RATE_6_ES3,
           PB_COM_ES3_GP_CMD_RATE_6_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_6_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_7_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_7_ES3,
           PB_COM_ES3_GP_CMD_RATE_7_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_7_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_GP_CMD_RATE_7_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_GP_CMD_RATE_7_ES3,
           PB_COM_ES3_GP_CMD_RATE_7_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_7_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_GP_CMD_RATE_7_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_GP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_GP_CMD_RATE_7_ES3,
           PB_COM_ES3_GP_CMD_RATE_7_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_GP_CMD_RATE_7_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_00_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_00_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_00_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MAILBOX_00_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_00_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_01_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_01_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_01_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MAILBOX_01_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_01_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PMU0_CNPM_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PMU0_CNPM_COUNTER;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PMU0_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PMU0_CNPM_COUNTER));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PMU0_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX, PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_TL_LINK_SYN_23_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_TL_LINK_SYN_23_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_TL_LINK_SYN_23_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_SYN_23_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_TL_LINK_SYN_23_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PMU2_CNPM_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PMU2_CNPM_COUNTER;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PMU2_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PMU2_CNPM_COUNTER));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PMU2_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_WOF_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_WOF_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_WOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_WOF_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_WOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_WOF_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_WOF_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_WOF_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_10_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_10_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_10_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_MAILBOX_10_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_10_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_11_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_11_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_11_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_MAILBOX_11_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_11_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_MAILBOX_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_MAILBOX_CTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_MAILBOX_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_MAILBOX_CTL_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_MAILBOX_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_MAILBOX_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_MAILBOX_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID,
           PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID,
           PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID,
           PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE,
           PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE,
           PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE,
           PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS,
           PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS,
           PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS,
           PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT,
           TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT,
           TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
