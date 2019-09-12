/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00012.H $            */
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

#ifndef __C_REG00012_H_
#define __C_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CGCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CGCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CGCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CGCSR;
#endif
    return fapi2::getScom(i_target, CPMS_CGCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CGCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_CGCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CGCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CGCSR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CGCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CGCSR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_CGCSR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CGCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_CGCSR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CGCSR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CGCSR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CGCSR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CGCSR_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_CGCSR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CGCSR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_CGCSR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CLK_SYNC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CLK_SYNC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_L3_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_L3_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_L3_CLK_SYNC_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_L3_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_RESERVED_2_3,
           CPMS_CGCSR_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_RESERVED_2_3,
           CPMS_CGCSR_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_RESERVED_2_3,
           CPMS_CGCSR_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CLKGLM_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLKGLM_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CLKGLM_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_L3_CLKGLM_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CGCSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_CL2_CLKGLM_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLKGLM_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_CL2_CLKGLM_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_CL2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_CL2_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_CL2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_CL2_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_CL2_CLKGLM_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CGCSR_CL2_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_CL2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CACHE_SB_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CACHE_SB_CTRL,
           CPMS_CGCSR_L3_CACHE_SB_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CACHE_SB_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CACHE_SB_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CACHE_SB_CTRL,
           CPMS_CGCSR_L3_CACHE_SB_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CACHE_SB_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_L3_CACHE_SB_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_L3_CACHE_SB_CTRL,
           CPMS_CGCSR_L3_CACHE_SB_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CACHE_SB_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CLK_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLK_SYNC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_L3_CLK_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_L3_CLK_SYNC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_CL2_CLK_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLK_SYNC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CGCSR_CL2_CLK_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CGCSR_CL2_CLK_SYNC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DCSR;
#endif
    return fapi2::getScom(i_target, CPMS_DCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DCSR));
#endif
    return fapi2::putScom(i_target, CPMS_DCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_DCSR_0_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCSR));
#endif
    return o_data.insertFromRight<CPMS_DCSR_0_COUNT,
           CPMS_DCSR_0_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DCSR_0_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DCSR_0_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCSR));
#endif
    return o_data.insertFromRight<CPMS_DCSR_0_COUNT,
           CPMS_DCSR_0_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DCSR_0_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DCSR_0_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCSR));
#endif
    return i_data.extractToRight<CPMS_DCSR_0_COUNT,
           CPMS_DCSR_0_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DCSR_0_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DCSR_1_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCSR));
#endif
    return o_data.insertFromRight<CPMS_DCSR_1_COUNT,
           CPMS_DCSR_1_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DCSR_1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DCSR_1_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCSR));
#endif
    return o_data.insertFromRight<CPMS_DCSR_1_COUNT,
           CPMS_DCSR_1_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DCSR_1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DCSR_1_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCSR));
#endif
    return i_data.extractToRight<CPMS_DCSR_1_COUNT,
           CPMS_DCSR_1_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DCSR_1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DHCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DHCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DHCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DHCR;
#endif
    return fapi2::getScom(i_target, CPMS_DHCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DHCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return fapi2::putScom(i_target, CPMS_DHCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.setBit<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.clearBit<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.extractToRight<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.getBit<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.setBit<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.clearBit<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.extractToRight<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.getBit<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.setBit<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.clearBit<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.extractToRight<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.getBit<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_SPARE,
           CPMS_DHCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_SPARE,
           CPMS_DHCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DHCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.extractToRight<CPMS_DHCR_SPARE,
           CPMS_DHCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_EVENT_HISTORY_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_EVENT_HISTORY_SELECT,
           CPMS_DHCR_EVENT_HISTORY_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_EVENT_HISTORY_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_EVENT_HISTORY_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_EVENT_HISTORY_SELECT,
           CPMS_DHCR_EVENT_HISTORY_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_EVENT_HISTORY_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DHCR_EVENT_HISTORY_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.extractToRight<CPMS_DHCR_EVENT_HISTORY_SELECT,
           CPMS_DHCR_EVENT_HISTORY_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_EVENT_HISTORY_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_EVENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_EVENT_COUNT,
           CPMS_DHCR_EVENT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_EVENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_EVENT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.insertFromRight<CPMS_DHCR_EVENT_COUNT,
           CPMS_DHCR_EVENT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_EVENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DHCR_EVENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.extractToRight<CPMS_DHCR_EVENT_COUNT,
           CPMS_DHCR_EVENT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DHCR_EVENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0;
#endif
    return fapi2::getScom(i_target, EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return fapi2::putScom(i_target, EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_SCOMC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SCOMC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_SCOMC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SCOMC;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_SCOMC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_SCOMC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SCOMC));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_SCOMC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC,
           EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC,
           EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC,
           EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SPURR_FREQ_SCALE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SPURR_FREQ_SCALE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SPURR_FREQ_SCALE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SPURR_FREQ_SCALE;
#endif
    return fapi2::getScom(i_target, EC_PC_SPURR_FREQ_SCALE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SPURR_FREQ_SCALE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return fapi2::putScom(i_target, EC_PC_SPURR_FREQ_SCALE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return o_data.insertFromRight<EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return o_data.insertFromRight<EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return o_data.setBit<EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return o_data.clearBit<EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return i_data.extractToRight<EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return i_data.getBit<EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_SCALE_FACTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return o_data.insertFromRight<EC_PC_SPURR_FREQ_SCALE_FACTOR,
           EC_PC_SPURR_FREQ_SCALE_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_SCALE_FACTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return o_data.insertFromRight<EC_PC_SPURR_FREQ_SCALE_FACTOR,
           EC_PC_SPURR_FREQ_SCALE_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_SPURR_FREQ_SCALE_FACTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_SCALE));
#endif
    return i_data.extractToRight<EC_PC_SPURR_FREQ_SCALE_FACTOR,
           EC_PC_SPURR_FREQ_SCALE_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_SPURR_FREQ_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_THRCTL_TCTLCOM_RAS_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_RAS_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_RAS_STATUS;
#endif
    return fapi2::getScom(i_target, EC_PC_THRCTL_TCTLCOM_RAS_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_THRCTL_TCTLCOM_RAS_STATUS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return fapi2::putScom(i_target, EC_PC_THRCTL_TCTLCOM_RAS_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_WR_EPS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_WR_EPS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_WR_EPS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_WR_EPS_REG;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_WR_EPS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_WR_EPS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_WR_EPS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_WR_EPS_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE,
           L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_1;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_CONFIG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_1));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_CONFIG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_1));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR,
           NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR,
           NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR,
           NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
