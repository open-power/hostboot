/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00004.H $            */
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

#ifndef __C_REG00004_H_
#define __C_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_CCCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CCCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CCCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_CCCR]

//>> GET_[CPMS_CCCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CCCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CCCR;
#endif
    return fapi2::getScom(i_target, CPMS_CCCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_CCCR]

//>> PUT_[CPMS_CCCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CCCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return fapi2::putScom(i_target, CPMS_CCCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CCCR]


//>> SET_[CPMS_CCCR_COUNT_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_MODE,
           CPMS_CCCR_COUNT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_MODE]

//>> SET_[CPMS_CCCR_COUNT_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_MODE,
           CPMS_CCCR_COUNT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_MODE]

//>> GET_[CPMS_CCCR_COUNT_MODE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_COUNT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_COUNT_MODE,
           CPMS_CCCR_COUNT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_COUNT_MODE]

//>> SET_[CPMS_CCCR_COUNT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_TYPE,
           CPMS_CCCR_COUNT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_TYPE]

//>> SET_[CPMS_CCCR_COUNT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_TYPE,
           CPMS_CCCR_COUNT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_TYPE]

//>> GET_[CPMS_CCCR_COUNT_TYPE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_COUNT_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_COUNT_TYPE,
           CPMS_CCCR_COUNT_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_COUNT_TYPE]

//>> SET_[CPMS_CCCR_COUNT_ENABLE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ENABLE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_ENABLE_SEL,
           CPMS_CCCR_COUNT_ENABLE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_ENABLE_SEL]

//>> SET_[CPMS_CCCR_COUNT_ENABLE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ENABLE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_ENABLE_SEL,
           CPMS_CCCR_COUNT_ENABLE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_ENABLE_SEL]

//>> GET_[CPMS_CCCR_COUNT_ENABLE_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_COUNT_ENABLE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_COUNT_ENABLE_SEL,
           CPMS_CCCR_COUNT_ENABLE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_COUNT_ENABLE_SEL]

//>> SET_[CPMS_CCCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_INVERT_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_INVERT_COUNT_ENABLE]

//>> SET_[CPMS_CCCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_INVERT_COUNT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_INVERT_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_INVERT_COUNT_ENABLE]

//>> SET_[CPMS_CCCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.setBit<CPMS_CCCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_INVERT_COUNT_ENABLE]

//>> CLEAR_[CPMS_CCCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.clearBit<CPMS_CCCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CCCR_INVERT_COUNT_ENABLE]

//>> GET_[CPMS_CCCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_INVERT_COUNT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_INVERT_COUNT_ENABLE]

//>> GET_[CPMS_CCCR_INVERT_COUNT_ENABLE]
static inline bool GET_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.getBit<CPMS_CCCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_INVERT_COUNT_ENABLE]

//>> SET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_ALWAYS_SAMPLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]

//>> SET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_ALWAYS_SAMPLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]

//>> SET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.setBit<CPMS_CCCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]

//>> CLEAR_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.clearBit<CPMS_CCCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]

//>> GET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_COUNT_ALWAYS_SAMPLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]

//>> GET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]
static inline bool GET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.getBit<CPMS_CCCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_COUNT_ALWAYS_SAMPLED]

//>> SET_[CPMS_CCCR_HI_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_HI_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_HI_THRESHOLD,
           CPMS_CCCR_HI_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_HI_THRESHOLD]

//>> SET_[CPMS_CCCR_HI_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_HI_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_HI_THRESHOLD,
           CPMS_CCCR_HI_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_HI_THRESHOLD]

//>> GET_[CPMS_CCCR_HI_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_HI_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_HI_THRESHOLD,
           CPMS_CCCR_HI_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_HI_THRESHOLD]

//>> SET_[CPMS_CCCR_LO_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_LO_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_LO_THRESHOLD,
           CPMS_CCCR_LO_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_LO_THRESHOLD]

//>> SET_[CPMS_CCCR_LO_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_LO_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_LO_THRESHOLD,
           CPMS_CCCR_LO_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_LO_THRESHOLD]

//>> GET_[CPMS_CCCR_LO_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_LO_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_LO_THRESHOLD,
           CPMS_CCCR_LO_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_LO_THRESHOLD]

//>> SET_[CPMS_CCCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_SPARE,
           CPMS_CCCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_SPARE]

//>> SET_[CPMS_CCCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_SPARE,
           CPMS_CCCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCCR_SPARE]

//>> GET_[CPMS_CCCR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_SPARE,
           CPMS_CCCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCCR_SPARE]

//>> PREP_[CPMS_DPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DPCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DPCR]

//>> GET_[CPMS_DPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DPCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPCR;
#endif
    return fapi2::getScom(i_target, CPMS_DPCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DPCR]

//>> PUT_[CPMS_DPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return fapi2::putScom(i_target, CPMS_DPCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DPCR]


//>> SET_[CPMS_DPCR_PROXY_SCALE_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_PROXY_SCALE_FACTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_PROXY_SCALE_FACTOR,
           CPMS_DPCR_PROXY_SCALE_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPCR_PROXY_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPCR_PROXY_SCALE_FACTOR]

//>> SET_[CPMS_DPCR_PROXY_SCALE_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_PROXY_SCALE_FACTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_PROXY_SCALE_FACTOR,
           CPMS_DPCR_PROXY_SCALE_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPCR_PROXY_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPCR_PROXY_SCALE_FACTOR]

//>> GET_[CPMS_DPCR_PROXY_SCALE_FACTOR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPCR_PROXY_SCALE_FACTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return i_data.extractToRight<CPMS_DPCR_PROXY_SCALE_FACTOR,
           CPMS_DPCR_PROXY_SCALE_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPCR_PROXY_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPCR_PROXY_SCALE_FACTOR]

//>> SET_[CPMS_DPCR_PROXY_LEAKAGE_CONSTANT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_PROXY_LEAKAGE_CONSTANT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_PROXY_LEAKAGE_CONSTANT,
           CPMS_DPCR_PROXY_LEAKAGE_CONSTANT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPCR_PROXY_LEAKAGE_CONSTANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPCR_PROXY_LEAKAGE_CONSTANT]

//>> SET_[CPMS_DPCR_PROXY_LEAKAGE_CONSTANT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_PROXY_LEAKAGE_CONSTANT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_PROXY_LEAKAGE_CONSTANT,
           CPMS_DPCR_PROXY_LEAKAGE_CONSTANT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPCR_PROXY_LEAKAGE_CONSTANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPCR_PROXY_LEAKAGE_CONSTANT]

//>> GET_[CPMS_DPCR_PROXY_LEAKAGE_CONSTANT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPCR_PROXY_LEAKAGE_CONSTANT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return i_data.extractToRight<CPMS_DPCR_PROXY_LEAKAGE_CONSTANT,
           CPMS_DPCR_PROXY_LEAKAGE_CONSTANT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPCR_PROXY_LEAKAGE_CONSTANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPCR_PROXY_LEAKAGE_CONSTANT]

//>> SET_[CPMS_DPCR_DDP_RECHARGE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_DDP_RECHARGE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_DDP_RECHARGE_VALUE,
           CPMS_DPCR_DDP_RECHARGE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPCR_DDP_RECHARGE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPCR_DDP_RECHARGE_VALUE]

//>> SET_[CPMS_DPCR_DDP_RECHARGE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_DDP_RECHARGE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_DDP_RECHARGE_VALUE,
           CPMS_DPCR_DDP_RECHARGE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPCR_DDP_RECHARGE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPCR_DDP_RECHARGE_VALUE]

//>> GET_[CPMS_DPCR_DDP_RECHARGE_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPCR_DDP_RECHARGE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return i_data.extractToRight<CPMS_DPCR_DDP_RECHARGE_VALUE,
           CPMS_DPCR_DDP_RECHARGE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPCR_DDP_RECHARGE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPCR_DDP_RECHARGE_VALUE]

//>> PREP_[CPMS_PSSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_PSSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PSSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_PSSR]

//>> GET_[CPMS_PSSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_PSSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PSSR;
#endif
    return fapi2::getScom(i_target, CPMS_PSSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_PSSR]

//>> PUT_[CPMS_PSSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_PSSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return fapi2::putScom(i_target, CPMS_PSSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_PSSR]


//>> SET_[CPMS_PSSR_ACCUM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_ACCUM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_ACCUM_ERROR,
           CPMS_PSSR_ACCUM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PSSR_ACCUM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_ACCUM_ERROR]

//>> SET_[CPMS_PSSR_ACCUM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_ACCUM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_ACCUM_ERROR,
           CPMS_PSSR_ACCUM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PSSR_ACCUM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_ACCUM_ERROR]

//>> GET_[CPMS_PSSR_ACCUM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_ACCUM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_ACCUM_ERROR,
           CPMS_PSSR_ACCUM_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PSSR_ACCUM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_ACCUM_ERROR]

//>> SET_[CPMS_PSSR_AVG_FTX_PHASE0]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_PHASE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_PHASE0,
           CPMS_PSSR_AVG_FTX_PHASE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_PHASE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_AVG_FTX_PHASE0]

//>> SET_[CPMS_PSSR_AVG_FTX_PHASE0]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_PHASE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_PHASE0,
           CPMS_PSSR_AVG_FTX_PHASE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_PHASE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_AVG_FTX_PHASE0]

//>> GET_[CPMS_PSSR_AVG_FTX_PHASE0]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_AVG_FTX_PHASE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_AVG_FTX_PHASE0,
           CPMS_PSSR_AVG_FTX_PHASE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_PHASE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_AVG_FTX_PHASE0]

//>> SET_[CPMS_PSSR_AVG_FTX_PHASE1]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_PHASE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_PHASE1,
           CPMS_PSSR_AVG_FTX_PHASE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_PHASE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_AVG_FTX_PHASE1]

//>> SET_[CPMS_PSSR_AVG_FTX_PHASE1]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_PHASE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_PHASE1,
           CPMS_PSSR_AVG_FTX_PHASE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_PHASE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_AVG_FTX_PHASE1]

//>> GET_[CPMS_PSSR_AVG_FTX_PHASE1]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_AVG_FTX_PHASE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_AVG_FTX_PHASE1,
           CPMS_PSSR_AVG_FTX_PHASE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_PHASE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_AVG_FTX_PHASE1]

//>> SET_[CPMS_PSSR_AVG_FTX_TOTAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_TOTAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_TOTAL,
           CPMS_PSSR_AVG_FTX_TOTAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_TOTAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_AVG_FTX_TOTAL]

//>> SET_[CPMS_PSSR_AVG_FTX_TOTAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_TOTAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_TOTAL,
           CPMS_PSSR_AVG_FTX_TOTAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_TOTAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_AVG_FTX_TOTAL]

//>> GET_[CPMS_PSSR_AVG_FTX_TOTAL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_AVG_FTX_TOTAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_AVG_FTX_TOTAL,
           CPMS_PSSR_AVG_FTX_TOTAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PSSR_AVG_FTX_TOTAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_AVG_FTX_TOTAL]

//>> SET_[CPMS_PSSR_PITCH_PERIOD_NUMBER]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_PERIOD_NUMBER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_PERIOD_NUMBER,
           CPMS_PSSR_PITCH_PERIOD_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PSSR_PITCH_PERIOD_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_PERIOD_NUMBER]

//>> SET_[CPMS_PSSR_PITCH_PERIOD_NUMBER]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_PERIOD_NUMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_PERIOD_NUMBER,
           CPMS_PSSR_PITCH_PERIOD_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PSSR_PITCH_PERIOD_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_PERIOD_NUMBER]

//>> GET_[CPMS_PSSR_PITCH_PERIOD_NUMBER]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_PITCH_PERIOD_NUMBER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_PITCH_PERIOD_NUMBER,
           CPMS_PSSR_PITCH_PERIOD_NUMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PSSR_PITCH_PERIOD_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_PITCH_PERIOD_NUMBER]

//>> SET_[CPMS_PSSR_PITCH_SUB_PERIOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_SUB_PERIOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_SUB_PERIOD,
           CPMS_PSSR_PITCH_SUB_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PSSR_PITCH_SUB_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_SUB_PERIOD]

//>> SET_[CPMS_PSSR_PITCH_SUB_PERIOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_SUB_PERIOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_SUB_PERIOD,
           CPMS_PSSR_PITCH_SUB_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PSSR_PITCH_SUB_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_SUB_PERIOD]

//>> GET_[CPMS_PSSR_PITCH_SUB_PERIOD]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_PITCH_SUB_PERIOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_PITCH_SUB_PERIOD,
           CPMS_PSSR_PITCH_SUB_PERIOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PSSR_PITCH_SUB_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_PITCH_SUB_PERIOD]

//>> SET_[CPMS_PSSR_PITCH_PERIOD_TIMER]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_PERIOD_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_PERIOD_TIMER,
           CPMS_PSSR_PITCH_PERIOD_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PSSR_PITCH_PERIOD_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_PERIOD_TIMER]

//>> SET_[CPMS_PSSR_PITCH_PERIOD_TIMER]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_PERIOD_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_PERIOD_TIMER,
           CPMS_PSSR_PITCH_PERIOD_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PSSR_PITCH_PERIOD_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_PERIOD_TIMER]

//>> GET_[CPMS_PSSR_PITCH_PERIOD_TIMER]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_PITCH_PERIOD_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_PITCH_PERIOD_TIMER,
           CPMS_PSSR_PITCH_PERIOD_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PSSR_PITCH_PERIOD_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_PITCH_PERIOD_TIMER]

//>> SET_[CPMS_PSSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_ACTIVE]

//>> SET_[CPMS_PSSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_ACTIVE]

//>> SET_[CPMS_PSSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.setBit<CPMS_PSSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PSSR_PITCH_ACTIVE]

//>> CLEAR_[CPMS_PSSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.clearBit<CPMS_PSSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_PSSR_PITCH_ACTIVE]

//>> GET_[CPMS_PSSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_PITCH_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_PITCH_ACTIVE]

//>> GET_[CPMS_PSSR_PITCH_ACTIVE]
static inline bool GET_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.getBit<CPMS_PSSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PSSR_PITCH_ACTIVE]

//>> PREP_[CPMS_RVCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_RVCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_RVCSR]

//>> GET_[CPMS_RVCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_RVCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR;
#endif
    return fapi2::getScom(i_target, CPMS_RVCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_RVCSR]

//>> PUT_[CPMS_RVCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_RVCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_RVCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_RVCSR]

//>> PREP_[CPMS_RVCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_RVCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_RVCSR_WO_CLEAR]

//>> GET_[CPMS_RVCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_RVCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_RVCSR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_RVCSR_WO_CLEAR]

//>> PUT_[CPMS_RVCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_RVCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_RVCSR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_RVCSR_WO_CLEAR]

//>> PREP_[CPMS_RVCSR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_RVCSR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_RVCSR_WO_OR]

//>> GET_[CPMS_RVCSR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_RVCSR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_RVCSR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_RVCSR_WO_OR]

//>> PUT_[CPMS_RVCSR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_RVCSR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_RVCSR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_RVCSR_WO_OR]


//>> SET_[CPMS_RVCSR_RVID_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ENABLE]

//>> SET_[CPMS_RVCSR_RVID_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ENABLE]

//>> SET_[CPMS_RVCSR_RVID_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_RVID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ENABLE]

//>> CLEAR_[CPMS_RVCSR_RVID_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_RVID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_RVCSR_RVID_ENABLE]

//>> GET_[CPMS_RVCSR_RVID_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVID_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVID_ENABLE]

//>> GET_[CPMS_RVCSR_RVID_ENABLE]
static inline bool GET_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_RVID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVID_ENABLE]

//>> SET_[CPMS_RVCSR_RVID_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_OVERRIDE]

//>> SET_[CPMS_RVCSR_RVID_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_OVERRIDE]

//>> SET_[CPMS_RVCSR_RVID_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_RVID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_OVERRIDE]

//>> CLEAR_[CPMS_RVCSR_RVID_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_RVID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_RVCSR_RVID_OVERRIDE]

//>> GET_[CPMS_RVCSR_RVID_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVID_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVID_OVERRIDE]

//>> GET_[CPMS_RVCSR_RVID_OVERRIDE]
static inline bool GET_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_RVID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVID_OVERRIDE]

//>> SET_[CPMS_RVCSR_ACS_CALIBRATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_ACS_CALIBRATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_ACS_CALIBRATE]

//>> SET_[CPMS_RVCSR_ACS_CALIBRATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_ACS_CALIBRATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_ACS_CALIBRATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_ACS_CALIBRATE]

//>> SET_[CPMS_RVCSR_ACS_CALIBRATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_ACS_CALIBRATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_ACS_CALIBRATE]

//>> CLEAR_[CPMS_RVCSR_ACS_CALIBRATE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_ACS_CALIBRATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_RVCSR_ACS_CALIBRATE]

//>> GET_[CPMS_RVCSR_ACS_CALIBRATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_ACS_CALIBRATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_ACS_CALIBRATE]

//>> GET_[CPMS_RVCSR_ACS_CALIBRATE]
static inline bool GET_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_ACS_CALIBRATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_ACS_CALIBRATE]

//>> SET_[CPMS_RVCSR_RVRM_TUNE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVRM_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVRM_TUNE,
           CPMS_RVCSR_RVRM_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_RVCSR_RVRM_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVRM_TUNE]

//>> SET_[CPMS_RVCSR_RVRM_TUNE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVRM_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVRM_TUNE,
           CPMS_RVCSR_RVRM_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_RVCSR_RVRM_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVRM_TUNE]

//>> GET_[CPMS_RVCSR_RVRM_TUNE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVRM_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVRM_TUNE,
           CPMS_RVCSR_RVRM_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_RVCSR_RVRM_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVRM_TUNE]

//>> SET_[CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ACTIVE]

//>> SET_[CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ACTIVE]

//>> SET_[CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ACTIVE]

//>> CLEAR_[CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_RVCSR_RVID_ACTIVE]

//>> GET_[CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVID_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVID_ACTIVE]

//>> GET_[CPMS_RVCSR_RVID_ACTIVE]
static inline bool GET_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVID_ACTIVE]

//>> SET_[CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_BYPASS_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_BYPASS_ACTIVE]

//>> SET_[CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_BYPASS_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_BYPASS_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_BYPASS_ACTIVE]

//>> SET_[CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_BYPASS_ACTIVE]

//>> CLEAR_[CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_RVCSR_BYPASS_ACTIVE]

//>> GET_[CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_BYPASS_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_BYPASS_ACTIVE]

//>> GET_[CPMS_RVCSR_BYPASS_ACTIVE]
static inline bool GET_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_BYPASS_ACTIVE]

//>> SET_[CPMS_RVCSR_RVID_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ENABLED]

//>> SET_[CPMS_RVCSR_RVID_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ENABLED]

//>> SET_[CPMS_RVCSR_RVID_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_RVID_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_RVCSR_RVID_ENABLED]

//>> CLEAR_[CPMS_RVCSR_RVID_ENABLED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_RVID_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_RVCSR_RVID_ENABLED]

//>> GET_[CPMS_RVCSR_RVID_ENABLED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVID_ENABLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVID_ENABLED]

//>> GET_[CPMS_RVCSR_RVID_ENABLED]
static inline bool GET_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_RVID_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_RVCSR_RVID_ENABLED]

//>> SET_[P10_20_CPMS_RVCSR_BYPASS_RAW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_RVCSR_BYPASS_RAW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_RVCSR_BYPASS_RAW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_RVCSR_BYPASS_RAW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_RVCSR_BYPASS_RAW]

//>> SET_[P10_20_CPMS_RVCSR_BYPASS_RAW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_RVCSR_BYPASS_RAW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_RVCSR_BYPASS_RAW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_RVCSR_BYPASS_RAW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_RVCSR_BYPASS_RAW]

//>> SET_[P10_20_CPMS_RVCSR_BYPASS_RAW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_RVCSR_BYPASS_RAW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<P10_20_CPMS_RVCSR_BYPASS_RAW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_CPMS_RVCSR_BYPASS_RAW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_RVCSR_BYPASS_RAW]

//>> CLEAR_[P10_20_CPMS_RVCSR_BYPASS_RAW]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CPMS_RVCSR_BYPASS_RAW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<P10_20_CPMS_RVCSR_BYPASS_RAW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_CPMS_RVCSR_BYPASS_RAW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CPMS_RVCSR_BYPASS_RAW]

//>> GET_[P10_20_CPMS_RVCSR_BYPASS_RAW]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_RVCSR_BYPASS_RAW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<P10_20_CPMS_RVCSR_BYPASS_RAW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_RVCSR_BYPASS_RAW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_RVCSR_BYPASS_RAW]

//>> GET_[P10_20_CPMS_RVCSR_BYPASS_RAW]
static inline bool GET_P10_20_CPMS_RVCSR_BYPASS_RAW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<P10_20_CPMS_RVCSR_BYPASS_RAW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_CPMS_RVCSR_BYPASS_RAW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_RVCSR_BYPASS_RAW]

//>> PREP_[EC_PC_IMA_EVENT_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_IMA_EVENT_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_IMA_EVENT_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_IMA_EVENT_MASK]

//>> GET_[EC_PC_IMA_EVENT_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_IMA_EVENT_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_IMA_EVENT_MASK;
#endif
    return fapi2::getScom(i_target, EC_PC_IMA_EVENT_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK]

//>> PUT_[EC_PC_IMA_EVENT_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_IMA_EVENT_MASK(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return fapi2::putScom(i_target, EC_PC_IMA_EVENT_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_IMA_EVENT_MASK]


//>> SET_[EC_PC_IMA_EVENT_MASK_IC_TAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_IC_TAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_IC_TAP,
           EC_PC_IMA_EVENT_MASK_IC_TAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_IC_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_IC_TAP]

//>> SET_[EC_PC_IMA_EVENT_MASK_IC_TAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_IC_TAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_IC_TAP,
           EC_PC_IMA_EVENT_MASK_IC_TAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_IC_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_IC_TAP]

//>> GET_[EC_PC_IMA_EVENT_MASK_IC_TAP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_IC_TAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_IC_TAP,
           EC_PC_IMA_EVENT_MASK_IC_TAP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_IC_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_IC_TAP]

//>> SET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_DIS_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]

//>> SET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_DIS_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]

//>> SET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_DIS_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]

//>> CLEAR_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_DIS_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]

//>> GET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_DIS_WRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]

//>> GET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]
static inline bool GET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_DIS_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_DIS_WRAP]

//>> SET_[EC_PC_IMA_EVENT_MASK_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_FREEZE]

//>> SET_[EC_PC_IMA_EVENT_MASK_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_FREEZE]

//>> SET_[EC_PC_IMA_EVENT_MASK_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_FREEZE]

//>> CLEAR_[EC_PC_IMA_EVENT_MASK_FREEZE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_IMA_EVENT_MASK_FREEZE]

//>> GET_[EC_PC_IMA_EVENT_MASK_FREEZE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_FREEZE]

//>> GET_[EC_PC_IMA_EVENT_MASK_FREEZE]
static inline bool GET_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_FREEZE]

//>> SET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EN_D_PRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]

//>> SET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EN_D_PRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]

//>> SET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_EN_D_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]

//>> CLEAR_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_EN_D_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]

//>> GET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_EN_D_PRE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]

//>> GET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]
static inline bool GET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_EN_D_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_EN_D_PRE]

//>> SET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EN_I_PRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]

//>> SET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EN_I_PRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]

//>> SET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_EN_I_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]

//>> CLEAR_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_EN_I_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]

//>> GET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_EN_I_PRE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]

//>> GET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]
static inline bool GET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_EN_I_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_EN_I_PRE]

//>> SET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_ONE_EVENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]

//>> SET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_ONE_EVENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]

//>> SET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_ONE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]

//>> CLEAR_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_ONE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]

//>> GET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_ONE_EVENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]

//>> GET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]
static inline bool GET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_ONE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_ONE_EVENT]

//>> SET_[EC_PC_IMA_EVENT_MASK_EVENT_VTID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EVENT_VTID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EVENT_VTID,
           EC_PC_IMA_EVENT_MASK_EVENT_VTID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EVENT_VTID]

//>> SET_[EC_PC_IMA_EVENT_MASK_EVENT_VTID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EVENT_VTID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EVENT_VTID,
           EC_PC_IMA_EVENT_MASK_EVENT_VTID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EVENT_VTID]

//>> GET_[EC_PC_IMA_EVENT_MASK_EVENT_VTID]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_EVENT_VTID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_EVENT_VTID,
           EC_PC_IMA_EVENT_MASK_EVENT_VTID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_EVENT_VTID]

//>> SET_[EC_PC_IMA_EVENT_MASK_EVENT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EVENT_SELECT,
           EC_PC_IMA_EVENT_MASK_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EVENT_SELECT]

//>> SET_[EC_PC_IMA_EVENT_MASK_EVENT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EVENT_SELECT,
           EC_PC_IMA_EVENT_MASK_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_IMA_EVENT_MASK_EVENT_SELECT]

//>> GET_[EC_PC_IMA_EVENT_MASK_EVENT_SELECT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_EVENT_SELECT,
           EC_PC_IMA_EVENT_MASK_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_IMA_EVENT_MASK_EVENT_SELECT]

//>> PREP_[L2_L2MISC_L2CERRS_TOPOTABLE2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_TOPOTABLE2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_TOPOTABLE2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_TOPOTABLE2]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_TOPOTABLE2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_TOPOTABLE2;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_TOPOTABLE2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2]

//>> PUT_[L2_L2MISC_L2CERRS_TOPOTABLE2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_TOPOTABLE2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_TOPOTABLE2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_TOPOTABLE2]


//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16,
           L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16,
           L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16,
           L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_16]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17,
           L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17,
           L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17,
           L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_17]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18,
           L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18,
           L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18,
           L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_18]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19,
           L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19,
           L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19,
           L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_19]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20,
           L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20,
           L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20,
           L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_20]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21,
           L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21,
           L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21,
           L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_21]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22,
           L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22,
           L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22,
           L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_22]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23,
           L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23,
           L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23,
           L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE2_23]

//>> PREP_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD]

//>> PUT_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD]


//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23]

//>> PREP_[QME_SPWU_FSP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SPWU_FSP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_FSP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SPWU_FSP]

//>> GET_[QME_SPWU_FSP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SPWU_FSP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_FSP;
#endif
    return fapi2::getScom(i_target, QME_SPWU_FSP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SPWU_FSP]

//>> PUT_[QME_SPWU_FSP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SPWU_FSP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return fapi2::putScom(i_target, QME_SPWU_FSP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SPWU_FSP]


//>> SET_[QME_SPWU_FSP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.insertFromRight<QME_SPWU_FSP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_FSP_REQ]

//>> SET_[QME_SPWU_FSP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.insertFromRight<QME_SPWU_FSP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_FSP_REQ]

//>> SET_[QME_SPWU_FSP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.setBit<QME_SPWU_FSP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_FSP_REQ]

//>> CLEAR_[QME_SPWU_FSP_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.clearBit<QME_SPWU_FSP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SPWU_FSP_REQ]

//>> GET_[QME_SPWU_FSP_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return i_data.extractToRight<QME_SPWU_FSP_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_FSP_REQ]

//>> GET_[QME_SPWU_FSP_REQ]
static inline bool GET_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return i_data.getBit<QME_SPWU_FSP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_FSP_REQ]

//>> SET_[QME_SPWU_FSP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.insertFromRight<QME_SPWU_FSP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_FSP_DONE]

//>> SET_[QME_SPWU_FSP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.insertFromRight<QME_SPWU_FSP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_FSP_DONE]

//>> SET_[QME_SPWU_FSP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.setBit<QME_SPWU_FSP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_FSP_DONE]

//>> CLEAR_[QME_SPWU_FSP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.clearBit<QME_SPWU_FSP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SPWU_FSP_DONE]

//>> GET_[QME_SPWU_FSP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return i_data.extractToRight<QME_SPWU_FSP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_FSP_DONE]

//>> GET_[QME_SPWU_FSP_DONE]
static inline bool GET_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return i_data.getBit<QME_SPWU_FSP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_FSP_DONE]

//>> PREP_[QME_SPWU_HYP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SPWU_HYP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_HYP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SPWU_HYP]

//>> GET_[QME_SPWU_HYP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SPWU_HYP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_HYP;
#endif
    return fapi2::getScom(i_target, QME_SPWU_HYP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SPWU_HYP]

//>> PUT_[QME_SPWU_HYP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SPWU_HYP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return fapi2::putScom(i_target, QME_SPWU_HYP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SPWU_HYP]


//>> SET_[QME_SPWU_HYP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.insertFromRight<QME_SPWU_HYP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_HYP_REQ]

//>> SET_[QME_SPWU_HYP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.insertFromRight<QME_SPWU_HYP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_HYP_REQ]

//>> SET_[QME_SPWU_HYP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.setBit<QME_SPWU_HYP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_HYP_REQ]

//>> CLEAR_[QME_SPWU_HYP_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.clearBit<QME_SPWU_HYP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SPWU_HYP_REQ]

//>> GET_[QME_SPWU_HYP_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return i_data.extractToRight<QME_SPWU_HYP_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_HYP_REQ]

//>> GET_[QME_SPWU_HYP_REQ]
static inline bool GET_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return i_data.getBit<QME_SPWU_HYP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_HYP_REQ]

//>> SET_[QME_SPWU_HYP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.insertFromRight<QME_SPWU_HYP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_HYP_DONE]

//>> SET_[QME_SPWU_HYP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.insertFromRight<QME_SPWU_HYP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_HYP_DONE]

//>> SET_[QME_SPWU_HYP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.setBit<QME_SPWU_HYP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_HYP_DONE]

//>> CLEAR_[QME_SPWU_HYP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.clearBit<QME_SPWU_HYP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SPWU_HYP_DONE]

//>> GET_[QME_SPWU_HYP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return i_data.extractToRight<QME_SPWU_HYP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_HYP_DONE]

//>> GET_[QME_SPWU_HYP_DONE]
static inline bool GET_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return i_data.getBit<QME_SPWU_HYP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_HYP_DONE]

//>> PREP_[QME_SPWU_OCC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SPWU_OCC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_OCC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SPWU_OCC]

//>> GET_[QME_SPWU_OCC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SPWU_OCC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_OCC;
#endif
    return fapi2::getScom(i_target, QME_SPWU_OCC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SPWU_OCC]

//>> PUT_[QME_SPWU_OCC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SPWU_OCC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return fapi2::putScom(i_target, QME_SPWU_OCC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SPWU_OCC]


//>> SET_[QME_SPWU_OCC_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.insertFromRight<QME_SPWU_OCC_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OCC_REQ]

//>> SET_[QME_SPWU_OCC_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.insertFromRight<QME_SPWU_OCC_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OCC_REQ]

//>> SET_[QME_SPWU_OCC_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.setBit<QME_SPWU_OCC_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OCC_REQ]

//>> CLEAR_[QME_SPWU_OCC_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.clearBit<QME_SPWU_OCC_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SPWU_OCC_REQ]

//>> GET_[QME_SPWU_OCC_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return i_data.extractToRight<QME_SPWU_OCC_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_OCC_REQ]

//>> GET_[QME_SPWU_OCC_REQ]
static inline bool GET_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return i_data.getBit<QME_SPWU_OCC_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_OCC_REQ]

//>> SET_[QME_SPWU_OCC_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.insertFromRight<QME_SPWU_OCC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OCC_DONE]

//>> SET_[QME_SPWU_OCC_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.insertFromRight<QME_SPWU_OCC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OCC_DONE]

//>> SET_[QME_SPWU_OCC_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.setBit<QME_SPWU_OCC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OCC_DONE]

//>> CLEAR_[QME_SPWU_OCC_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.clearBit<QME_SPWU_OCC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SPWU_OCC_DONE]

//>> GET_[QME_SPWU_OCC_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return i_data.extractToRight<QME_SPWU_OCC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_OCC_DONE]

//>> GET_[QME_SPWU_OCC_DONE]
static inline bool GET_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return i_data.getBit<QME_SPWU_OCC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_OCC_DONE]

//>> PREP_[QME_SSH_FSP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSH_FSP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_FSP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SSH_FSP]

//>> GET_[QME_SSH_FSP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSH_FSP(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_FSP;
#endif
    return fapi2::getScom(i_target, QME_SSH_FSP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SSH_FSP]

//>> PUT_[QME_SSH_FSP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSH_FSP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return fapi2::putScom(i_target, QME_SSH_FSP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SSH_FSP]


//>> SET_[QME_SSH_FSP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_STOP_GATED]

//>> SET_[QME_SSH_FSP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_STOP_GATED]

//>> SET_[QME_SSH_FSP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.setBit<QME_SSH_FSP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_STOP_GATED]

//>> CLEAR_[QME_SSH_FSP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.clearBit<QME_SSH_FSP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_FSP_STOP_GATED]

//>> GET_[QME_SSH_FSP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_STOP_GATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_STOP_GATED]

//>> GET_[QME_SSH_FSP_STOP_GATED]
static inline bool GET_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.getBit<QME_SSH_FSP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_STOP_GATED]

//>> SET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.setBit<QME_SSH_FSP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]

//>> CLEAR_[QME_SSH_FSP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.clearBit<QME_SSH_FSP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_FSP_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]
static inline bool GET_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.getBit<QME_SSH_FSP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_FSP_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_STOP_TRANSITION,
           QME_SSH_FSP_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_FSP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_STOP_TRANSITION]

//>> SET_[QME_SSH_FSP_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_TRANSITION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_STOP_TRANSITION,
           QME_SSH_FSP_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_FSP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_STOP_TRANSITION]

//>> GET_[QME_SSH_FSP_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_STOP_TRANSITION,
           QME_SSH_FSP_STOP_TRANSITION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_FSP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_STOP_TRANSITION]

//>> SET_[QME_SSH_FSP_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_REQ_STOP_LEVEL,
           QME_SSH_FSP_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_FSP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_FSP_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_REQ_STOP_LEVEL,
           QME_SSH_FSP_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_FSP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_FSP_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_REQ_STOP_LEVEL,
           QME_SSH_FSP_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_FSP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_FSP_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_ACT_STOP_LEVEL,
           QME_SSH_FSP_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_FSP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_FSP_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_ACT_STOP_LEVEL,
           QME_SSH_FSP_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_FSP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_FSP_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_ACT_STOP_LEVEL,
           QME_SSH_FSP_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_FSP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL]

//>> PREP_[QME_SSH_HYP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSH_HYP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_HYP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SSH_HYP]

//>> GET_[QME_SSH_HYP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSH_HYP(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_HYP;
#endif
    return fapi2::getScom(i_target, QME_SSH_HYP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SSH_HYP]

//>> PUT_[QME_SSH_HYP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSH_HYP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return fapi2::putScom(i_target, QME_SSH_HYP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SSH_HYP]


//>> SET_[QME_SSH_HYP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_STOP_GATED]

//>> SET_[QME_SSH_HYP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_STOP_GATED]

//>> SET_[QME_SSH_HYP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.setBit<QME_SSH_HYP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_STOP_GATED]

//>> CLEAR_[QME_SSH_HYP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.clearBit<QME_SSH_HYP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_HYP_STOP_GATED]

//>> GET_[QME_SSH_HYP_STOP_GATED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_STOP_GATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_STOP_GATED]

//>> GET_[QME_SSH_HYP_STOP_GATED]
static inline bool GET_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.getBit<QME_SSH_HYP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_STOP_GATED]

//>> SET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.setBit<QME_SSH_HYP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]

//>> CLEAR_[QME_SSH_HYP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.clearBit<QME_SSH_HYP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_HYP_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]
static inline bool GET_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.getBit<QME_SSH_HYP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_HYP_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_STOP_TRANSITION,
           QME_SSH_HYP_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_HYP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_STOP_TRANSITION]

//>> SET_[QME_SSH_HYP_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_TRANSITION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_STOP_TRANSITION,
           QME_SSH_HYP_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_HYP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_STOP_TRANSITION]

//>> GET_[QME_SSH_HYP_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_STOP_TRANSITION,
           QME_SSH_HYP_STOP_TRANSITION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_HYP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_STOP_TRANSITION]

//>> SET_[QME_SSH_HYP_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_REQ_STOP_LEVEL,
           QME_SSH_HYP_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_HYP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_HYP_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_REQ_STOP_LEVEL,
           QME_SSH_HYP_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_HYP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_HYP_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_REQ_STOP_LEVEL,
           QME_SSH_HYP_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_HYP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_HYP_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_ACT_STOP_LEVEL,
           QME_SSH_HYP_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_HYP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_HYP_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_ACT_STOP_LEVEL,
           QME_SSH_HYP_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_HYP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_HYP_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_ACT_STOP_LEVEL,
           QME_SSH_HYP_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_HYP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL]

//>> PREP_[QME_SSH_OCC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSH_OCC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_OCC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SSH_OCC]

//>> GET_[QME_SSH_OCC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSH_OCC(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_OCC;
#endif
    return fapi2::getScom(i_target, QME_SSH_OCC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SSH_OCC]

//>> PUT_[QME_SSH_OCC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSH_OCC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return fapi2::putScom(i_target, QME_SSH_OCC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SSH_OCC]


//>> SET_[QME_SSH_OCC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_STOP_GATED]

//>> SET_[QME_SSH_OCC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_STOP_GATED]

//>> SET_[QME_SSH_OCC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.setBit<QME_SSH_OCC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_STOP_GATED]

//>> CLEAR_[QME_SSH_OCC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.clearBit<QME_SSH_OCC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_OCC_STOP_GATED]

//>> GET_[QME_SSH_OCC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_STOP_GATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_STOP_GATED]

//>> GET_[QME_SSH_OCC_STOP_GATED]
static inline bool GET_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.getBit<QME_SSH_OCC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_STOP_GATED]

//>> SET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.setBit<QME_SSH_OCC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]

//>> CLEAR_[QME_SSH_OCC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.clearBit<QME_SSH_OCC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_OCC_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]
static inline bool GET_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.getBit<QME_SSH_OCC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_OCC_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_STOP_TRANSITION,
           QME_SSH_OCC_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OCC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_STOP_TRANSITION]

//>> SET_[QME_SSH_OCC_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_TRANSITION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_STOP_TRANSITION,
           QME_SSH_OCC_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OCC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_STOP_TRANSITION]

//>> GET_[QME_SSH_OCC_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_STOP_TRANSITION,
           QME_SSH_OCC_STOP_TRANSITION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OCC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_STOP_TRANSITION]

//>> SET_[QME_SSH_OCC_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_REQ_STOP_LEVEL,
           QME_SSH_OCC_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OCC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_OCC_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_REQ_STOP_LEVEL,
           QME_SSH_OCC_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OCC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_OCC_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_REQ_STOP_LEVEL,
           QME_SSH_OCC_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OCC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_OCC_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_ACT_STOP_LEVEL,
           QME_SSH_OCC_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OCC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_OCC_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_ACT_STOP_LEVEL,
           QME_SSH_OCC_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OCC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_OCC_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_ACT_STOP_LEVEL,
           QME_SSH_OCC_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OCC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
