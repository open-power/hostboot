/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00079.H $         */
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

#ifndef __PROC_REG00079_H_
#define __PROC_REG00079_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_AIB_CTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_AIB_CTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_AIB_CTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_AIB_CTL;
#endif
    return fapi2::getScom(i_target, INT_CQ_AIB_CTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_AIB_CTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return fapi2::putScom(i_target, INT_CQ_AIB_CTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.setBit<INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.clearBit<INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.getBit<INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_RESERVED_1_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_RESERVED_1_25,
           INT_CQ_AIB_CTL_RESERVED_1_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_RESERVED_1_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_RESERVED_1_25,
           INT_CQ_AIB_CTL_RESERVED_1_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_RESERVED_1_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_RESERVED_1_25,
           INT_CQ_AIB_CTL_RESERVED_1_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5,
           INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5,
           INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5,
           INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5,
           INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5,
           INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5,
           INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5,
           INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_RESERVED_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_RESERVED_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_RESERVED_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_RESERVED_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_RESERVED_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.setBit<INT_CQ_AIB_CTL_RESERVED_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_AIB_CTL_RESERVED_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.clearBit<INT_CQ_AIB_CTL_RESERVED_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_RESERVED_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_RESERVED_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_AIB_CTL_RESERVED_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.getBit<INT_CQ_AIB_CTL_RESERVED_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_REINIT_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_REINIT_CREDITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_REINIT_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_REINIT_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_AIB_CTL_REINIT_CREDITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_REINIT_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_AIB_CTL_REINIT_CREDITS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.setBit<INT_CQ_AIB_CTL_REINIT_CREDITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_REINIT_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_AIB_CTL_REINIT_CREDITS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return o_data.clearBit<INT_CQ_AIB_CTL_REINIT_CREDITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_REINIT_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_AIB_CTL_REINIT_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.extractToRight<INT_CQ_AIB_CTL_REINIT_CREDITS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_REINIT_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_AIB_CTL_REINIT_CREDITS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_AIB_CTL));
#endif
    return i_data.getBit<INT_CQ_AIB_CTL_REINIT_CREDITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_AIB_CTL_REINIT_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_CFG_STQ2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_CFG_STQ2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_CFG_STQ2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_CFG_STQ2;
#endif
    return fapi2::getScom(i_target, INT_CQ_CFG_STQ2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_CFG_STQ2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return fapi2::putScom(i_target, INT_CQ_CFG_STQ2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXNC_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXNC_MIN_0_2,
           INT_CQ_CFG_STQ2_NXNC_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXNC_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXNC_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXNC_MIN_0_2,
           INT_CQ_CFG_STQ2_NXNC_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXNC_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_NXNC_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_NXNC_MIN_0_2,
           INT_CQ_CFG_STQ2_NXNC_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXNC_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXNC_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXNC_MAX_0_4,
           INT_CQ_CFG_STQ2_NXNC_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXNC_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXNC_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXNC_MAX_0_4,
           INT_CQ_CFG_STQ2_NXNC_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXNC_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_NXNC_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_NXNC_MAX_0_4,
           INT_CQ_CFG_STQ2_NXNC_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXNC_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXCI_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXCI_MIN_0_2,
           INT_CQ_CFG_STQ2_NXCI_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXCI_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXCI_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXCI_MIN_0_2,
           INT_CQ_CFG_STQ2_NXCI_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXCI_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_NXCI_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_NXCI_MIN_0_2,
           INT_CQ_CFG_STQ2_NXCI_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXCI_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXCI_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXCI_MAX_0_4,
           INT_CQ_CFG_STQ2_NXCI_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXCI_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXCI_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXCI_MAX_0_4,
           INT_CQ_CFG_STQ2_NXCI_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXCI_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_NXCI_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_NXCI_MAX_0_4,
           INT_CQ_CFG_STQ2_NXCI_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXCI_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXLS_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXLS_MIN_0_2,
           INT_CQ_CFG_STQ2_NXLS_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXLS_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXLS_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXLS_MIN_0_2,
           INT_CQ_CFG_STQ2_NXLS_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXLS_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_NXLS_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_NXLS_MIN_0_2,
           INT_CQ_CFG_STQ2_NXLS_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXLS_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXLS_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXLS_MAX_0_4,
           INT_CQ_CFG_STQ2_NXLS_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXLS_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_NXLS_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_NXLS_MAX_0_4,
           INT_CQ_CFG_STQ2_NXLS_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXLS_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_NXLS_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_NXLS_MAX_0_4,
           INT_CQ_CFG_STQ2_NXLS_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_NXLS_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_REG_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_REG_MIN_0_2,
           INT_CQ_CFG_STQ2_REG_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_REG_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_REG_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_REG_MIN_0_2,
           INT_CQ_CFG_STQ2_REG_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_REG_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_REG_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_REG_MIN_0_2,
           INT_CQ_CFG_STQ2_REG_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_REG_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_REG_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_REG_MAX_0_4,
           INT_CQ_CFG_STQ2_REG_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_REG_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_REG_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_REG_MAX_0_4,
           INT_CQ_CFG_STQ2_REG_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_REG_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_REG_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_REG_MAX_0_4,
           INT_CQ_CFG_STQ2_REG_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_REG_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_KILL_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_KILL_MIN_0_2,
           INT_CQ_CFG_STQ2_KILL_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_KILL_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_KILL_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_KILL_MIN_0_2,
           INT_CQ_CFG_STQ2_KILL_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_KILL_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_KILL_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_KILL_MIN_0_2,
           INT_CQ_CFG_STQ2_KILL_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_KILL_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_KILL_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_KILL_MAX_0_4,
           INT_CQ_CFG_STQ2_KILL_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_KILL_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ2_KILL_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ2_KILL_MAX_0_4,
           INT_CQ_CFG_STQ2_KILL_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_KILL_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ2_KILL_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_CFG_STQ2));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ2_KILL_MAX_0_4,
           INT_CQ_CFG_STQ2_KILL_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ2_KILL_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_SWI_CMD4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_SWI_CMD4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_SWI_CMD4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_SWI_CMD4;
#endif
    return fapi2::getScom(i_target, INT_CQ_SWI_CMD4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_SWI_CMD4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_SWI_CMD4));
#endif
    return fapi2::putScom(i_target, INT_CQ_SWI_CMD4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_TAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_TAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_TAR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_TAR;
#endif
    return fapi2::getScom(i_target, INT_CQ_TAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_TAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return fapi2::putScom(i_target, INT_CQ_TAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return o_data.insertFromRight<INT_CQ_TAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return o_data.insertFromRight<INT_CQ_TAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return o_data.setBit<INT_CQ_TAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_TAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return o_data.clearBit<INT_CQ_TAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return i_data.extractToRight<INT_CQ_TAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_TAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return i_data.getBit<INT_CQ_TAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TAR_TABLE_SEL_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return o_data.insertFromRight<INT_CQ_TAR_TABLE_SEL_0_3,
           INT_CQ_TAR_TABLE_SEL_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_TABLE_SEL_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TAR_TABLE_SEL_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return o_data.insertFromRight<INT_CQ_TAR_TABLE_SEL_0_3,
           INT_CQ_TAR_TABLE_SEL_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_TABLE_SEL_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TAR_TABLE_SEL_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return i_data.extractToRight<INT_CQ_TAR_TABLE_SEL_0_3,
           INT_CQ_TAR_TABLE_SEL_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_TABLE_SEL_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TAR_ENTRY_SEL_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return o_data.insertFromRight<INT_CQ_TAR_ENTRY_SEL_0_3,
           INT_CQ_TAR_ENTRY_SEL_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_ENTRY_SEL_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TAR_ENTRY_SEL_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return o_data.insertFromRight<INT_CQ_TAR_ENTRY_SEL_0_3,
           INT_CQ_TAR_ENTRY_SEL_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_ENTRY_SEL_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TAR_ENTRY_SEL_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TAR));
#endif
    return i_data.extractToRight<INT_CQ_TAR_ENTRY_SEL_0_3,
           INT_CQ_TAR_ENTRY_SEL_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TAR_ENTRY_SEL_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_TM_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_TM_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_TM_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_TM_BAR;
#endif
    return fapi2::getScom(i_target, INT_CQ_TM_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_TM_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return fapi2::putScom(i_target, INT_CQ_TM_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.setBit<INT_CQ_TM_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.clearBit<INT_CQ_TM_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.extractToRight<INT_CQ_TM_BAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.getBit<INT_CQ_TM_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_PAGE_SIZE_64K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.setBit<INT_CQ_TM_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.clearBit<INT_CQ_TM_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.extractToRight<INT_CQ_TM_BAR_PAGE_SIZE_64K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.getBit<INT_CQ_TM_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_ADDR_8_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_ADDR_8_49,
           INT_CQ_TM_BAR_ADDR_8_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_ADDR_8_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_ADDR_8_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_ADDR_8_49,
           INT_CQ_TM_BAR_ADDR_8_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_ADDR_8_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TM_BAR_ADDR_8_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.extractToRight<INT_CQ_TM_BAR_ADDR_8_49,
           INT_CQ_TM_BAR_ADDR_8_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TM_BAR_ADDR_8_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_FATAL_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_FATAL_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_FATAL_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_FATAL_ERR;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_FATAL_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_FATAL_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FATAL_ERR));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_FATAL_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FATAL_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR,
           INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FATAL_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR,
           INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FATAL_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR,
           INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_PERF_EVENT_SEL_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_PERF_EVENT_SEL_2;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_PERF_EVENT_SEL_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_PERF_EVENT_SEL_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_PERF_EVENT_SEL_2));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH3_DATA0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WATCH3_DATA0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH3_DATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WATCH3_DATA0;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH3_DATA0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH3_DATA0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WATCH3_DATA0));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH3_DATA0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_DBG_PMC_ATX0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_DBG_PMC_ATX0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_DBG_PMC_ATX0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_DBG_PMC_ATX0;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_DBG_PMC_ATX0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_DBG_PMC_ATX0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_DBG_PMC_ATX0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_0,
           INT_PC_REGS_DBG_PMC_ATX0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_0,
           INT_PC_REGS_DBG_PMC_ATX0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_0,
           INT_PC_REGS_DBG_PMC_ATX0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_1,
           INT_PC_REGS_DBG_PMC_ATX0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_1,
           INT_PC_REGS_DBG_PMC_ATX0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_1,
           INT_PC_REGS_DBG_PMC_ATX0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_2,
           INT_PC_REGS_DBG_PMC_ATX0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_2,
           INT_PC_REGS_DBG_PMC_ATX0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_2,
           INT_PC_REGS_DBG_PMC_ATX0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_3,
           INT_PC_REGS_DBG_PMC_ATX0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_3,
           INT_PC_REGS_DBG_PMC_ATX0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_3,
           INT_PC_REGS_DBG_PMC_ATX0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_15,
           INT_PC_REGS_DBG_PMC_ATX0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_15,
           INT_PC_REGS_DBG_PMC_ATX0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_15,
           INT_PC_REGS_DBG_PMC_ATX0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_4R(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_4R,
           INT_PC_REGS_DBG_PMC_ATX0_4R_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_4R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_4R(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_4R,
           INT_PC_REGS_DBG_PMC_ATX0_4R_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_4R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_4R(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_4R,
           INT_PC_REGS_DBG_PMC_ATX0_4R_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_4R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_4W(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_4W,
           INT_PC_REGS_DBG_PMC_ATX0_4W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_4W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_4W(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_4W,
           INT_PC_REGS_DBG_PMC_ATX0_4W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_4W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_4W(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_4W,
           INT_PC_REGS_DBG_PMC_ATX0_4W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_4W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_5,
           INT_PC_REGS_DBG_PMC_ATX0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_5,
           INT_PC_REGS_DBG_PMC_ATX0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_5,
           INT_PC_REGS_DBG_PMC_ATX0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_6,
           INT_PC_REGS_DBG_PMC_ATX0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_6,
           INT_PC_REGS_DBG_PMC_ATX0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_6,
           INT_PC_REGS_DBG_PMC_ATX0_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_7,
           INT_PC_REGS_DBG_PMC_ATX0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_7,
           INT_PC_REGS_DBG_PMC_ATX0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_7,
           INT_PC_REGS_DBG_PMC_ATX0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_8,
           INT_PC_REGS_DBG_PMC_ATX0_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_8,
           INT_PC_REGS_DBG_PMC_ATX0_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_8,
           INT_PC_REGS_DBG_PMC_ATX0_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_9,
           INT_PC_REGS_DBG_PMC_ATX0_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_9,
           INT_PC_REGS_DBG_PMC_ATX0_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_9,
           INT_PC_REGS_DBG_PMC_ATX0_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_10,
           INT_PC_REGS_DBG_PMC_ATX0_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_10,
           INT_PC_REGS_DBG_PMC_ATX0_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_10,
           INT_PC_REGS_DBG_PMC_ATX0_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_11,
           INT_PC_REGS_DBG_PMC_ATX0_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_11,
           INT_PC_REGS_DBG_PMC_ATX0_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_11,
           INT_PC_REGS_DBG_PMC_ATX0_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_12,
           INT_PC_REGS_DBG_PMC_ATX0_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_12,
           INT_PC_REGS_DBG_PMC_ATX0_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_12,
           INT_PC_REGS_DBG_PMC_ATX0_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_13,
           INT_PC_REGS_DBG_PMC_ATX0_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX0_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX0_13,
           INT_PC_REGS_DBG_PMC_ATX0_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX0_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_PMC_ATX0));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX0_13,
           INT_PC_REGS_DBG_PMC_ATX0_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_FLUSH_POLL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_EASC_FLUSH_POLL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_FLUSH_POLL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_EASC_FLUSH_POLL;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_FLUSH_POLL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_FLUSH_POLL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_FLUSH_POLL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_POLL_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_POLL_BLOCKID,
           INT_VC_EASC_FLUSH_POLL_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_POLL_BLOCKID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_POLL_BLOCKID,
           INT_VC_EASC_FLUSH_POLL_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_POLL_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_POLL_BLOCKID,
           INT_VC_EASC_FLUSH_POLL_BLOCKID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_POLL_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_POLL_OFFSET,
           INT_VC_EASC_FLUSH_POLL_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_POLL_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_POLL_OFFSET,
           INT_VC_EASC_FLUSH_POLL_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_POLL_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_POLL_OFFSET,
           INT_VC_EASC_FLUSH_POLL_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK,
           INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK,
           INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK,
           INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_POLL_OFFSET_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_POLL_OFFSET_MASK,
           INT_VC_EASC_FLUSH_POLL_OFFSET_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_POLL_OFFSET_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_POLL_OFFSET_MASK,
           INT_VC_EASC_FLUSH_POLL_OFFSET_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_POLL_OFFSET_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_POLL_OFFSET_MASK,
           INT_VC_EASC_FLUSH_POLL_OFFSET_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_POLL_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_ADDITIONAL_PERF_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_ADDITIONAL_PERF_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_ADDITIONAL_PERF_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_ADDITIONAL_PERF_1;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_ADDITIONAL_PERF_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_ADDITIONAL_PERF_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_ADDITIONAL_PERF_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.setBit<INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.clearBit<INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.getBit<INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.setBit<INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.clearBit<INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.getBit<INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7,
           INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7,
           INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7,
           INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO,
           INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY,
           INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY,
           INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY,
           INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63,
           INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63,
           INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_ADDITIONAL_PERF_1));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63,
           INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH0_DATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_WATCH0_DATA2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH0_DATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_WATCH0_DATA2;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH0_DATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH0_DATA2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH0_DATA2));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH0_DATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH1_SPEC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_WATCH1_SPEC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH1_SPEC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_WATCH1_SPEC;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH1_SPEC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH1_SPEC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH1_SPEC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_CONFLICT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_CONFLICT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_CONFLICT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_CONFLICT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_CONFLICT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_CONFLICT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_CONFLICT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.setBit<INT_VC_ENDC_WATCH1_SPEC_CONFLICT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_CONFLICT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_WATCH1_SPEC_CONFLICT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.clearBit<INT_VC_ENDC_WATCH1_SPEC_CONFLICT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_CONFLICT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_WATCH1_SPEC_CONFLICT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.extractToRight<INT_VC_ENDC_WATCH1_SPEC_CONFLICT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_CONFLICT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_ENDC_WATCH1_SPEC_CONFLICT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.getBit<INT_VC_ENDC_WATCH1_SPEC_CONFLICT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_CONFLICT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.extractToRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.setBit<INT_VC_ENDC_WATCH1_SPEC_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_WATCH1_SPEC_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.clearBit<INT_VC_ENDC_WATCH1_SPEC_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_WATCH1_SPEC_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.extractToRight<INT_VC_ENDC_WATCH1_SPEC_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_ENDC_WATCH1_SPEC_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.getBit<INT_VC_ENDC_WATCH1_SPEC_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.extractToRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_BLOCKID,
           INT_VC_ENDC_WATCH1_SPEC_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_BLOCKID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_BLOCKID,
           INT_VC_ENDC_WATCH1_SPEC_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_WATCH1_SPEC_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.extractToRight<INT_VC_ENDC_WATCH1_SPEC_BLOCKID,
           INT_VC_ENDC_WATCH1_SPEC_BLOCKID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.extractToRight<INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39,
           INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_OFFSET,
           INT_VC_ENDC_WATCH1_SPEC_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_WATCH1_SPEC_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_WATCH1_SPEC_OFFSET,
           INT_VC_ENDC_WATCH1_SPEC_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_WATCH1_SPEC_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_SPEC));
#endif
    return i_data.extractToRight<INT_VC_ENDC_WATCH1_SPEC_OFFSET,
           INT_VC_ENDC_WATCH1_SPEC_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_WATCH1_SPEC_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_END_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_END_BLOCK_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_END_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_END_BLOCK_MODE;
#endif
    return fapi2::getScom(i_target, INT_VC_END_BLOCK_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_END_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_END_BLOCK_MODE));
#endif
    return fapi2::putScom(i_target, INT_VC_END_BLOCK_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_END_BLOCK_MODE));
#endif
    return o_data.insertFromRight<INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE,
           INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_END_BLOCK_MODE));
#endif
    return o_data.insertFromRight<INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE,
           INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_END_BLOCK_MODE));
#endif
    return i_data.extractToRight<INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE,
           INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ERR_CFG_G2R0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ERR_CFG_G2R0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ERR_CFG_G2R0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ERR_CFG_G2R0;
#endif
    return fapi2::getScom(i_target, INT_VC_ERR_CFG_G2R0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ERR_CFG_G2R0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ERR_CFG_G2R0));
#endif
    return fapi2::putScom(i_target, INT_VC_ERR_CFG_G2R0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ERR_CFG_G2R0));
#endif
    return o_data.insertFromRight<INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG,
           INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ERR_CFG_G2R0));
#endif
    return o_data.insertFromRight<INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG,
           INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ERR_CFG_G2R0));
#endif
    return i_data.extractToRight<INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG,
           INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ESBC_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ESBC_PERF_EVENT_SEL_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ESBC_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ESBC_PERF_EVENT_SEL_1;
#endif
    return fapi2::getScom(i_target, INT_VC_ESBC_PERF_EVENT_SEL_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ESBC_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return fapi2::putScom(i_target, INT_VC_ESBC_PERF_EVENT_SEL_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED,
           INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED,
           INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED,
           INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED,
           INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED,
           INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED,
           INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES,
           INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES,
           INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES,
           INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU,
           INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU,
           INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU,
           INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY,
           INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY,
           INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY,
           INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_PERF_EVENT_SEL_1));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT,
           INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_ADDR_2_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_ADDR_2_HASH_FUNCTION_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_ADDR_2_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_ADDR_2_HASH_FUNCTION_REG;
#endif
    return fapi2::getScom(i_target, NX_CH4_ADDR_2_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_ADDR_2_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_2_HASH_FUNCTION_REG));
#endif
    return fapi2::putScom(i_target, NX_CH4_ADDR_2_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_2_HASH_FUNCTION_REG));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION,
           NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_2_HASH_FUNCTION_REG));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION,
           NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_2_HASH_FUNCTION_REG));
#endif
    return i_data.extractToRight<NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION,
           NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_GZIP_CONTROL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_GZIP_CONTROL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_GZIP_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_GZIP_CONTROL_REG;
#endif
    return fapi2::getScom(i_target, NX_CH4_GZIP_CONTROL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_GZIP_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return fapi2::putScom(i_target, NX_CH4_GZIP_CONTROL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.setBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.clearBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.extractToRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.getBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.setBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.clearBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.extractToRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.getBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.setBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.clearBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.extractToRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.getBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.setBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.clearBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.extractToRight<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.getBit<NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK,
           NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK,
           NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_CONTROL_REG));
#endif
    return i_data.extractToRight<NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK,
           NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_EFT_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_EFT_MAX_BYTE_CNT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_EFT_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_EFT_MAX_BYTE_CNT;
#endif
    return fapi2::getScom(i_target, NX_DMA_EFT_MAX_BYTE_CNT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_EFT_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return fapi2::putScom(i_target, NX_DMA_EFT_MAX_BYTE_CNT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT,
           NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT,
           NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT,
           NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_EFT_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT,
           NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_RESET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_RESET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_RESET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_RESET;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_RESET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_RESET(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RESET));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_RESET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RESET_RNG_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RESET));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RESET_RNG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_RESET_RNG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RESET_RNG_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RESET));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RESET_RNG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_RESET_RNG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RESET_RNG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RESET));
#endif
    return o_data.setBit<NX_PBI_RNG_RESET_RNG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_RESET_RNG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_RESET_RNG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RESET));
#endif
    return o_data.clearBit<NX_PBI_RNG_RESET_RNG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_RESET_RNG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_RESET_RNG_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RESET));
#endif
    return i_data.extractToRight<NX_PBI_RNG_RESET_RNG_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_RESET_RNG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_RESET_RNG_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RESET));
#endif
    return i_data.getBit<NX_PBI_RNG_RESET_RNG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_RESET_RNG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_ES3_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_ES3_HP_MODE1_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_ES3_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_ES3_HP_MODE1_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_ES3_HP_MODE1_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_ES3_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_ES3_HP_MODE1_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_ES3_SP_CMD_RATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_ES3_SP_CMD_RATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_ES3_SP_CMD_RATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_ES3_SP_CMD_RATE;
#endif
    return fapi2::getScom(i_target, PB_COM_ES3_SP_CMD_RATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_ES3_SP_CMD_RATE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return fapi2::putScom(i_target, PB_COM_ES3_SP_CMD_RATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_0_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_0_ES3,
           PB_COM_ES3_SP_CMD_RATE_0_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_0_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_0_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_0_ES3,
           PB_COM_ES3_SP_CMD_RATE_0_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_0_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_SP_CMD_RATE_0_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_SP_CMD_RATE_0_ES3,
           PB_COM_ES3_SP_CMD_RATE_0_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_0_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_1_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_1_ES3,
           PB_COM_ES3_SP_CMD_RATE_1_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_1_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_1_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_1_ES3,
           PB_COM_ES3_SP_CMD_RATE_1_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_1_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_SP_CMD_RATE_1_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_SP_CMD_RATE_1_ES3,
           PB_COM_ES3_SP_CMD_RATE_1_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_1_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_2_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_2_ES3,
           PB_COM_ES3_SP_CMD_RATE_2_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_2_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_2_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_2_ES3,
           PB_COM_ES3_SP_CMD_RATE_2_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_2_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_SP_CMD_RATE_2_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_SP_CMD_RATE_2_ES3,
           PB_COM_ES3_SP_CMD_RATE_2_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_2_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_3_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_3_ES3,
           PB_COM_ES3_SP_CMD_RATE_3_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_3_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_3_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_3_ES3,
           PB_COM_ES3_SP_CMD_RATE_3_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_3_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_SP_CMD_RATE_3_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_SP_CMD_RATE_3_ES3,
           PB_COM_ES3_SP_CMD_RATE_3_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_3_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_4_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_4_ES3,
           PB_COM_ES3_SP_CMD_RATE_4_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_4_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_4_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_4_ES3,
           PB_COM_ES3_SP_CMD_RATE_4_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_4_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_SP_CMD_RATE_4_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_SP_CMD_RATE_4_ES3,
           PB_COM_ES3_SP_CMD_RATE_4_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_4_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_5_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_5_ES3,
           PB_COM_ES3_SP_CMD_RATE_5_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_5_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_5_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_5_ES3,
           PB_COM_ES3_SP_CMD_RATE_5_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_5_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_SP_CMD_RATE_5_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_SP_CMD_RATE_5_ES3,
           PB_COM_ES3_SP_CMD_RATE_5_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_5_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_6_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_6_ES3,
           PB_COM_ES3_SP_CMD_RATE_6_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_6_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_6_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_6_ES3,
           PB_COM_ES3_SP_CMD_RATE_6_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_6_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_SP_CMD_RATE_6_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_SP_CMD_RATE_6_ES3,
           PB_COM_ES3_SP_CMD_RATE_6_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_6_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_7_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_7_ES3,
           PB_COM_ES3_SP_CMD_RATE_7_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_7_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_SP_CMD_RATE_7_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_ES3_SP_CMD_RATE_7_ES3,
           PB_COM_ES3_SP_CMD_RATE_7_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_7_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_SP_CMD_RATE_7_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_ES3_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_ES3_SP_CMD_RATE_7_ES3,
           PB_COM_ES3_SP_CMD_RATE_7_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_SP_CMD_RATE_7_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_CFG_CNPM_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_CFG_CNPM_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_CFG_CNPM_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_CFG_CNPM_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_CFG_CNPM_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_CFG_CNPM_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_CFG_CNPM_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_CFG_CNPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_CFG_CNPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_CFG_CNPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP,
           PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3,
           PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_SPARE,
           PB_PTLSCOM10_CFG_CNPM_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_CFG_CNPM_REG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_CFG_CNPM_REG_SPARE,
           PB_PTLSCOM10_CFG_CNPM_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_CFG_CNPM_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_CFG_CNPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_CFG_CNPM_REG_SPARE,
           PB_PTLSCOM10_CFG_CNPM_REG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_CFG_CNPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_FP01_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FP01_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_FP01_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FP01_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_FP01_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_FP01_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_FP01_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME,
           PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME,
           PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME,
           PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MISC_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MISC_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MISC_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MISC_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MISC_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MISC_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MISC_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL,
           PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL,
           PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL,
           PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL,
           PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL,
           PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL,
           PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_MISC_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_MISC_SPARE,
           PB_PTLSCOM10_MISC_CFG_MISC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_MISC_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_MISC_SPARE,
           PB_PTLSCOM10_MISC_CFG_MISC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_MISC_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_MISC_SPARE,
           PB_PTLSCOM10_MISC_CFG_MISC_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PMU3_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PMU3_TLPM_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PMU3_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PMU3_TLPM_COUNTER;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PMU3_TLPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PMU3_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PMU3_TLPM_COUNTER));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PMU3_TLPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_WOF_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_WOF_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_WOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_WOF_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_WOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_WOF_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_WOF_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_WOF_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PMU1_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PMU1_TLPM_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PMU1_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PMU1_TLPM_COUNTER;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PMU1_TLPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PMU1_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PMU1_TLPM_COUNTER));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PMU1_TLPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_CFG_TLPM_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_CFG_TLPM_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_CFG_TLPM_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_CFG_TLPM_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_CFG_TLPM_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_CFG_TLPM_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_CFG_TLPM_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_CFG_TLPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_CFG_TLPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_CFG_TLPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP,
           PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3,
           PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_SPARE,
           PB_PTLSCOM45_CFG_TLPM_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_REG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_REG_SPARE,
           PB_PTLSCOM45_CFG_TLPM_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_REG_SPARE,
           PB_PTLSCOM45_CFG_TLPM_REG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_TL_LINK_SYN_23_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_TL_LINK_SYN_23_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_TL_LINK_SYN_23_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_SYN_23_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_TL_LINK_SYN_23_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_TRACE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_TRACE_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_TRACE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_TRACE_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_TRACE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_TRACE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_TRACE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TRACE_CFG_0L_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TRACE_CFG_0L_SEL,
           PB_PTLSCOM67_TRACE_CFG_0L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TRACE_CFG_0L_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TRACE_CFG_0L_SEL,
           PB_PTLSCOM67_TRACE_CFG_0L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TRACE_CFG_0L_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TRACE_CFG_0L_SEL,
           PB_PTLSCOM67_TRACE_CFG_0L_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TRACE_CFG_0R_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TRACE_CFG_0R_SEL,
           PB_PTLSCOM67_TRACE_CFG_0R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TRACE_CFG_0R_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TRACE_CFG_0R_SEL,
           PB_PTLSCOM67_TRACE_CFG_0R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TRACE_CFG_0R_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TRACE_CFG_0R_SEL,
           PB_PTLSCOM67_TRACE_CFG_0R_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TRACE_CFG_1L_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TRACE_CFG_1L_SEL,
           PB_PTLSCOM67_TRACE_CFG_1L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TRACE_CFG_1L_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TRACE_CFG_1L_SEL,
           PB_PTLSCOM67_TRACE_CFG_1L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TRACE_CFG_1L_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TRACE_CFG_1L_SEL,
           PB_PTLSCOM67_TRACE_CFG_1L_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TRACE_CFG_1R_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TRACE_CFG_1R_SEL,
           PB_PTLSCOM67_TRACE_CFG_1R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TRACE_CFG_1R_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TRACE_CFG_1R_SEL,
           PB_PTLSCOM67_TRACE_CFG_1R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TRACE_CFG_1R_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TRACE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TRACE_CFG_1R_SEL,
           PB_PTLSCOM67_TRACE_CFG_1R_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_DECAY_0_CONTROL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_DECAY_0_CONTROL_REG;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_DECAY_0_CONTROL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_DECAY_0_CONTROL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return o_data.setBit<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return o_data.clearBit<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return i_data.getBit<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY,
           PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY,
           PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_CONTROL_REG));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY,
           PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_PRDSTKOVR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_PRDSTKOVR_REG;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_PRDSTKOVR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_PRDSTKOVR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0,
           PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0,
           PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0,
           PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1,
           PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1,
           PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1,
           PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return o_data.setBit<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return o_data.clearBit<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_PRDSTKOVR_REG));
#endif
    return i_data.getBit<PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0,
           PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0,
           PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0,
           PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND,
                           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND,
                           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND,
                           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND,
                           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK,
           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND,
                           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK,
           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW, PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND,
                           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK,
           PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE,
           PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND,
                           PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND,
                           PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND,
                           PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG;
#endif
    return fapi2::getScom(i_target, PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return fapi2::putScom(i_target, PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR,
           PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3;
#endif
    return fapi2::getScom(i_target, PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3));
#endif
    return fapi2::putScom(i_target, PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3,
           PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3,
           PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3,
           PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG;
#endif
    return fapi2::getScom(i_target, PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG));
#endif
    return fapi2::putScom(i_target, PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0,
           PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0,
           PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0,
           PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG;
#endif
    return fapi2::getScom(i_target, PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return fapi2::putScom(i_target, PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK;
#endif
    return fapi2::getScom(i_target, PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return fapi2::putScom(i_target, PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return o_data.insertFromRight<PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return o_data.insertFromRight<PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return i_data.extractToRight<PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK;
#endif
    return fapi2::getScom(i_target, PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return fapi2::putScom(i_target, PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return o_data.insertFromRight<PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return o_data.insertFromRight<PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return i_data.extractToRight<PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL;
#endif
    return fapi2::getScom(i_target, PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL));
#endif
    return fapi2::putScom(i_target, PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP;
#endif
    return fapi2::getScom(i_target, PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return fapi2::putScom(i_target, PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.insertFromRight<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.insertFromRight<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.setBit<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.clearBit<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return i_data.extractToRight<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return i_data.getBit<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.insertFromRight<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.insertFromRight<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP));
#endif
    return i_data.extractToRight<PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_LPC_SYNC_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_LPC_SYNC_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_LPC_SYNC_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_LPC_SYNC_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, TP_LPC_SYNC_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_LPC_SYNC_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_LPC_SYNC_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_LPC_SYNC_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_LPC_SYNC_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_LPC_SYNC_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_LPC_SYNC_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_LPC_SYNC_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_LPC_SYNC_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_LPC_SYNC_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_LPC_SYNC_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_LPC_SYNC_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_LPC_SYNC_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_LPC_SYNC_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_LPC_SYNC_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_LPC_SYNC_FIR_MASK_REG_RW, TP_LPC_SYNC_FIR_MASK_REG_WO_AND, TP_LPC_SYNC_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
