/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00002.H $            */
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

#ifndef __C_REG00002_H_
#define __C_REG00002_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_DTIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DTIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DTIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DTIR]

//>> GET_[CPMS_DTIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DTIR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DTIR;
#endif
    return fapi2::getScom(i_target, CPMS_DTIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DTIR]

//>> PUT_[CPMS_DTIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DTIR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return fapi2::putScom(i_target, CPMS_DTIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DTIR]


//>> SET_[CPMS_DTIR_VALID]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTIR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_VALID]

//>> SET_[CPMS_DTIR_VALID]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTIR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_VALID]

//>> SET_[CPMS_DTIR_VALID]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.setBit<CPMS_DTIR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DTIR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_VALID]

//>> CLEAR_[CPMS_DTIR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DTIR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.clearBit<CPMS_DTIR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DTIR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DTIR_VALID]

//>> GET_[CPMS_DTIR_VALID]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTIR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return i_data.extractToRight<CPMS_DTIR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTIR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTIR_VALID]

//>> GET_[CPMS_DTIR_VALID]
static inline bool GET_CPMS_DTIR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return i_data.getBit<CPMS_DTIR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DTIR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTIR_VALID]

//>> SET_[CPMS_DTIR_THREAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_THREAD_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_THREAD_SEL,
           CPMS_DTIR_THREAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTIR_THREAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_THREAD_SEL]

//>> SET_[CPMS_DTIR_THREAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_THREAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_THREAD_SEL,
           CPMS_DTIR_THREAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTIR_THREAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_THREAD_SEL]

//>> GET_[CPMS_DTIR_THREAD_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTIR_THREAD_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return i_data.extractToRight<CPMS_DTIR_THREAD_SEL,
           CPMS_DTIR_THREAD_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTIR_THREAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTIR_THREAD_SEL]

//>> SET_[CPMS_DTIR_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_MODE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_MODE_SEL,
           CPMS_DTIR_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTIR_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_MODE_SEL]

//>> SET_[CPMS_DTIR_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_MODE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_MODE_SEL,
           CPMS_DTIR_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTIR_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_MODE_SEL]

//>> GET_[CPMS_DTIR_MODE_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTIR_MODE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return i_data.extractToRight<CPMS_DTIR_MODE_SEL,
           CPMS_DTIR_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTIR_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTIR_MODE_SEL]

//>> SET_[CPMS_DTIR_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_VALUE,
           CPMS_DTIR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTIR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_VALUE]

//>> SET_[CPMS_DTIR_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_VALUE,
           CPMS_DTIR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTIR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_VALUE]

//>> GET_[CPMS_DTIR_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTIR_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return i_data.extractToRight<CPMS_DTIR_VALUE,
           CPMS_DTIR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTIR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTIR_VALUE]

//>> SET_[CPMS_DTIR_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_WINDOW_SEL,
           CPMS_DTIR_WINDOW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTIR_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_WINDOW_SEL]

//>> SET_[CPMS_DTIR_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTIR_WINDOW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return o_data.insertFromRight<CPMS_DTIR_WINDOW_SEL,
           CPMS_DTIR_WINDOW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTIR_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTIR_WINDOW_SEL]

//>> GET_[CPMS_DTIR_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTIR_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTIR));
#endif
    return i_data.extractToRight<CPMS_DTIR_WINDOW_SEL,
           CPMS_DTIR_WINDOW_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTIR_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTIR_WINDOW_SEL]

//>> PREP_[CPMS_FMMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FMMR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FMMR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FMMR_RW]

//>> GET_[CPMS_FMMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FMMR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FMMR_RW;
#endif
    return fapi2::getScom(i_target, CPMS_FMMR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FMMR_RW]

//>> PUT_[CPMS_FMMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FMMR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FMMR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FMMR_RW]

//>> PREP_[CPMS_FMMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FMMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FMMR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FMMR_WO_CLEAR]

//>> GET_[CPMS_FMMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FMMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FMMR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_FMMR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FMMR_WO_CLEAR]

//>> PUT_[CPMS_FMMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FMMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FMMR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FMMR_WO_CLEAR]

//>> PREP_[CPMS_FMMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FMMR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FMMR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FMMR_WO_OR]

//>> GET_[CPMS_FMMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FMMR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FMMR_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_FMMR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FMMR_WO_OR]

//>> PUT_[CPMS_FMMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FMMR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FMMR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FMMR_WO_OR]


//>> SET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_STAGGER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_STAGGER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]

//>> SET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_STAGGER_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_STAGGER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]

//>> SET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_STAGGER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_SMALL_STAGGER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]

//>> CLEAR_[CPMS_FMMR_SMALL_STAGGER_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_SMALL_STAGGER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_SMALL_STAGGER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_SMALL_STAGGER_ENABLE]

//>> GET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_STAGGER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_STAGGER_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]

//>> GET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]
static inline bool GET_CPMS_FMMR_SMALL_STAGGER_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_SMALL_STAGGER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_STAGGER_ENABLE]

//>> SET_[CPMS_FMMR_SMALL_STAGGER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_STAGGER_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_STAGGER_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_STAGGER_SELECT]

//>> SET_[CPMS_FMMR_SMALL_STAGGER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_STAGGER_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_STAGGER_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_STAGGER_SELECT]

//>> SET_[CPMS_FMMR_SMALL_STAGGER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_STAGGER_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_SMALL_STAGGER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_STAGGER_SELECT]

//>> CLEAR_[CPMS_FMMR_SMALL_STAGGER_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_SMALL_STAGGER_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_SMALL_STAGGER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_SMALL_STAGGER_SELECT]

//>> GET_[CPMS_FMMR_SMALL_STAGGER_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_STAGGER_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_STAGGER_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_STAGGER_SELECT]

//>> GET_[CPMS_FMMR_SMALL_STAGGER_SELECT]
static inline bool GET_CPMS_FMMR_SMALL_STAGGER_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_SMALL_STAGGER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_STAGGER_SELECT]

//>> SET_[CPMS_FMMR_SMALL_STAGGER_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_STAGGER_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_STAGGER_CYCLES,
           CPMS_FMMR_SMALL_STAGGER_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_STAGGER_CYCLES]

//>> SET_[CPMS_FMMR_SMALL_STAGGER_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_STAGGER_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_STAGGER_CYCLES,
           CPMS_FMMR_SMALL_STAGGER_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_STAGGER_CYCLES]

//>> GET_[CPMS_FMMR_SMALL_STAGGER_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_STAGGER_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_STAGGER_CYCLES,
           CPMS_FMMR_SMALL_STAGGER_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_STAGGER_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_STAGGER_CYCLES]

//>> SET_[CPMS_FMMR_ADJ_WARN_WEIGHT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_ADJ_WARN_WEIGHT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_ADJ_WARN_WEIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_WEIGHT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_ADJ_WARN_WEIGHT]

//>> SET_[CPMS_FMMR_ADJ_WARN_WEIGHT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_ADJ_WARN_WEIGHT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_ADJ_WARN_WEIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_WEIGHT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_ADJ_WARN_WEIGHT]

//>> SET_[CPMS_FMMR_ADJ_WARN_WEIGHT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_ADJ_WARN_WEIGHT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_ADJ_WARN_WEIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_WEIGHT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_ADJ_WARN_WEIGHT]

//>> CLEAR_[CPMS_FMMR_ADJ_WARN_WEIGHT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_ADJ_WARN_WEIGHT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_ADJ_WARN_WEIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_WEIGHT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_ADJ_WARN_WEIGHT]

//>> GET_[CPMS_FMMR_ADJ_WARN_WEIGHT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_ADJ_WARN_WEIGHT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_ADJ_WARN_WEIGHT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_WEIGHT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_ADJ_WARN_WEIGHT]

//>> GET_[CPMS_FMMR_ADJ_WARN_WEIGHT]
static inline bool GET_CPMS_FMMR_ADJ_WARN_WEIGHT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_ADJ_WARN_WEIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_WEIGHT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_ADJ_WARN_WEIGHT]

//>> SET_[CPMS_FMMR_ADJ_WARN_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_ADJ_WARN_RESPONSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_ADJ_WARN_RESPONSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_ADJ_WARN_RESPONSE]

//>> SET_[CPMS_FMMR_ADJ_WARN_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_ADJ_WARN_RESPONSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_ADJ_WARN_RESPONSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_ADJ_WARN_RESPONSE]

//>> SET_[CPMS_FMMR_ADJ_WARN_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_ADJ_WARN_RESPONSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_ADJ_WARN_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_ADJ_WARN_RESPONSE]

//>> CLEAR_[CPMS_FMMR_ADJ_WARN_RESPONSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_ADJ_WARN_RESPONSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_ADJ_WARN_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_ADJ_WARN_RESPONSE]

//>> GET_[CPMS_FMMR_ADJ_WARN_RESPONSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_ADJ_WARN_RESPONSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_ADJ_WARN_RESPONSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_ADJ_WARN_RESPONSE]

//>> GET_[CPMS_FMMR_ADJ_WARN_RESPONSE]
static inline bool GET_CPMS_FMMR_ADJ_WARN_RESPONSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_ADJ_WARN_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_ADJ_WARN_RESPONSE]

//>> SET_[CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT,
           CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT]

//>> SET_[CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT,
           CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT]

//>> GET_[CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT,
           CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT]

//>> SET_[CPMS_FMMR_DDP_TRIP_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DDP_TRIP_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DDP_TRIP_SELECT,
           CPMS_FMMR_DDP_TRIP_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_DDP_TRIP_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DDP_TRIP_SELECT]

//>> SET_[CPMS_FMMR_DDP_TRIP_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DDP_TRIP_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DDP_TRIP_SELECT,
           CPMS_FMMR_DDP_TRIP_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_DDP_TRIP_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DDP_TRIP_SELECT]

//>> GET_[CPMS_FMMR_DDP_TRIP_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_DDP_TRIP_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_DDP_TRIP_SELECT,
           CPMS_FMMR_DDP_TRIP_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_DDP_TRIP_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_DDP_TRIP_SELECT]

//>> SET_[CPMS_FMMR_SLOPEA_TYPE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPEA_TYPE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SLOPEA_TYPE_SELECT,
           CPMS_FMMR_SLOPEA_TYPE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SLOPEA_TYPE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPEA_TYPE_SELECT]

//>> SET_[CPMS_FMMR_SLOPEA_TYPE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPEA_TYPE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SLOPEA_TYPE_SELECT,
           CPMS_FMMR_SLOPEA_TYPE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SLOPEA_TYPE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPEA_TYPE_SELECT]

//>> GET_[CPMS_FMMR_SLOPEA_TYPE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SLOPEA_TYPE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SLOPEA_TYPE_SELECT,
           CPMS_FMMR_SLOPEA_TYPE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SLOPEA_TYPE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SLOPEA_TYPE_SELECT]

//>> SET_[CPMS_FMMR_SLOPEB_TYPE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPEB_TYPE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SLOPEB_TYPE_SELECT,
           CPMS_FMMR_SLOPEB_TYPE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SLOPEB_TYPE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPEB_TYPE_SELECT]

//>> SET_[CPMS_FMMR_SLOPEB_TYPE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPEB_TYPE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SLOPEB_TYPE_SELECT,
           CPMS_FMMR_SLOPEB_TYPE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SLOPEB_TYPE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPEB_TYPE_SELECT]

//>> GET_[CPMS_FMMR_SLOPEB_TYPE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SLOPEB_TYPE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SLOPEB_TYPE_SELECT,
           CPMS_FMMR_SLOPEB_TYPE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SLOPEB_TYPE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SLOPEB_TYPE_SELECT]

//>> SET_[CPMS_FMMR_SMALL_ASSERT_STABILITY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_ASSERT_STABILITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_ASSERT_STABILITY,
           CPMS_FMMR_SMALL_ASSERT_STABILITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_ASSERT_STABILITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_ASSERT_STABILITY]

//>> SET_[CPMS_FMMR_SMALL_ASSERT_STABILITY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_ASSERT_STABILITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_ASSERT_STABILITY,
           CPMS_FMMR_SMALL_ASSERT_STABILITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_ASSERT_STABILITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_ASSERT_STABILITY]

//>> GET_[CPMS_FMMR_SMALL_ASSERT_STABILITY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_ASSERT_STABILITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_ASSERT_STABILITY,
           CPMS_FMMR_SMALL_ASSERT_STABILITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_ASSERT_STABILITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_ASSERT_STABILITY]

//>> SET_[CPMS_FMMR_SMALL_DEASSERT_STABILITY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DEASSERT_STABILITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DEASSERT_STABILITY,
           CPMS_FMMR_SMALL_DEASSERT_STABILITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_DEASSERT_STABILITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DEASSERT_STABILITY]

//>> SET_[CPMS_FMMR_SMALL_DEASSERT_STABILITY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DEASSERT_STABILITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DEASSERT_STABILITY,
           CPMS_FMMR_SMALL_DEASSERT_STABILITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_DEASSERT_STABILITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DEASSERT_STABILITY]

//>> GET_[CPMS_FMMR_SMALL_DEASSERT_STABILITY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_DEASSERT_STABILITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_DEASSERT_STABILITY,
           CPMS_FMMR_SMALL_DEASSERT_STABILITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_DEASSERT_STABILITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_DEASSERT_STABILITY]

//>> SET_[CPMS_FMMR_SMALL_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_INITIAL_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_INITIAL_CYCLES,
           CPMS_FMMR_SMALL_INITIAL_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_INITIAL_CYCLES]

//>> SET_[CPMS_FMMR_SMALL_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_INITIAL_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_INITIAL_CYCLES,
           CPMS_FMMR_SMALL_INITIAL_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_INITIAL_CYCLES]

//>> GET_[CPMS_FMMR_SMALL_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_INITIAL_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_INITIAL_CYCLES,
           CPMS_FMMR_SMALL_INITIAL_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_INITIAL_CYCLES]

//>> SET_[CPMS_FMMR_SMALL_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_INITIAL_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_INITIAL_ACTION,
           CPMS_FMMR_SMALL_INITIAL_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_INITIAL_ACTION]

//>> SET_[CPMS_FMMR_SMALL_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_INITIAL_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_INITIAL_ACTION,
           CPMS_FMMR_SMALL_INITIAL_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_INITIAL_ACTION]

//>> GET_[CPMS_FMMR_SMALL_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_INITIAL_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_INITIAL_ACTION,
           CPMS_FMMR_SMALL_INITIAL_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_INITIAL_ACTION]

//>> SET_[CPMS_FMMR_SMALL_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_PREFETCH_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_PREFETCH_ACTION,
           CPMS_FMMR_SMALL_PREFETCH_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_PREFETCH_ACTION]

//>> SET_[CPMS_FMMR_SMALL_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_PREFETCH_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_PREFETCH_ACTION,
           CPMS_FMMR_SMALL_PREFETCH_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_PREFETCH_ACTION]

//>> GET_[CPMS_FMMR_SMALL_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_PREFETCH_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_PREFETCH_ACTION,
           CPMS_FMMR_SMALL_PREFETCH_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_PREFETCH_ACTION]

//>> SET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DITHER_WINDOW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_WINDOW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DITHER_WINDOW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_SMALL_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]

//>> CLEAR_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_SMALL_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_SMALL_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]

//>> GET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_DITHER_WINDOW_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]

//>> GET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]
static inline bool GET_CPMS_FMMR_SMALL_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_SMALL_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FMMR_SMALL_VECTOR_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_VECTOR_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_VECTOR_ACTION,
           CPMS_FMMR_SMALL_VECTOR_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_VECTOR_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_VECTOR_ACTION]

//>> SET_[CPMS_FMMR_SMALL_VECTOR_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_VECTOR_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_VECTOR_ACTION,
           CPMS_FMMR_SMALL_VECTOR_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_VECTOR_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_VECTOR_ACTION]

//>> GET_[CPMS_FMMR_SMALL_VECTOR_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_VECTOR_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_VECTOR_ACTION,
           CPMS_FMMR_SMALL_VECTOR_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_VECTOR_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_VECTOR_ACTION]

//>> SET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPE_TIMEOUT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SLOPE_TIMEOUT_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SLOPE_TIMEOUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]

//>> SET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPE_TIMEOUT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SLOPE_TIMEOUT_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SLOPE_TIMEOUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]

//>> SET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPE_TIMEOUT_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_SLOPE_TIMEOUT_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_SLOPE_TIMEOUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]

//>> CLEAR_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_SLOPE_TIMEOUT_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_SLOPE_TIMEOUT_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_SLOPE_TIMEOUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]

//>> GET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SLOPE_TIMEOUT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SLOPE_TIMEOUT_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SLOPE_TIMEOUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]

//>> GET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]
static inline bool GET_CPMS_FMMR_SLOPE_TIMEOUT_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_SLOPE_TIMEOUT_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_SLOPE_TIMEOUT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SLOPE_TIMEOUT_SELECT]

//>> SET_[CPMS_FMMR_SMALL_THROTTLE_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_THROTTLE_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_THROTTLE_ACTION,
           CPMS_FMMR_SMALL_THROTTLE_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_THROTTLE_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_THROTTLE_ACTION]

//>> SET_[CPMS_FMMR_SMALL_THROTTLE_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_THROTTLE_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_THROTTLE_ACTION,
           CPMS_FMMR_SMALL_THROTTLE_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_THROTTLE_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_THROTTLE_ACTION]

//>> GET_[CPMS_FMMR_SMALL_THROTTLE_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_THROTTLE_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_THROTTLE_ACTION,
           CPMS_FMMR_SMALL_THROTTLE_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_THROTTLE_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_THROTTLE_ACTION]

//>> SET_[CPMS_FMMR_SMALL_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_REPEAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DITHER_REPEAT,
           CPMS_FMMR_SMALL_DITHER_REPEAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_REPEAT]

//>> SET_[CPMS_FMMR_SMALL_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_REPEAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DITHER_REPEAT,
           CPMS_FMMR_SMALL_DITHER_REPEAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_REPEAT]

//>> GET_[CPMS_FMMR_SMALL_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_DITHER_REPEAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_DITHER_REPEAT,
           CPMS_FMMR_SMALL_DITHER_REPEAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_DITHER_REPEAT]

//>> SET_[CPMS_FMMR_SMALL_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_INCREASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DITHER_INCREASE,
           CPMS_FMMR_SMALL_DITHER_INCREASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_INCREASE]

//>> SET_[CPMS_FMMR_SMALL_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_INCREASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DITHER_INCREASE,
           CPMS_FMMR_SMALL_DITHER_INCREASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_INCREASE]

//>> GET_[CPMS_FMMR_SMALL_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_DITHER_INCREASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_DITHER_INCREASE,
           CPMS_FMMR_SMALL_DITHER_INCREASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_DITHER_INCREASE]

//>> SET_[CPMS_FMMR_SMALL_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_INITIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DITHER_INITIAL,
           CPMS_FMMR_SMALL_DITHER_INITIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_INITIAL]

//>> SET_[CPMS_FMMR_SMALL_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_DITHER_INITIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_DITHER_INITIAL,
           CPMS_FMMR_SMALL_DITHER_INITIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_DITHER_INITIAL]

//>> GET_[CPMS_FMMR_SMALL_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_DITHER_INITIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_DITHER_INITIAL,
           CPMS_FMMR_SMALL_DITHER_INITIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_DITHER_INITIAL]

//>> SET_[CPMS_FMMR_DPLL_DATA2_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DPLL_DATA2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DPLL_DATA2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DPLL_DATA2_SEL]

//>> SET_[CPMS_FMMR_DPLL_DATA2_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DPLL_DATA2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DPLL_DATA2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DPLL_DATA2_SEL]

//>> SET_[CPMS_FMMR_DPLL_DATA2_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DPLL_DATA2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_DPLL_DATA2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DPLL_DATA2_SEL]

//>> CLEAR_[CPMS_FMMR_DPLL_DATA2_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_DPLL_DATA2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_DPLL_DATA2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_DPLL_DATA2_SEL]

//>> GET_[CPMS_FMMR_DPLL_DATA2_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_DPLL_DATA2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_DPLL_DATA2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_DPLL_DATA2_SEL]

//>> GET_[CPMS_FMMR_DPLL_DATA2_SEL]
static inline bool GET_CPMS_FMMR_DPLL_DATA2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_DPLL_DATA2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_DPLL_DATA2_SEL]

//>> SET_[CPMS_FMMR_DPLL_DATA1_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DPLL_DATA1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DPLL_DATA1_SEL,
           CPMS_FMMR_DPLL_DATA1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DPLL_DATA1_SEL]

//>> SET_[CPMS_FMMR_DPLL_DATA1_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DPLL_DATA1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DPLL_DATA1_SEL,
           CPMS_FMMR_DPLL_DATA1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DPLL_DATA1_SEL]

//>> GET_[CPMS_FMMR_DPLL_DATA1_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_DPLL_DATA1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_DPLL_DATA1_SEL,
           CPMS_FMMR_DPLL_DATA1_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_DPLL_DATA1_SEL]

//>> SET_[CPMS_FMMR_DPLL_DATA0_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DPLL_DATA0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DPLL_DATA0_SEL,
           CPMS_FMMR_DPLL_DATA0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DPLL_DATA0_SEL]

//>> SET_[CPMS_FMMR_DPLL_DATA0_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DPLL_DATA0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DPLL_DATA0_SEL,
           CPMS_FMMR_DPLL_DATA0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DPLL_DATA0_SEL]

//>> GET_[CPMS_FMMR_DPLL_DATA0_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_DPLL_DATA0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_DPLL_DATA0_SEL,
           CPMS_FMMR_DPLL_DATA0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_DPLL_DATA0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_DPLL_DATA0_SEL]

//>> SET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]

//>> SET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]

//>> SET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]

//>> CLEAR_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]

//>> GET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]

//>> GET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]
static inline bool GET_CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE]

//>> SET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_RESPONSE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SMALL_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]

//>> SET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_RESPONSE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SMALL_RESPONSE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SMALL_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]

//>> SET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SMALL_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_SMALL_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_SMALL_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]

//>> CLEAR_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_SMALL_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_SMALL_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_SMALL_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]

//>> GET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SMALL_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SMALL_RESPONSE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SMALL_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]

//>> GET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]
static inline bool GET_CPMS_FMMR_SMALL_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_SMALL_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_SMALL_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SMALL_RESPONSE_DISABLE]

//>> SET_[CPMS_FMMR_SLOPE_REPORT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPE_REPORT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SLOPE_REPORT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_SLOPE_REPORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPE_REPORT_SEL]

//>> SET_[CPMS_FMMR_SLOPE_REPORT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPE_REPORT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_SLOPE_REPORT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_SLOPE_REPORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPE_REPORT_SEL]

//>> SET_[CPMS_FMMR_SLOPE_REPORT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_SLOPE_REPORT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FMMR_SLOPE_REPORT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FMMR_SLOPE_REPORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_SLOPE_REPORT_SEL]

//>> CLEAR_[CPMS_FMMR_SLOPE_REPORT_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FMMR_SLOPE_REPORT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FMMR_SLOPE_REPORT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FMMR_SLOPE_REPORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FMMR_SLOPE_REPORT_SEL]

//>> GET_[CPMS_FMMR_SLOPE_REPORT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_SLOPE_REPORT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_SLOPE_REPORT_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_SLOPE_REPORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SLOPE_REPORT_SEL]

//>> GET_[CPMS_FMMR_SLOPE_REPORT_SEL]
static inline bool GET_CPMS_FMMR_SLOPE_REPORT_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FMMR_SLOPE_REPORT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FMMR_SLOPE_REPORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_SLOPE_REPORT_SEL]

//>> SET_[CPMS_FMMR_OVERRIDE_VECTOR_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_OVERRIDE_VECTOR_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_OVERRIDE_VECTOR_LIMIT,
           CPMS_FMMR_OVERRIDE_VECTOR_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FMMR_OVERRIDE_VECTOR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_OVERRIDE_VECTOR_LIMIT]

//>> SET_[CPMS_FMMR_OVERRIDE_VECTOR_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FMMR_OVERRIDE_VECTOR_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FMMR_OVERRIDE_VECTOR_LIMIT,
           CPMS_FMMR_OVERRIDE_VECTOR_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FMMR_OVERRIDE_VECTOR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FMMR_OVERRIDE_VECTOR_LIMIT]

//>> GET_[CPMS_FMMR_OVERRIDE_VECTOR_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FMMR_OVERRIDE_VECTOR_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FMMR_RW, CPMS_FMMR_WO_CLEAR, CPMS_FMMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FMMR_OVERRIDE_VECTOR_LIMIT,
           CPMS_FMMR_OVERRIDE_VECTOR_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FMMR_OVERRIDE_VECTOR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FMMR_OVERRIDE_VECTOR_LIMIT]

//>> PREP_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_THRCTL_TCTLCOM_HOLD_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_HOLD_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_HOLD_OUT;
#endif
    return fapi2::getScom(i_target, EC_PC_THRCTL_TCTLCOM_HOLD_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT]

//>> PUT_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_THRCTL_TCTLCOM_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return fapi2::putScom(i_target, EC_PC_THRCTL_TCTLCOM_HOLD_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT]


//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT]

//>> PREP_[L2_L2MISC_L2CERRS_TOPOTABLE3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_TOPOTABLE3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_TOPOTABLE3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_TOPOTABLE3]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_TOPOTABLE3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_TOPOTABLE3;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_TOPOTABLE3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3]

//>> PUT_[L2_L2MISC_L2CERRS_TOPOTABLE3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_TOPOTABLE3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_TOPOTABLE3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_TOPOTABLE3]


//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_24,
           L2_L2MISC_L2CERRS_TOPOTABLE3_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_24,
           L2_L2MISC_L2CERRS_TOPOTABLE3_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_24,
           L2_L2MISC_L2CERRS_TOPOTABLE3_24_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_24]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_25,
           L2_L2MISC_L2CERRS_TOPOTABLE3_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_25,
           L2_L2MISC_L2CERRS_TOPOTABLE3_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_25,
           L2_L2MISC_L2CERRS_TOPOTABLE3_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_25]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_26,
           L2_L2MISC_L2CERRS_TOPOTABLE3_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_26,
           L2_L2MISC_L2CERRS_TOPOTABLE3_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_26,
           L2_L2MISC_L2CERRS_TOPOTABLE3_26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_26]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_27,
           L2_L2MISC_L2CERRS_TOPOTABLE3_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_27,
           L2_L2MISC_L2CERRS_TOPOTABLE3_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_27,
           L2_L2MISC_L2CERRS_TOPOTABLE3_27_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_27]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_28,
           L2_L2MISC_L2CERRS_TOPOTABLE3_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_28,
           L2_L2MISC_L2CERRS_TOPOTABLE3_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_28,
           L2_L2MISC_L2CERRS_TOPOTABLE3_28_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_28]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_29,
           L2_L2MISC_L2CERRS_TOPOTABLE3_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_29,
           L2_L2MISC_L2CERRS_TOPOTABLE3_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_29,
           L2_L2MISC_L2CERRS_TOPOTABLE3_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_29]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_30,
           L2_L2MISC_L2CERRS_TOPOTABLE3_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_30,
           L2_L2MISC_L2CERRS_TOPOTABLE3_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_30,
           L2_L2MISC_L2CERRS_TOPOTABLE3_30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_30]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_31,
           L2_L2MISC_L2CERRS_TOPOTABLE3_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE3_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE3_31,
           L2_L2MISC_L2CERRS_TOPOTABLE3_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE3_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE3));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE3_31,
           L2_L2MISC_L2CERRS_TOPOTABLE3_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE3_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE3_31]

//>> PREP_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD]

//>> PUT_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD]


//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7,
           L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7]

//>> PREP_[NC_NCCHTM_NCCHTSC_HTM_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCCHTM_NCCHTSC_HTM_MODE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_MODE;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE]

//>> PUT_[NC_NCCHTM_NCCHTSC_HTM_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCCHTM_NCCHTSC_HTM_MODE]


//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL,
           NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL,
           NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL,
           NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE,
           NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE,
           NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE,
           NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_STORE_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_LLAT_IMBEDDED_TS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_LLAT_PAUSE_ON_PURGE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CORE_CAPTURE_HOLD_ACTIVE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2,
           NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2,
           NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2,
           NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES,
           NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES,
           NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES,
           NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET,
           NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET,
           NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MODE));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET,
           NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
