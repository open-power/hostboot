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

//>> PREP_[EC_LS_LSU_HOLD_OUT_REG10]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG10(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG10;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_LS_LSU_HOLD_OUT_REG10]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG10(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG10;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG10, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10]

//>> PUT_[EC_LS_LSU_HOLD_OUT_REG10]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG10(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG10, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_LS_LSU_HOLD_OUT_REG10]


//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
SET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
CLEAR_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_CORECHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_LD0_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG10));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG10_LD1_ACC_LLQ_RF_PERR_NRECOV_SYSCHKSTOP_HOLD_OUT]

//>> PREP_[EC_LS_LSU_HOLD_OUT_REG6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_LS_LSU_HOLD_OUT_REG6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG6;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6]

//>> PUT_[EC_LS_LSU_HOLD_OUT_REG6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG6(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_LS_LSU_HOLD_OUT_REG6]


//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG6));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT]

//>> PREP_[EC_PC_SCR4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SCR4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_SCR4]

//>> GET_[EC_PC_SCR4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SCR4(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR4;
#endif
    return fapi2::getScom(i_target, EC_PC_SCR4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_SCR4]

//>> PUT_[EC_PC_SCR4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SCR4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SCR4));
#endif
    return fapi2::putScom(i_target, EC_PC_SCR4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_SCR4]


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

//>> PREP_[EC_PC_TOD_SYNC010]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_SYNC010(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC010;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TOD_SYNC010]

//>> GET_[EC_PC_TOD_SYNC010]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_SYNC010(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC010;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_SYNC010, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TOD_SYNC010]

//>> PUT_[EC_PC_TOD_SYNC010]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_SYNC010(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC010));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_SYNC010, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TOD_SYNC010]


//>> SET_[EC_PC_TOD_SYNC010_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC010_TOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC010));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC010_TOD,
           EC_PC_TOD_SYNC010_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_SYNC010_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC010_TOD]

//>> SET_[EC_PC_TOD_SYNC010_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC010_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC010));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC010_TOD,
           EC_PC_TOD_SYNC010_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_SYNC010_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC010_TOD]

//>> GET_[EC_PC_TOD_SYNC010_TOD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC010_TOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC010));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC010_TOD,
           EC_PC_TOD_SYNC010_TOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_SYNC010_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_SYNC010_TOD]

//>> SET_[EC_PC_TOD_SYNC010_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC010_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC010));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC010_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC010_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_SYNC010_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC010_CHIP_TOD_STATUS]

//>> SET_[EC_PC_TOD_SYNC010_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC010_CHIP_TOD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC010));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC010_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC010_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_SYNC010_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC010_CHIP_TOD_STATUS]

//>> GET_[EC_PC_TOD_SYNC010_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC010_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC010));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC010_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC010_CHIP_TOD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_SYNC010_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_SYNC010_CHIP_TOD_STATUS]

//>> PREP_[EC_PC_TOD_SYNC101]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_SYNC101(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC101;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TOD_SYNC101]

//>> GET_[EC_PC_TOD_SYNC101]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_SYNC101(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC101;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_SYNC101, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TOD_SYNC101]

//>> PUT_[EC_PC_TOD_SYNC101]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_SYNC101(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC101));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_SYNC101, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TOD_SYNC101]


//>> SET_[EC_PC_TOD_SYNC101_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC101_TOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC101));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC101_TOD,
           EC_PC_TOD_SYNC101_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_SYNC101_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC101_TOD]

//>> SET_[EC_PC_TOD_SYNC101_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC101_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC101));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC101_TOD,
           EC_PC_TOD_SYNC101_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_SYNC101_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC101_TOD]

//>> GET_[EC_PC_TOD_SYNC101_TOD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC101_TOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC101));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC101_TOD,
           EC_PC_TOD_SYNC101_TOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_SYNC101_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_SYNC101_TOD]

//>> SET_[EC_PC_TOD_SYNC101_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC101_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC101));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC101_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC101_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_SYNC101_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC101_CHIP_TOD_STATUS]

//>> SET_[EC_PC_TOD_SYNC101_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC101_CHIP_TOD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC101));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC101_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC101_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_SYNC101_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC101_CHIP_TOD_STATUS]

//>> GET_[EC_PC_TOD_SYNC101_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC101_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC101));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC101_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC101_CHIP_TOD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_SYNC101_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_SYNC101_CHIP_TOD_STATUS]

//>> PREP_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG]

//>> PUT_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG]


//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline bool GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline bool GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline bool GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> PREP_[L2_L2MISC_L2CERRS_ERR_RPT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_ERR_RPT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_ERR_RPT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_ERR_RPT0]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_ERR_RPT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_ERR_RPT0;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_ERR_RPT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0]

//>> PUT_[L2_L2MISC_L2CERRS_ERR_RPT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_ERR_RPT0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_ERR_RPT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_ERR_RPT0]


//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]

//>> SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]

//>> GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR]

//>> PREP_[L2_L2MISC_L2CERRS_MODE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_MODE_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_MODE_REG1]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_MODE_REG1;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_MODE_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1]

//>> PUT_[L2_L2MISC_L2CERRS_MODE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_MODE_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_MODE_REG1]


//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]

//>> CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]
static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]

//>> CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]
static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE,
           L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE,
           L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE,
           L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV,
           L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV,
           L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV,
           L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV,
           L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV,
           L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV,
           L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1,
           L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1,
           L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1,
           L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]

//>> CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]
static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2,
           L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2,
           L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2,
           L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE,
           L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE,
           L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE,
           L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]

//>> CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]
static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]

//>> CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]
static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]

//>> CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]
static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM,
           L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM]

//>> SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM,
           L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM]

//>> GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM,
           L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM]

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

//>> PREP_[L2TRA_TR1_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR1_TRACE_HI_DATA_REG]

//>> GET_[L2TRA_TR1_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR1_TRACE_HI_DATA_REG]

//>> PUT_[L2TRA_TR1_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR1_TRACE_HI_DATA_REG]


//>> SET_[L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> SET_[L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> GET_[L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> PREP_[L2TRA_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR1_CONFIG_2]

//>> GET_[L2TRA_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_2;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_2]

//>> PUT_[L2TRA_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_2));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR1_CONFIG_2]


//>> SET_[L2TRA_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_2_A,
           L2TRA_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_2_A]

//>> SET_[L2TRA_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_2_A,
           L2TRA_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_2_A]

//>> GET_[L2TRA_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_2_A,
           L2TRA_TR1_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_2_A]

//>> SET_[L2TRA_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_2_B,
           L2TRA_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_2_B]

//>> SET_[L2TRA_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_2_B,
           L2TRA_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_2_B]

//>> GET_[L2TRA_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_2_B,
           L2TRA_TR1_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_2_B]

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

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> PREP_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG]

//>> PUT_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG]


//>> SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR,
           NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR,
           NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR,
           NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
