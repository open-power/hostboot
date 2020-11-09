/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00013.H $            */
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

#ifndef __C_REG00013_H_
#define __C_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_DCCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DCCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DCCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DCCR]

//>> GET_[CPMS_DCCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DCCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DCCR;
#endif
    return fapi2::getScom(i_target, CPMS_DCCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DCCR]

//>> PUT_[CPMS_DCCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DCCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return fapi2::putScom(i_target, CPMS_DCCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DCCR]


//>> SET_[CPMS_DCCR_LARGE_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_LARGE_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_LARGE_OFFSET,
           CPMS_DCCR_LARGE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DCCR_LARGE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_LARGE_OFFSET]

//>> SET_[CPMS_DCCR_LARGE_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_LARGE_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_LARGE_OFFSET,
           CPMS_DCCR_LARGE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DCCR_LARGE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_LARGE_OFFSET]

//>> GET_[CPMS_DCCR_LARGE_OFFSET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DCCR_LARGE_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return i_data.extractToRight<CPMS_DCCR_LARGE_OFFSET,
           CPMS_DCCR_LARGE_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DCCR_LARGE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DCCR_LARGE_OFFSET]

//>> SET_[CPMS_DCCR_0_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_0_THRESH_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_0_THRESH_SCALE,
           CPMS_DCCR_0_THRESH_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DCCR_0_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_0_THRESH_SCALE]

//>> SET_[CPMS_DCCR_0_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_0_THRESH_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_0_THRESH_SCALE,
           CPMS_DCCR_0_THRESH_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DCCR_0_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_0_THRESH_SCALE]

//>> GET_[CPMS_DCCR_0_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DCCR_0_THRESH_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return i_data.extractToRight<CPMS_DCCR_0_THRESH_SCALE,
           CPMS_DCCR_0_THRESH_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DCCR_0_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DCCR_0_THRESH_SCALE]

//>> SET_[CPMS_DCCR_0_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_0_THRESH_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_0_THRESH_VALUE,
           CPMS_DCCR_0_THRESH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DCCR_0_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_0_THRESH_VALUE]

//>> SET_[CPMS_DCCR_0_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_0_THRESH_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_0_THRESH_VALUE,
           CPMS_DCCR_0_THRESH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DCCR_0_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_0_THRESH_VALUE]

//>> GET_[CPMS_DCCR_0_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DCCR_0_THRESH_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return i_data.extractToRight<CPMS_DCCR_0_THRESH_VALUE,
           CPMS_DCCR_0_THRESH_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DCCR_0_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DCCR_0_THRESH_VALUE]

//>> SET_[CPMS_DCCR_1_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_1_THRESH_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_1_THRESH_SCALE,
           CPMS_DCCR_1_THRESH_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DCCR_1_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_1_THRESH_SCALE]

//>> SET_[CPMS_DCCR_1_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_1_THRESH_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_1_THRESH_SCALE,
           CPMS_DCCR_1_THRESH_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DCCR_1_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_1_THRESH_SCALE]

//>> GET_[CPMS_DCCR_1_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DCCR_1_THRESH_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return i_data.extractToRight<CPMS_DCCR_1_THRESH_SCALE,
           CPMS_DCCR_1_THRESH_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DCCR_1_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DCCR_1_THRESH_SCALE]

//>> SET_[CPMS_DCCR_1_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_1_THRESH_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_1_THRESH_VALUE,
           CPMS_DCCR_1_THRESH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DCCR_1_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_1_THRESH_VALUE]

//>> SET_[CPMS_DCCR_1_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_1_THRESH_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_1_THRESH_VALUE,
           CPMS_DCCR_1_THRESH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DCCR_1_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_1_THRESH_VALUE]

//>> GET_[CPMS_DCCR_1_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DCCR_1_THRESH_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return i_data.extractToRight<CPMS_DCCR_1_THRESH_VALUE,
           CPMS_DCCR_1_THRESH_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DCCR_1_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DCCR_1_THRESH_VALUE]

//>> SET_[CPMS_DCCR_0_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_0_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_0_EVENT_SEL,
           CPMS_DCCR_0_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DCCR_0_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_0_EVENT_SEL]

//>> SET_[CPMS_DCCR_0_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_0_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_0_EVENT_SEL,
           CPMS_DCCR_0_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DCCR_0_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_0_EVENT_SEL]

//>> GET_[CPMS_DCCR_0_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DCCR_0_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return i_data.extractToRight<CPMS_DCCR_0_EVENT_SEL,
           CPMS_DCCR_0_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DCCR_0_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DCCR_0_EVENT_SEL]

//>> SET_[CPMS_DCCR_1_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_1_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_1_EVENT_SEL,
           CPMS_DCCR_1_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DCCR_1_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_1_EVENT_SEL]

//>> SET_[CPMS_DCCR_1_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DCCR_1_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return o_data.insertFromRight<CPMS_DCCR_1_EVENT_SEL,
           CPMS_DCCR_1_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DCCR_1_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DCCR_1_EVENT_SEL]

//>> GET_[CPMS_DCCR_1_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DCCR_1_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DCCR));
#endif
    return i_data.extractToRight<CPMS_DCCR_1_EVENT_SEL,
           CPMS_DCCR_1_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DCCR_1_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DCCR_1_EVENT_SEL]

//>> PREP_[CPMS_MMA_PFETSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_MMA_PFETSTAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMA_PFETSTAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_MMA_PFETSTAT]

//>> GET_[CPMS_MMA_PFETSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_MMA_PFETSTAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMA_PFETSTAT;
#endif
    return fapi2::getScom(i_target, CPMS_MMA_PFETSTAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_MMA_PFETSTAT]

//>> PUT_[CPMS_MMA_PFETSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_MMA_PFETSTAT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return fapi2::putScom(i_target, CPMS_MMA_PFETSTAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_MMA_PFETSTAT]


//>> SET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETSTAT_S_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETSTAT_S_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_ENABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]

//>> SET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETSTAT_S_ENABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETSTAT_S_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_ENABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]

//>> SET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETSTAT_S_ENABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.setBit<CPMS_MMA_PFETSTAT_S_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_ENABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]

//>> CLEAR_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMA_PFETSTAT_S_ENABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.clearBit<CPMS_MMA_PFETSTAT_S_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_ENABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]

//>> GET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETSTAT_S_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETSTAT_S_ENABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_ENABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]

//>> GET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]
static inline bool GET_CPMS_MMA_PFETSTAT_S_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return i_data.getBit<CPMS_MMA_PFETSTAT_S_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_ENABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETSTAT_S_ENABLED_SENSE]

//>> SET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETSTAT_S_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETSTAT_S_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_DISABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]

//>> SET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETSTAT_S_DISABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETSTAT_S_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_DISABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]

//>> SET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETSTAT_S_DISABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.setBit<CPMS_MMA_PFETSTAT_S_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_DISABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]

//>> CLEAR_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMA_PFETSTAT_S_DISABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.clearBit<CPMS_MMA_PFETSTAT_S_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_DISABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]

//>> GET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETSTAT_S_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETSTAT_S_DISABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_DISABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]

//>> GET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]
static inline bool GET_CPMS_MMA_PFETSTAT_S_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return i_data.getBit<CPMS_MMA_PFETSTAT_S_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMA_PFETSTAT_S_DISABLED_SENSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETSTAT_S_DISABLED_SENSE]

//>> SET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.insertFromRight<P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]

//>> SET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.insertFromRight<P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]

//>> SET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.setBit<P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]

//>> CLEAR_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.clearBit<P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]

//>> GET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return i_data.extractToRight<P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]

//>> GET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]
static inline bool GET_P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return i_data.getBit<P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_MMA_PFETSTAT_S_FINGER0_SENSE]

//>> SET_[CPMS_MMA_PFETSTAT_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETSTAT_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETSTAT_ENABLE_ACTUAL,
           CPMS_MMA_PFETSTAT_ENABLE_ACTUAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETSTAT_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETSTAT_ENABLE_ACTUAL]

//>> SET_[CPMS_MMA_PFETSTAT_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETSTAT_ENABLE_ACTUAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETSTAT_ENABLE_ACTUAL,
           CPMS_MMA_PFETSTAT_ENABLE_ACTUAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETSTAT_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETSTAT_ENABLE_ACTUAL]

//>> GET_[CPMS_MMA_PFETSTAT_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETSTAT_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETSTAT_ENABLE_ACTUAL,
           CPMS_MMA_PFETSTAT_ENABLE_ACTUAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETSTAT_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETSTAT_ENABLE_ACTUAL]

//>> PREP_[CPMS_PFETDLY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_PFETDLY(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PFETDLY;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_PFETDLY]

//>> GET_[CPMS_PFETDLY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_PFETDLY(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PFETDLY;
#endif
    return fapi2::getScom(i_target, CPMS_PFETDLY, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_PFETDLY]

//>> PUT_[CPMS_PFETDLY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_PFETDLY(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return fapi2::putScom(i_target, CPMS_PFETDLY, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_PFETDLY]


//>> SET_[CPMS_PFETDLY_POWDN_DLY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PFETDLY_POWDN_DLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return o_data.insertFromRight<CPMS_PFETDLY_POWDN_DLY,
           CPMS_PFETDLY_POWDN_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PFETDLY_POWDN_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PFETDLY_POWDN_DLY]

//>> SET_[CPMS_PFETDLY_POWDN_DLY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PFETDLY_POWDN_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return o_data.insertFromRight<CPMS_PFETDLY_POWDN_DLY,
           CPMS_PFETDLY_POWDN_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PFETDLY_POWDN_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PFETDLY_POWDN_DLY]

//>> GET_[CPMS_PFETDLY_POWDN_DLY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PFETDLY_POWDN_DLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return i_data.extractToRight<CPMS_PFETDLY_POWDN_DLY,
           CPMS_PFETDLY_POWDN_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PFETDLY_POWDN_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PFETDLY_POWDN_DLY]

//>> SET_[CPMS_PFETDLY_L3_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PFETDLY_L3_POWUP_DLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return o_data.insertFromRight<CPMS_PFETDLY_L3_POWUP_DLY,
           CPMS_PFETDLY_L3_POWUP_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PFETDLY_L3_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PFETDLY_L3_POWUP_DLY]

//>> SET_[CPMS_PFETDLY_L3_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PFETDLY_L3_POWUP_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return o_data.insertFromRight<CPMS_PFETDLY_L3_POWUP_DLY,
           CPMS_PFETDLY_L3_POWUP_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PFETDLY_L3_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PFETDLY_L3_POWUP_DLY]

//>> GET_[CPMS_PFETDLY_L3_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PFETDLY_L3_POWUP_DLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return i_data.extractToRight<CPMS_PFETDLY_L3_POWUP_DLY,
           CPMS_PFETDLY_L3_POWUP_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PFETDLY_L3_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PFETDLY_L3_POWUP_DLY]

//>> SET_[CPMS_PFETDLY_CL2_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PFETDLY_CL2_POWUP_DLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return o_data.insertFromRight<CPMS_PFETDLY_CL2_POWUP_DLY,
           CPMS_PFETDLY_CL2_POWUP_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PFETDLY_CL2_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PFETDLY_CL2_POWUP_DLY]

//>> SET_[CPMS_PFETDLY_CL2_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PFETDLY_CL2_POWUP_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return o_data.insertFromRight<CPMS_PFETDLY_CL2_POWUP_DLY,
           CPMS_PFETDLY_CL2_POWUP_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PFETDLY_CL2_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PFETDLY_CL2_POWUP_DLY]

//>> GET_[CPMS_PFETDLY_CL2_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PFETDLY_CL2_POWUP_DLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return i_data.extractToRight<CPMS_PFETDLY_CL2_POWUP_DLY,
           CPMS_PFETDLY_CL2_POWUP_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PFETDLY_CL2_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PFETDLY_CL2_POWUP_DLY]

//>> SET_[CPMS_PFETDLY_MMA_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PFETDLY_MMA_POWUP_DLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return o_data.insertFromRight<CPMS_PFETDLY_MMA_POWUP_DLY,
           CPMS_PFETDLY_MMA_POWUP_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PFETDLY_MMA_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PFETDLY_MMA_POWUP_DLY]

//>> SET_[CPMS_PFETDLY_MMA_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PFETDLY_MMA_POWUP_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return o_data.insertFromRight<CPMS_PFETDLY_MMA_POWUP_DLY,
           CPMS_PFETDLY_MMA_POWUP_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PFETDLY_MMA_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PFETDLY_MMA_POWUP_DLY]

//>> GET_[CPMS_PFETDLY_MMA_POWUP_DLY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PFETDLY_MMA_POWUP_DLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PFETDLY));
#endif
    return i_data.extractToRight<CPMS_PFETDLY_MMA_POWUP_DLY,
           CPMS_PFETDLY_MMA_POWUP_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PFETDLY_MMA_POWUP_DLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PFETDLY_MMA_POWUP_DLY]

//>> PREP_[CPMS_PPSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_PPSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PPSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_PPSR]

//>> GET_[CPMS_PPSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_PPSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PPSR;
#endif
    return fapi2::getScom(i_target, CPMS_PPSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_PPSR]

//>> PUT_[CPMS_PPSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_PPSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return fapi2::putScom(i_target, CPMS_PPSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_PPSR]


//>> SET_[CPMS_PPSR_ENERGY_PROXY_UPPER]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_ENERGY_PROXY_UPPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_ENERGY_PROXY_UPPER,
           CPMS_PPSR_ENERGY_PROXY_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PPSR_ENERGY_PROXY_UPPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_ENERGY_PROXY_UPPER]

//>> SET_[CPMS_PPSR_ENERGY_PROXY_UPPER]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_ENERGY_PROXY_UPPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_ENERGY_PROXY_UPPER,
           CPMS_PPSR_ENERGY_PROXY_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PPSR_ENERGY_PROXY_UPPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_ENERGY_PROXY_UPPER]

//>> GET_[CPMS_PPSR_ENERGY_PROXY_UPPER]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PPSR_ENERGY_PROXY_UPPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.extractToRight<CPMS_PPSR_ENERGY_PROXY_UPPER,
           CPMS_PPSR_ENERGY_PROXY_UPPER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PPSR_ENERGY_PROXY_UPPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_ENERGY_PROXY_UPPER]

//>> SET_[CPMS_PPSR_ENERGY_PROXY_LOWER]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_ENERGY_PROXY_LOWER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_ENERGY_PROXY_LOWER,
           CPMS_PPSR_ENERGY_PROXY_LOWER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PPSR_ENERGY_PROXY_LOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_ENERGY_PROXY_LOWER]

//>> SET_[CPMS_PPSR_ENERGY_PROXY_LOWER]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_ENERGY_PROXY_LOWER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_ENERGY_PROXY_LOWER,
           CPMS_PPSR_ENERGY_PROXY_LOWER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PPSR_ENERGY_PROXY_LOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_ENERGY_PROXY_LOWER]

//>> GET_[CPMS_PPSR_ENERGY_PROXY_LOWER]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PPSR_ENERGY_PROXY_LOWER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.extractToRight<CPMS_PPSR_ENERGY_PROXY_LOWER,
           CPMS_PPSR_ENERGY_PROXY_LOWER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PPSR_ENERGY_PROXY_LOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_ENERGY_PROXY_LOWER]

//>> SET_[CPMS_PPSR_PERIOD_PROXY_REMAIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PERIOD_PROXY_REMAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_PERIOD_PROXY_REMAIN,
           CPMS_PPSR_PERIOD_PROXY_REMAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PPSR_PERIOD_PROXY_REMAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PERIOD_PROXY_REMAIN]

//>> SET_[CPMS_PPSR_PERIOD_PROXY_REMAIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PERIOD_PROXY_REMAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_PERIOD_PROXY_REMAIN,
           CPMS_PPSR_PERIOD_PROXY_REMAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PPSR_PERIOD_PROXY_REMAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PERIOD_PROXY_REMAIN]

//>> GET_[CPMS_PPSR_PERIOD_PROXY_REMAIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PPSR_PERIOD_PROXY_REMAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.extractToRight<CPMS_PPSR_PERIOD_PROXY_REMAIN,
           CPMS_PPSR_PERIOD_PROXY_REMAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PPSR_PERIOD_PROXY_REMAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_PERIOD_PROXY_REMAIN]

//>> SET_[CPMS_PPSR_FTX_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_FTX_SATURATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_FTX_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PPSR_FTX_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_FTX_SATURATED]

//>> SET_[CPMS_PPSR_FTX_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_FTX_SATURATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_FTX_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PPSR_FTX_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_FTX_SATURATED]

//>> SET_[CPMS_PPSR_FTX_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_FTX_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.setBit<CPMS_PPSR_FTX_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_PPSR_FTX_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_FTX_SATURATED]

//>> CLEAR_[CPMS_PPSR_FTX_SATURATED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_PPSR_FTX_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.clearBit<CPMS_PPSR_FTX_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_PPSR_FTX_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_PPSR_FTX_SATURATED]

//>> GET_[CPMS_PPSR_FTX_SATURATED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PPSR_FTX_SATURATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.extractToRight<CPMS_PPSR_FTX_SATURATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PPSR_FTX_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_FTX_SATURATED]

//>> GET_[CPMS_PPSR_FTX_SATURATED]
static inline bool GET_CPMS_PPSR_FTX_SATURATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.getBit<CPMS_PPSR_FTX_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_PPSR_FTX_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_FTX_SATURATED]

//>> SET_[CPMS_PPSR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_SATURATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_PITCH_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PPSR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_SATURATED]

//>> SET_[CPMS_PPSR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_SATURATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_PITCH_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PPSR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_SATURATED]

//>> SET_[CPMS_PPSR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.setBit<CPMS_PPSR_PITCH_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_PPSR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_SATURATED]

//>> CLEAR_[CPMS_PPSR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_PPSR_PITCH_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.clearBit<CPMS_PPSR_PITCH_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_PPSR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_PPSR_PITCH_SATURATED]

//>> GET_[CPMS_PPSR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PPSR_PITCH_SATURATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.extractToRight<CPMS_PPSR_PITCH_SATURATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PPSR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_PITCH_SATURATED]

//>> GET_[CPMS_PPSR_PITCH_SATURATED]
static inline bool GET_CPMS_PPSR_PITCH_SATURATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.getBit<CPMS_PPSR_PITCH_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_PPSR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_PITCH_SATURATED]

//>> SET_[CPMS_PPSR_PITCH_ABORTED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_ABORTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_PITCH_ABORTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PPSR_PITCH_ABORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_ABORTED]

//>> SET_[CPMS_PPSR_PITCH_ABORTED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_ABORTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_PITCH_ABORTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PPSR_PITCH_ABORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_ABORTED]

//>> SET_[CPMS_PPSR_PITCH_ABORTED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_ABORTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.setBit<CPMS_PPSR_PITCH_ABORTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_PPSR_PITCH_ABORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_ABORTED]

//>> CLEAR_[CPMS_PPSR_PITCH_ABORTED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_PPSR_PITCH_ABORTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.clearBit<CPMS_PPSR_PITCH_ABORTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_PPSR_PITCH_ABORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_PPSR_PITCH_ABORTED]

//>> GET_[CPMS_PPSR_PITCH_ABORTED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PPSR_PITCH_ABORTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.extractToRight<CPMS_PPSR_PITCH_ABORTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PPSR_PITCH_ABORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_PITCH_ABORTED]

//>> GET_[CPMS_PPSR_PITCH_ABORTED]
static inline bool GET_CPMS_PPSR_PITCH_ABORTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.getBit<CPMS_PPSR_PITCH_ABORTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_PPSR_PITCH_ABORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_PITCH_ABORTED]

//>> SET_[CPMS_PPSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_PITCH_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PPSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_ACTIVE]

//>> SET_[CPMS_PPSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.insertFromRight<CPMS_PPSR_PITCH_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PPSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_ACTIVE]

//>> SET_[CPMS_PPSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PPSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.setBit<CPMS_PPSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_PPSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PPSR_PITCH_ACTIVE]

//>> CLEAR_[CPMS_PPSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_PPSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return o_data.clearBit<CPMS_PPSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_PPSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_PPSR_PITCH_ACTIVE]

//>> GET_[CPMS_PPSR_PITCH_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PPSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.extractToRight<CPMS_PPSR_PITCH_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PPSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_PITCH_ACTIVE]

//>> GET_[CPMS_PPSR_PITCH_ACTIVE]
static inline bool GET_CPMS_PPSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PPSR));
#endif
    return i_data.getBit<CPMS_PPSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_PPSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PPSR_PITCH_ACTIVE]

//>> PREP_[EC_PC_COMMON_SPR_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_MODE]

//>> GET_[EC_PC_COMMON_SPR_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_MODE;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE]

//>> PUT_[EC_PC_COMMON_SPR_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_MODE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_MODE]


//>> SET_[EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ,
           EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ]

//>> SET_[EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ,
           EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ]

//>> GET_[EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ,
           EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]

//>> CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]
static inline bool GET_EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]

//>> CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]
static inline bool GET_EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]

//>> CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]
static inline bool GET_EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]

//>> CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]
static inline bool GET_EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]

//>> CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]
static inline bool GET_EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]

//>> CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]
static inline bool GET_EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]

//>> CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]
static inline bool GET_EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]

//>> SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]

//>> CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]

//>> GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]
static inline bool GET_EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_MODE));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL]

//>> PREP_[EC_PC_FIR_CORE_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_ACTION1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_ACTION1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_CORE_ACTION1]

//>> GET_[EC_PC_FIR_CORE_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_ACTION1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_ACTION1;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_ACTION1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1]

//>> PUT_[EC_PC_FIR_CORE_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_ACTION1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_ACTION1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_CORE_ACTION1]


//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]

//>> SET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]

//>> SET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]

//>> CLEAR_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]

//>> GET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]

//>> GET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]
static inline bool GET_P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_FIR_CORE_ACTION1_UNUSED_13]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_UNUSED_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_UNUSED_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_UNUSED_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_UNUSED_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_UNUSED_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]

//>> GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_UNUSED_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION1));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR]

//>> PREP_[EC_PC_PMC_THREAD_INFO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMC_THREAD_INFO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMC_THREAD_INFO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PMC_THREAD_INFO]

//>> GET_[EC_PC_PMC_THREAD_INFO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMC_THREAD_INFO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMC_THREAD_INFO;
#endif
    return fapi2::getScom(i_target, EC_PC_PMC_THREAD_INFO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO]

//>> PUT_[EC_PC_PMC_THREAD_INFO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMC_THREAD_INFO(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return fapi2::putScom(i_target, EC_PC_PMC_THREAD_INFO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PMC_THREAD_INFO]


//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP,
           EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP]

//>> SET_[EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE,
           EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE]

//>> SET_[EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE,
           EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE]

//>> GET_[EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE,
           EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE]

//>> SET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_PSCOM_PURGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_PSCOM_PURGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_PSCOM_PURGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]

//>> SET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_PSCOM_PURGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_PSCOM_PURGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_PSCOM_PURGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]

//>> SET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_PSCOM_PURGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_PSCOM_PURGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_PSCOM_PURGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_PSCOM_PURGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_PSCOM_PURGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_PSCOM_PURGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]

//>> GET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_PSCOM_PURGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_PSCOM_PURGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_PSCOM_PURGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]

//>> GET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]
static inline bool GET_EC_PC_PMC_THREAD_INFO_PSCOM_PURGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_PSCOM_PURGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_PSCOM_PURGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_PSCOM_PURGE]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]

//>> SET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]

//>> GET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]
static inline bool GET_EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS]

//>> SET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]

//>> SET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]

//>> SET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]

//>> GET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]

//>> GET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]
static inline bool GET_EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST]

//>> SET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]

//>> SET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]

//>> SET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]

//>> CLEAR_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]

//>> GET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]

//>> GET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]
static inline bool GET_EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST]

//>> SET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]

//>> SET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]

//>> SET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.setBit<P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]

//>> CLEAR_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return o_data.clearBit<P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]

//>> GET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.extractToRight<P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]

//>> GET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]
static inline bool GET_P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_THREAD_INFO));
#endif
    return i_data.getBit<P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_DOWN_BLOCKED]

//>> PREP_[EC_PC_SCR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SCR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_SCR1]

//>> GET_[EC_PC_SCR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SCR1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR1;
#endif
    return fapi2::getScom(i_target, EC_PC_SCR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_SCR1]

//>> PUT_[EC_PC_SCR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SCR1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SCR1));
#endif
    return fapi2::putScom(i_target, EC_PC_SCR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_SCR1]


//>> PREP_[EC_PC_TOD_READ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_READ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_READ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TOD_READ]

//>> GET_[EC_PC_TOD_READ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_READ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_READ;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_READ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TOD_READ]

//>> PUT_[EC_PC_TOD_READ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_READ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_READ));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_READ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TOD_READ]


//>> SET_[EC_PC_TOD_READ_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_READ_TOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_READ));
#endif
    return o_data.insertFromRight<EC_PC_TOD_READ_TOD,
           EC_PC_TOD_READ_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_READ_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_READ_TOD]

//>> SET_[EC_PC_TOD_READ_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_READ_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_READ));
#endif
    return o_data.insertFromRight<EC_PC_TOD_READ_TOD,
           EC_PC_TOD_READ_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_READ_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_READ_TOD]

//>> GET_[EC_PC_TOD_READ_TOD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_READ_TOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_READ));
#endif
    return i_data.extractToRight<EC_PC_TOD_READ_TOD,
           EC_PC_TOD_READ_TOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_READ_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_READ_TOD]

//>> PREP_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0]

//>> PUT_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0]


//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7]

//>> PREP_[QME_PSCRS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PSCRS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PSCRS0]

//>> GET_[QME_PSCRS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PSCRS0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS0;
#endif
    return fapi2::getScom(i_target, QME_PSCRS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PSCRS0]

//>> PUT_[QME_PSCRS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PSCRS0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return fapi2::putScom(i_target, QME_PSCRS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PSCRS0]


//>> SET_[QME_PSCRS0_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_DPDES_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_DPDES_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS0_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_DPDES_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_DPDES_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_DPDES_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_DPDES_EXIT_ENABLE]
static inline bool GET_QME_PSCRS0_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_SD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_SD]

//>> SET_[QME_PSCRS0_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_SD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_SD]

//>> SET_[QME_PSCRS0_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_SD]

//>> CLEAR_[QME_PSCRS0_SD]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_SD]

//>> GET_[QME_PSCRS0_SD]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_SD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_SD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_SD]

//>> GET_[QME_PSCRS0_SD]
static inline bool GET_QME_PSCRS0_SD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_SD]

//>> SET_[QME_PSCRS0_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_ESL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_ESL]

//>> SET_[QME_PSCRS0_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_ESL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_ESL]

//>> SET_[QME_PSCRS0_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_ESL]

//>> CLEAR_[QME_PSCRS0_ESL]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_ESL]

//>> GET_[QME_PSCRS0_ESL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_ESL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_ESL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_ESL]

//>> GET_[QME_PSCRS0_ESL]
static inline bool GET_QME_PSCRS0_ESL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_ESL]

//>> SET_[QME_PSCRS0_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_EC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_EC]

//>> SET_[QME_PSCRS0_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_EC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_EC]

//>> SET_[QME_PSCRS0_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_EC]

//>> CLEAR_[QME_PSCRS0_EC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_EC]

//>> GET_[QME_PSCRS0_EC]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_EC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_EC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_EC]

//>> GET_[QME_PSCRS0_EC]
static inline bool GET_QME_PSCRS0_EC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_EC]

//>> SET_[QME_PSCRS0_PSLL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_PSLL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_PSLL,
           QME_PSCRS0_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_PSLL]

//>> SET_[QME_PSCRS0_PSLL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_PSLL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_PSLL,
           QME_PSCRS0_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_PSLL]

//>> GET_[QME_PSCRS0_PSLL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_PSLL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_PSLL,
           QME_PSCRS0_PSLL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_PSLL]

//>> SET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HYP_VIRT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_HYP_VIRT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]
static inline bool GET_QME_PSCRS0_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_UV_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS0_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_UV_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_UV_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]
static inline bool GET_QME_PSCRS0_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HYP_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_HYP_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]
static inline bool GET_QME_PSCRS0_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_EXT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_EXT_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS0_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_EXT_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_EXT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_EXT_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_EXT_EXIT_ENABLE]
static inline bool GET_QME_PSCRS0_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_DEC_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_DEC_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS0_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_DEC_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_DEC_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_DEC_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_DEC_EXIT_ENABLE]
static inline bool GET_QME_PSCRS0_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HMI_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.setBit<QME_PSCRS0_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS0_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_HMI_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS0_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS0_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.clearBit<QME_PSCRS0_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS0_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS0_HMI_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_HMI_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_HMI_EXIT_ENABLE]

//>> GET_[QME_PSCRS0_HMI_EXIT_ENABLE]
static inline bool GET_QME_PSCRS0_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.getBit<QME_PSCRS0_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS0_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS0_TR]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_TR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_TR,
           QME_PSCRS0_TR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_TR]

//>> SET_[QME_PSCRS0_TR]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_TR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_TR,
           QME_PSCRS0_TR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_TR]

//>> GET_[QME_PSCRS0_TR]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_TR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_TR,
           QME_PSCRS0_TR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_TR]

//>> SET_[QME_PSCRS0_MTL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_MTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_MTL,
           QME_PSCRS0_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_MTL]

//>> SET_[QME_PSCRS0_MTL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_MTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_MTL,
           QME_PSCRS0_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_MTL]

//>> GET_[QME_PSCRS0_MTL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_MTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_MTL,
           QME_PSCRS0_MTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_MTL]

//>> SET_[QME_PSCRS0_RL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_RL,
           QME_PSCRS0_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_RL]

//>> SET_[QME_PSCRS0_RL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_RL,
           QME_PSCRS0_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_RL]

//>> GET_[QME_PSCRS0_RL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_RL,
           QME_PSCRS0_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_RL]

//>> SET_[QME_PSCRS0_PLS]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_PLS,
           QME_PSCRS0_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS0_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_PLS]

//>> SET_[QME_PSCRS0_PLS]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS0_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return o_data.insertFromRight<QME_PSCRS0_PLS,
           QME_PSCRS0_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS0_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS0_PLS]

//>> GET_[QME_PSCRS0_PLS]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS0_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS0));
#endif
    return i_data.extractToRight<QME_PSCRS0_PLS,
           QME_PSCRS0_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS0_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS0_PLS]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
