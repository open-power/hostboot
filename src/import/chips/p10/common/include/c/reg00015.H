/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00015.H $            */
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

#ifndef __C_REG00015_H_
#define __C_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_ACCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_ACCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_ACCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_ACCR]

//>> GET_[CPMS_ACCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_ACCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_ACCR;
#endif
    return fapi2::getScom(i_target, CPMS_ACCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_ACCR]

//>> PUT_[CPMS_ACCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_ACCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return fapi2::putScom(i_target, CPMS_ACCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_ACCR]


//>> SET_[CPMS_ACCR_COUNT_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_COUNT_MODE,
           CPMS_ACCR_COUNT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ACCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_MODE]

//>> SET_[CPMS_ACCR_COUNT_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_COUNT_MODE,
           CPMS_ACCR_COUNT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ACCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_MODE]

//>> GET_[CPMS_ACCR_COUNT_MODE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ACCR_COUNT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.extractToRight<CPMS_ACCR_COUNT_MODE,
           CPMS_ACCR_COUNT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ACCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_COUNT_MODE]

//>> SET_[CPMS_ACCR_COUNT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_COUNT_TYPE,
           CPMS_ACCR_COUNT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ACCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_TYPE]

//>> SET_[CPMS_ACCR_COUNT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_COUNT_TYPE,
           CPMS_ACCR_COUNT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ACCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_TYPE]

//>> GET_[CPMS_ACCR_COUNT_TYPE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ACCR_COUNT_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.extractToRight<CPMS_ACCR_COUNT_TYPE,
           CPMS_ACCR_COUNT_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ACCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_COUNT_TYPE]

//>> SET_[CPMS_ACCR_COUNT_ENABLE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_ENABLE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_COUNT_ENABLE_SEL,
           CPMS_ACCR_COUNT_ENABLE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ACCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_ENABLE_SEL]

//>> SET_[CPMS_ACCR_COUNT_ENABLE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_ENABLE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_COUNT_ENABLE_SEL,
           CPMS_ACCR_COUNT_ENABLE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ACCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_ENABLE_SEL]

//>> GET_[CPMS_ACCR_COUNT_ENABLE_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ACCR_COUNT_ENABLE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.extractToRight<CPMS_ACCR_COUNT_ENABLE_SEL,
           CPMS_ACCR_COUNT_ENABLE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ACCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_COUNT_ENABLE_SEL]

//>> SET_[CPMS_ACCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_INVERT_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ACCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_INVERT_COUNT_ENABLE]

//>> SET_[CPMS_ACCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_INVERT_COUNT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_INVERT_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ACCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_INVERT_COUNT_ENABLE]

//>> SET_[CPMS_ACCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.setBit<CPMS_ACCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ACCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_INVERT_COUNT_ENABLE]

//>> CLEAR_[CPMS_ACCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ACCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.clearBit<CPMS_ACCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ACCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ACCR_INVERT_COUNT_ENABLE]

//>> GET_[CPMS_ACCR_INVERT_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ACCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.extractToRight<CPMS_ACCR_INVERT_COUNT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ACCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_INVERT_COUNT_ENABLE]

//>> GET_[CPMS_ACCR_INVERT_COUNT_ENABLE]
static inline bool GET_CPMS_ACCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.getBit<CPMS_ACCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ACCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_INVERT_COUNT_ENABLE]

//>> SET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_COUNT_ALWAYS_SAMPLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ACCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]

//>> SET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_ALWAYS_SAMPLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_COUNT_ALWAYS_SAMPLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ACCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]

//>> SET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.setBit<CPMS_ACCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ACCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]

//>> CLEAR_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ACCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.clearBit<CPMS_ACCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ACCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]

//>> GET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ACCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.extractToRight<CPMS_ACCR_COUNT_ALWAYS_SAMPLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ACCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]

//>> GET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]
static inline bool GET_CPMS_ACCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.getBit<CPMS_ACCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ACCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_COUNT_ALWAYS_SAMPLED]

//>> SET_[CPMS_ACCR_HI_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_HI_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_HI_THRESHOLD,
           CPMS_ACCR_HI_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ACCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_HI_THRESHOLD]

//>> SET_[CPMS_ACCR_HI_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_HI_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_HI_THRESHOLD,
           CPMS_ACCR_HI_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ACCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_HI_THRESHOLD]

//>> GET_[CPMS_ACCR_HI_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ACCR_HI_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.extractToRight<CPMS_ACCR_HI_THRESHOLD,
           CPMS_ACCR_HI_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ACCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_HI_THRESHOLD]

//>> SET_[CPMS_ACCR_LO_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_LO_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_LO_THRESHOLD,
           CPMS_ACCR_LO_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ACCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_LO_THRESHOLD]

//>> SET_[CPMS_ACCR_LO_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_LO_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_LO_THRESHOLD,
           CPMS_ACCR_LO_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ACCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_LO_THRESHOLD]

//>> GET_[CPMS_ACCR_LO_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ACCR_LO_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.extractToRight<CPMS_ACCR_LO_THRESHOLD,
           CPMS_ACCR_LO_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ACCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_LO_THRESHOLD]

//>> SET_[CPMS_ACCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_SPARE,
           CPMS_ACCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ACCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_SPARE]

//>> SET_[CPMS_ACCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ACCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return o_data.insertFromRight<CPMS_ACCR_SPARE,
           CPMS_ACCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ACCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ACCR_SPARE]

//>> GET_[CPMS_ACCR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ACCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ACCR));
#endif
    return i_data.extractToRight<CPMS_ACCR_SPARE,
           CPMS_ACCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ACCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ACCR_SPARE]

//>> PREP_[CPMS_MMAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_MMAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_MMAR]

//>> GET_[CPMS_MMAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_MMAR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMAR;
#endif
    return fapi2::getScom(i_target, CPMS_MMAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_MMAR]

//>> PUT_[CPMS_MMAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_MMAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_MMAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_MMAR]

//>> PREP_[CPMS_MMAR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_MMAR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMAR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_MMAR_SCOM2]

//>> GET_[CPMS_MMAR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_MMAR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMAR_SCOM2;
#endif
    return fapi2::getScom(i_target, CPMS_MMAR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_MMAR_SCOM2]

//>> PUT_[CPMS_MMAR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_MMAR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_MMAR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_MMAR_SCOM2]

//>> PREP_[CPMS_MMAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_MMAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMAR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_MMAR_WO_CLEAR]

//>> GET_[CPMS_MMAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_MMAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMAR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_MMAR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_MMAR_WO_CLEAR]

//>> PUT_[CPMS_MMAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_MMAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_MMAR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_MMAR_WO_CLEAR]


//>> SET_[CPMS_MMAR_AVAILABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_AVAILABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMAR_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_AVAILABLE]

//>> SET_[CPMS_MMAR_AVAILABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_AVAILABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_AVAILABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMAR_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_AVAILABLE]

//>> SET_[CPMS_MMAR_AVAILABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_AVAILABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_MMAR_AVAILABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMAR_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_AVAILABLE]

//>> CLEAR_[CPMS_MMAR_AVAILABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMAR_AVAILABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_MMAR_AVAILABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMAR_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMAR_AVAILABLE]

//>> GET_[CPMS_MMAR_AVAILABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_MMAR_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_MMAR_AVAILABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMAR_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_AVAILABLE]

//>> GET_[CPMS_MMAR_AVAILABLE]
static inline bool GET_CPMS_MMAR_AVAILABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_MMAR_AVAILABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMAR_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_AVAILABLE]

//>> SET_[CPMS_MMAR_FUNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_FUNC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_FUNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMAR_FUNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_FUNC_RESET]

//>> SET_[CPMS_MMAR_FUNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_FUNC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_FUNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMAR_FUNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_FUNC_RESET]

//>> SET_[CPMS_MMAR_FUNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_FUNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_MMAR_FUNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMAR_FUNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_FUNC_RESET]

//>> CLEAR_[CPMS_MMAR_FUNC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMAR_FUNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_MMAR_FUNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMAR_FUNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMAR_FUNC_RESET]

//>> GET_[CPMS_MMAR_FUNC_RESET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_MMAR_FUNC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_MMAR_FUNC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMAR_FUNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_FUNC_RESET]

//>> GET_[CPMS_MMAR_FUNC_RESET]
static inline bool GET_CPMS_MMAR_FUNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_MMAR_FUNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMAR_FUNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_FUNC_RESET]

//>> SET_[CPMS_MMAR_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_LIMIT,
           CPMS_MMAR_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMAR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_LIMIT]

//>> SET_[CPMS_MMAR_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_LIMIT,
           CPMS_MMAR_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMAR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_LIMIT]

//>> GET_[CPMS_MMAR_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_MMAR_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_MMAR_LIMIT,
           CPMS_MMAR_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMAR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_LIMIT]

//>> SET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_LIMIT_UPDATE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_LIMIT_UPDATE_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMAR_LIMIT_UPDATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]

//>> SET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_LIMIT_UPDATE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_LIMIT_UPDATE_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMAR_LIMIT_UPDATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]

//>> SET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_LIMIT_UPDATE_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_MMAR_LIMIT_UPDATE_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMAR_LIMIT_UPDATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]

//>> CLEAR_[CPMS_MMAR_LIMIT_UPDATE_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMAR_LIMIT_UPDATE_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_MMAR_LIMIT_UPDATE_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMAR_LIMIT_UPDATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMAR_LIMIT_UPDATE_SELECT]

//>> GET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_MMAR_LIMIT_UPDATE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_MMAR_LIMIT_UPDATE_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMAR_LIMIT_UPDATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]

//>> GET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]
static inline bool GET_CPMS_MMAR_LIMIT_UPDATE_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_MMAR_LIMIT_UPDATE_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMAR_LIMIT_UPDATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_LIMIT_UPDATE_SELECT]

//>> SET_[CPMS_MMAR_DIRTY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_DIRTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_DIRTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMAR_DIRTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_DIRTY]

//>> SET_[CPMS_MMAR_DIRTY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_DIRTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_MMAR_DIRTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMAR_DIRTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_DIRTY]

//>> SET_[CPMS_MMAR_DIRTY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMAR_DIRTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_MMAR_DIRTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMAR_DIRTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMAR_DIRTY]

//>> CLEAR_[CPMS_MMAR_DIRTY]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMAR_DIRTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_MMAR_DIRTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMAR_DIRTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMAR_DIRTY]

//>> GET_[CPMS_MMAR_DIRTY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_MMAR_DIRTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_MMAR_DIRTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMAR_DIRTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_DIRTY]

//>> GET_[CPMS_MMAR_DIRTY]
static inline bool GET_CPMS_MMAR_DIRTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMAR, CPMS_MMAR_SCOM2, CPMS_MMAR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_MMAR_DIRTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMAR_DIRTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMAR_DIRTY]

//>> PREP_[CPMS_SDSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_SDSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_SDSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_SDSR]

//>> GET_[CPMS_SDSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_SDSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_SDSR;
#endif
    return fapi2::getScom(i_target, CPMS_SDSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_SDSR]

//>> PUT_[CPMS_SDSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_SDSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return fapi2::putScom(i_target, CPMS_SDSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_SDSR]


//>> SET_[CPMS_SDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_DDS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<CPMS_SDSR_DDS_DATA,
           CPMS_SDSR_DDS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_SDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_DDS_DATA]

//>> SET_[CPMS_SDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_DDS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<CPMS_SDSR_DDS_DATA,
           CPMS_SDSR_DDS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_SDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_DDS_DATA]

//>> GET_[CPMS_SDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& GET_CPMS_SDSR_DDS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<CPMS_SDSR_DDS_DATA,
           CPMS_SDSR_DDS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_SDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_SDSR_DDS_DATA]

//>> SET_[CPMS_SDSR_DDS_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_DDS_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<CPMS_SDSR_DDS_MIN,
           CPMS_SDSR_DDS_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_SDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_DDS_MIN]

//>> SET_[CPMS_SDSR_DDS_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_DDS_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<CPMS_SDSR_DDS_MIN,
           CPMS_SDSR_DDS_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_SDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_DDS_MIN]

//>> GET_[CPMS_SDSR_DDS_MIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_SDSR_DDS_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<CPMS_SDSR_DDS_MIN,
           CPMS_SDSR_DDS_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_SDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_SDSR_DDS_MIN]

//>> SET_[CPMS_SDSR_DDS_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_DDS_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<CPMS_SDSR_DDS_MAX,
           CPMS_SDSR_DDS_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_SDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_DDS_MAX]

//>> SET_[CPMS_SDSR_DDS_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_DDS_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<CPMS_SDSR_DDS_MAX,
           CPMS_SDSR_DDS_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_SDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_DDS_MAX]

//>> GET_[CPMS_SDSR_DDS_MAX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_SDSR_DDS_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<CPMS_SDSR_DDS_MAX,
           CPMS_SDSR_DDS_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_SDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_SDSR_DDS_MAX]

//>> SET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<CPMS_SDSR_SAMPLE_DISABLE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<CPMS_SDSR_SAMPLE_DISABLE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.setBit<CPMS_SDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> CLEAR_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.clearBit<CPMS_SDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> GET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<CPMS_SDSR_SAMPLE_DISABLE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> GET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline bool GET_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.getBit<CPMS_SDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> PREP_[EC_PC_COMMON_SPR_SCOMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_SCOMD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SCOMD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_SCOMD]

//>> GET_[EC_PC_COMMON_SPR_SCOMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_SCOMD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SCOMD;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_SCOMD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SCOMD]

//>> PUT_[EC_PC_COMMON_SPR_SCOMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_SCOMD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SCOMD));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_SCOMD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_SCOMD]


//>> PREP_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_TFAC_HOLD_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_TFAC_HOLD_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_TFAC_HOLD_OUT;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_TFAC_HOLD_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]

//>> PUT_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_TFAC_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_TFAC_HOLD_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]


//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> PREP_[EC_PC_PWM_EVENTS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PWM_EVENTS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PWM_EVENTS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PWM_EVENTS]

//>> GET_[EC_PC_PWM_EVENTS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PWM_EVENTS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PWM_EVENTS;
#endif
    return fapi2::getScom(i_target, EC_PC_PWM_EVENTS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS]

//>> PUT_[EC_PC_PWM_EVENTS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PWM_EVENTS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return fapi2::putScom(i_target, EC_PC_PWM_EVENTS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PWM_EVENTS]


//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.setBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]

//>> CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.clearBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]
static inline bool GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.getBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32]

//>> SET_[EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD,
           EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD,
           EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD]

//>> GET_[EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD,
           EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.setBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]

//>> CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.clearBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]
static inline bool GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.getBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40]

//>> SET_[EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD,
           EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD,
           EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD]

//>> GET_[EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD,
           EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.setBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]

//>> CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.clearBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]
static inline bool GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.getBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48]

//>> SET_[EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD,
           EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD,
           EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD]

//>> GET_[EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD,
           EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.setBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]

//>> CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.clearBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]
static inline bool GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.getBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52]

//>> SET_[EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD,
           EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD,
           EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD]

//>> GET_[EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD,
           EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.setBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]

//>> CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.clearBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]
static inline bool GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.getBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.setBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]

//>> CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.clearBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]
static inline bool GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.getBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57]

//>> SET_[EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS,
           EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS]

//>> SET_[EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS,
           EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS]

//>> GET_[EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS,
           EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.setBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]

//>> CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.clearBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]
static inline bool GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.getBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]

//>> SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.setBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]

//>> CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.clearBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]

//>> GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]
static inline bool GET_EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.getBit<EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61]

//>> SET_[EC_PC_PWM_EVENTS_PMCM_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PMCM_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PMCM_THRESHOLD,
           EC_PC_PWM_EVENTS_PMCM_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PWM_EVENTS_PMCM_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PMCM_THRESHOLD]

//>> SET_[EC_PC_PWM_EVENTS_PMCM_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PWM_EVENTS_PMCM_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return o_data.insertFromRight<EC_PC_PWM_EVENTS_PMCM_THRESHOLD,
           EC_PC_PWM_EVENTS_PMCM_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PWM_EVENTS_PMCM_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PWM_EVENTS_PMCM_THRESHOLD]

//>> GET_[EC_PC_PWM_EVENTS_PMCM_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PWM_EVENTS_PMCM_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PWM_EVENTS));
#endif
    return i_data.extractToRight<EC_PC_PWM_EVENTS_PMCM_THRESHOLD,
           EC_PC_PWM_EVENTS_PMCM_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PWM_EVENTS_PMCM_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PWM_EVENTS_PMCM_THRESHOLD]

//>> PREP_[EC_PC_TRACE1_TR_TR0_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE1_TR_TR0_CONFIG_0]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_CONFIG_0;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR_TR0_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_0]

//>> PUT_[EC_PC_TRACE1_TR_TR0_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_0));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR_TR0_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE1_TR_TR0_CONFIG_0]


//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_0));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> PREP_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG]

//>> PUT_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG]


//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> PREP_[L2_L2MISC_L2CERRS_ERR_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_ERR_INJ_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_ERR_INJ_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_ERR_INJ_REG]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_ERR_INJ_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_ERR_INJ_REG;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_ERR_INJ_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG]

//>> PUT_[L2_L2MISC_L2CERRS_ERR_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_ERR_INJ_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_ERR_INJ_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_ERR_INJ_REG]


//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE,
           L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]

//>> SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]

//>> GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN]

//>> PREP_[L2TRA_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR0_TRACE_LO_DATA_REG]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG]

//>> PUT_[L2TRA_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR0_TRACE_LO_DATA_REG]


//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA,
           L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA,
           L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA,
           L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS,
           L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS,
           L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS,
           L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> CLEAR_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline bool GET_L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> CLEAR_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline bool GET_L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> CLEAR_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline bool GET_L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> SET_[L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> GET_[L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> PREP_[L2TRA_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR0_CONFIG]

//>> GET_[L2TRA_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG]

//>> PUT_[L2TRA_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR0_CONFIG]


//>> SET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> CLEAR_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline bool GET_L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> CLEAR_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline bool GET_L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE,
           L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE,
           L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> GET_[L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE,
           L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[L2TRA_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_BANK_MODE]

//>> SET_[L2TRA_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_BANK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_BANK_MODE]

//>> SET_[L2TRA_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_BANK_MODE]

//>> CLEAR_[L2TRA_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_BANK_MODE]

//>> GET_[L2TRA_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_BANK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_BANK_MODE]

//>> GET_[L2TRA_TR0_CONFIG_BANK_MODE]
static inline bool GET_L2TRA_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_BANK_MODE]

//>> SET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_ENH_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]

//>> CLEAR_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]

//>> GET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_ENH_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]

//>> GET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]
static inline bool GET_L2TRA_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> GET_[L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL,
           L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL,
           L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> GET_[L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL,
           L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> CLEAR_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline bool GET_L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]

//>> CLEAR_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]

//>> GET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]

//>> GET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]
static inline bool GET_L2TRA_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_STICKY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]

//>> CLEAR_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]

//>> GET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]

//>> GET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]
static inline bool GET_L2TRA_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> CLEAR_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline bool GET_L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> CLEAR_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> GET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> GET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline bool GET_L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> CLEAR_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline bool GET_L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> SET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> SET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> CLEAR_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> GET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> GET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline bool GET_L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> PREP_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG]

//>> GET_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG]

//>> PUT_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG]


//>> SET_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG,
           L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG,
           L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG]

//>> GET_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG,
           L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG]

//>> PREP_[NC_NCMISC_NCSCOMS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_FIR_REG_RW]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_RW]

//>> PUT_[NC_NCMISC_NCSCOMS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_FIR_REG_RW]

//>> PREP_[NC_NCMISC_NCSCOMS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_FIR_REG_WO_AND]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_WO_AND]

//>> PUT_[NC_NCMISC_NCSCOMS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_FIR_REG_WO_AND]

//>> PREP_[NC_NCMISC_NCSCOMS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_FIR_REG_WO_OR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_WO_OR]

//>> PUT_[NC_NCMISC_NCSCOMS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_FIR_REG_WO_OR]


//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SYNC_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1,
           NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1,
           NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1,
           NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR1]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]

//>> CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]
static inline bool GET_NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR,
           NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR]

//>> SET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR,
           NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR]

//>> GET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_REG_RW, NC_NCMISC_NCSCOMS_FIR_REG_WO_AND,
                           NC_NCMISC_NCSCOMS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR,
           NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_FIR_REG_SPARE_FIR]

//>> PREP_[NC_NCMISC_NCSCOMS_NCU_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_NCU_MODE_REG]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_MODE_REG;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG]

//>> PUT_[NC_NCMISC_NCSCOMS_NCU_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_NCU_MODE_REG]


//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
