/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00012.H $            */
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

#ifndef __C_REG00012_H_
#define __C_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_CGCSR]
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
//<< PREP_[CPMS_CGCSR]

//>> GET_[CPMS_CGCSR]
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
//<< GET_[CPMS_CGCSR]

//>> PUT_[CPMS_CGCSR]
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
//<< PUT_[CPMS_CGCSR]

//>> PREP_[CPMS_CGCSR_WO_CLEAR]
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
//<< PREP_[CPMS_CGCSR_WO_CLEAR]

//>> GET_[CPMS_CGCSR_WO_CLEAR]
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
//<< GET_[CPMS_CGCSR_WO_CLEAR]

//>> PUT_[CPMS_CGCSR_WO_CLEAR]
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
//<< PUT_[CPMS_CGCSR_WO_CLEAR]

//>> PREP_[CPMS_CGCSR_WO_OR]
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
//<< PREP_[CPMS_CGCSR_WO_OR]

//>> GET_[CPMS_CGCSR_WO_OR]
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
//<< GET_[CPMS_CGCSR_WO_OR]

//>> PUT_[CPMS_CGCSR_WO_OR]
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
//<< PUT_[CPMS_CGCSR_WO_OR]


//>> SET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]

//>> SET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]

//>> SET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_L3_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]

//>> CLEAR_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_L3_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]

//>> GET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]

//>> GET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]
static inline bool GET_CPMS_CGCSR_L3_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_L3_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CLK_SYNC_ENABLE]

//>> SET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]

//>> SET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]

//>> SET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]

//>> CLEAR_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]

//>> GET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]

//>> GET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]
static inline bool GET_CPMS_CGCSR_CL2_CLK_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_CL2_CLK_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_CL2_CLK_SYNC_ENABLE]

//>> SET_[CPMS_CGCSR_RESERVED_2_3]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_RESERVED_2_3]

//>> SET_[CPMS_CGCSR_RESERVED_2_3]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_RESERVED_2_3]

//>> GET_[CPMS_CGCSR_RESERVED_2_3]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_RESERVED_2_3]

//>> SET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]

//>> SET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]

//>> SET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]

//>> CLEAR_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]

//>> GET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]

//>> GET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]
static inline bool GET_CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET]

//>> SET_[CPMS_CGCSR_L3_CLKGLM_SEL]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLKGLM_SEL]

//>> SET_[CPMS_CGCSR_L3_CLKGLM_SEL]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLKGLM_SEL]

//>> SET_[CPMS_CGCSR_L3_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLKGLM_SEL]

//>> CLEAR_[CPMS_CGCSR_L3_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CGCSR_L3_CLKGLM_SEL]

//>> GET_[CPMS_CGCSR_L3_CLKGLM_SEL]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CLKGLM_SEL]

//>> GET_[CPMS_CGCSR_L3_CLKGLM_SEL]
static inline bool GET_CPMS_CGCSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CGCSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CLKGLM_SEL]

//>> SET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]

//>> SET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]

//>> SET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]

//>> CLEAR_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]

//>> GET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]

//>> GET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]
static inline bool GET_CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET]

//>> SET_[CPMS_CGCSR_CL2_CLKGLM_SEL]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLKGLM_SEL]

//>> SET_[CPMS_CGCSR_CL2_CLKGLM_SEL]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLKGLM_SEL]

//>> SET_[CPMS_CGCSR_CL2_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_CL2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLKGLM_SEL]

//>> CLEAR_[CPMS_CGCSR_CL2_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_CL2_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_CL2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CGCSR_CL2_CLKGLM_SEL]

//>> GET_[CPMS_CGCSR_CL2_CLKGLM_SEL]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_CL2_CLKGLM_SEL]

//>> GET_[CPMS_CGCSR_CL2_CLKGLM_SEL]
static inline bool GET_CPMS_CGCSR_CL2_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_CL2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CGCSR_CL2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_CL2_CLKGLM_SEL]

//>> SET_[CPMS_CGCSR_L3_CACHE_SB_CTRL]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_L3_CACHE_SB_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CACHE_SB_CTRL]

//>> SET_[CPMS_CGCSR_L3_CACHE_SB_CTRL]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_L3_CACHE_SB_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CACHE_SB_CTRL]

//>> GET_[CPMS_CGCSR_L3_CACHE_SB_CTRL]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_L3_CACHE_SB_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CACHE_SB_CTRL]

//>> SET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> SET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> SET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> CLEAR_[CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> GET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> GET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline bool GET_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> SET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> SET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> SET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> CLEAR_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> GET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> GET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline bool GET_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CGCSR, CPMS_CGCSR_WO_CLEAR, CPMS_CGCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> PREP_[EC_PC_COMMON_SPR_SCOMC]
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
//<< PREP_[EC_PC_COMMON_SPR_SCOMC]

//>> GET_[EC_PC_COMMON_SPR_SCOMC]
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
//<< GET_[EC_PC_COMMON_SPR_SCOMC]

//>> PUT_[EC_PC_COMMON_SPR_SCOMC]
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
//<< PUT_[EC_PC_COMMON_SPR_SCOMC]


//>> SET_[EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC]

//>> SET_[EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC]

//>> GET_[EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC]

//>> PREP_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS]
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
//<< PREP_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS]
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
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS]

//>> PUT_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS]
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
//<< PUT_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS]


//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_STATUS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE]

//>> PREP_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG]
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
//<< PREP_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG]
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
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG]

//>> PUT_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG]
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
//<< PUT_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG]


//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]

//>> CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]
static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]

//>> CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]
static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]

//>> CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]
static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]

//>> CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]
static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]

//>> SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]

//>> GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR]

//>> PREP_[CPMS_DHCR]
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
//<< PREP_[CPMS_DHCR]

//>> GET_[CPMS_DHCR]
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
//<< GET_[CPMS_DHCR]

//>> PUT_[CPMS_DHCR]
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
//<< PUT_[CPMS_DHCR]


//>> SET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]

//>> SET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]

//>> SET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.setBit<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]

//>> CLEAR_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.clearBit<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]

//>> GET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]

//>> GET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]
static inline bool GET_CPMS_DHCR_FREEZE_HISTORY_ON_LARGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.getBit<CPMS_DHCR_FREEZE_HISTORY_ON_LARGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DHCR_FREEZE_HISTORY_ON_LARGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_FREEZE_HISTORY_ON_LARGE]

//>> SET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]

//>> SET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]

//>> SET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.setBit<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]

//>> CLEAR_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.clearBit<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]

//>> GET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]

//>> GET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]
static inline bool GET_CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.getBit<CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE]

//>> SET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]

//>> SET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]

//>> SET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.setBit<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]

//>> CLEAR_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return o_data.clearBit<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]

//>> GET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]

//>> GET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]
static inline bool GET_CPMS_DHCR_ADJACENT_WARN_RECORD_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHCR));
#endif
    return i_data.getBit<CPMS_DHCR_ADJACENT_WARN_RECORD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DHCR_ADJACENT_WARN_RECORD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_ADJACENT_WARN_RECORD_MODE]

//>> SET_[CPMS_DHCR_SPARE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_SPARE]

//>> SET_[CPMS_DHCR_SPARE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_SPARE]

//>> GET_[CPMS_DHCR_SPARE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_SPARE]

//>> SET_[CPMS_DHCR_EVENT_HISTORY_SELECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHCR_EVENT_HISTORY_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_EVENT_HISTORY_SELECT]

//>> SET_[CPMS_DHCR_EVENT_HISTORY_SELECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHCR_EVENT_HISTORY_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_EVENT_HISTORY_SELECT]

//>> GET_[CPMS_DHCR_EVENT_HISTORY_SELECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHCR_EVENT_HISTORY_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_EVENT_HISTORY_SELECT]

//>> SET_[CPMS_DHCR_EVENT_COUNT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHCR_EVENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_EVENT_COUNT]

//>> SET_[CPMS_DHCR_EVENT_COUNT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHCR_EVENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHCR_EVENT_COUNT]

//>> GET_[CPMS_DHCR_EVENT_COUNT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHCR_EVENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHCR_EVENT_COUNT]

//>> PREP_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG]
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
//<< PREP_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG]
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
//<< GET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG]

//>> PUT_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG]
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
//<< PUT_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG]


//>> SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
