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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA,
           P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA]

//>> SET_[P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA,
           P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA]

//>> GET_[P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA,
           P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_SDSR_CPMS_DDSR_DDS_DATA]

//>> SET_[CPMS_SDSR_DDS_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_DDS_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_CPMS_SDSR_DDS_MIN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_DDS_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_DDS_MIN,
           P10_20_CPMS_SDSR_DDS_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_SDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_DDS_MIN]

//>> SET_[P10_20_CPMS_SDSR_DDS_MIN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_DDS_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_DDS_MIN,
           P10_20_CPMS_SDSR_DDS_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_SDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_DDS_MIN]

//>> GET_[P10_20_CPMS_SDSR_DDS_MIN]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_SDSR_DDS_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<P10_20_CPMS_SDSR_DDS_MIN,
           P10_20_CPMS_SDSR_DDS_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_SDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_SDSR_DDS_MIN]

//>> SET_[CPMS_SDSR_DDS_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_DDS_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_CPMS_SDSR_DDS_MAX]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_DDS_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_DDS_MAX,
           P10_20_CPMS_SDSR_DDS_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_SDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_DDS_MAX]

//>> SET_[P10_20_CPMS_SDSR_DDS_MAX]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_DDS_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_DDS_MAX,
           P10_20_CPMS_SDSR_DDS_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_SDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_DDS_MAX]

//>> GET_[P10_20_CPMS_SDSR_DDS_MAX]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_SDSR_DDS_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<P10_20_CPMS_SDSR_DDS_MAX,
           P10_20_CPMS_SDSR_DDS_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_SDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_SDSR_DDS_MAX]

//>> SET_[CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.setBit<P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> CLEAR_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.clearBit<P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> GET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> GET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]
static inline bool GET_P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.getBit<P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_SDSR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_SDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]

//>> SET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_STOP_STATE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.insertFromRight<P10_20_CPMS_SDSR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_SDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]

//>> SET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_SDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.setBit<P10_20_CPMS_SDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_CPMS_SDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]

//>> CLEAR_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CPMS_SDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return o_data.clearBit<P10_20_CPMS_SDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_CPMS_SDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]

//>> GET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_SDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.extractToRight<P10_20_CPMS_SDSR_STOP_STATE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_SDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]

//>> GET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]
static inline bool GET_P10_20_CPMS_SDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_SDSR));
#endif
    return i_data.getBit<P10_20_CPMS_SDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_CPMS_SDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_SDSR_STOP_STATE_OCCURRED]

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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]

//>> CLEAR_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]
static inline bool GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]

//>> CLEAR_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]
static inline bool GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]

//>> CLEAR_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]
static inline bool GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT,
           P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT]

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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]

//>> SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]

//>> CLEAR_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]

//>> GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]
static inline bool GET_P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
