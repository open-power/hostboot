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

//>> PREP_[EC_LS_LSU_HOLD_OUT_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_LS_LSU_HOLD_OUT_REG3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG3;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3]

//>> PUT_[EC_LS_LSU_HOLD_OUT_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_LS_LSU_HOLD_OUT_REG3]


//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_0_EADIR_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG3));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG3_1_EADIR_ERR_HOLD_OUT_SET7]

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

//>> PREP_[EC_PC_COMMON_SPR_V2_HMER_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_V2_HMER_RW_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_V2_HMER_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_V2_HMER_RW_WAND]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_V2_HMER_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_V2_HMER_RW_WAND;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_V2_HMER_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_RW_WAND]

//>> PUT_[EC_PC_COMMON_SPR_V2_HMER_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_V2_HMER_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_V2_HMER_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_V2_HMER_RW_WAND]

//>> PREP_[EC_PC_COMMON_SPR_V2_HMER_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_V2_HMER_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_V2_HMER_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_V2_HMER_WO_OR]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_V2_HMER_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_V2_HMER_WO_OR;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_V2_HMER_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_WO_OR]

//>> PUT_[EC_PC_COMMON_SPR_V2_HMER_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_V2_HMER_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_V2_HMER_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_V2_HMER_WO_OR]


//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_MALFUNCTION_ALERT]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_1]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_DONE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SUSPEND_MODE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFAC_ERR]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TFX_ERR]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_6]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_7]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_FAIL]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_DONE]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_10]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_PROC_RCVY_AGAIN]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_12]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_13]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_14]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_15]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_SCOM_FIR_HMI]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_TRIG_FIR_HMI]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_19]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_SPARE_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]

//>> CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V2_HMER_SPARE_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_SPARE_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]
static inline bool GET_EC_PC_COMMON_SPR_V2_HMER_SPARE_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V2_HMER_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_SPARE_20]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS]

//>> SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS]

//>> GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V2_HMER_RW_WAND, EC_PC_COMMON_SPR_V2_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_V2_HMER_V2_HMER_XSCOM_STATUS]

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

//>> PREP_[EC_PC_PMU_SPRCOR_OCC_SCOMC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMU_SPRCOR_OCC_SCOMC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_OCC_SCOMC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PMU_SPRCOR_OCC_SCOMC]

//>> GET_[EC_PC_PMU_SPRCOR_OCC_SCOMC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMU_SPRCOR_OCC_SCOMC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_OCC_SCOMC;
#endif
    return fapi2::getScom(i_target, EC_PC_PMU_SPRCOR_OCC_SCOMC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_OCC_SCOMC]

//>> PUT_[EC_PC_PMU_SPRCOR_OCC_SCOMC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMU_SPRCOR_OCC_SCOMC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_OCC_SCOMC));
#endif
    return fapi2::putScom(i_target, EC_PC_PMU_SPRCOR_OCC_SCOMC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PMU_SPRCOR_OCC_SCOMC]


//>> SET_[EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_OCC_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS,
           EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS]

//>> SET_[EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_OCC_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS,
           EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS]

//>> GET_[EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_OCC_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS,
           EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_OCC_SCOMC_OCC_SCOMD_ADDRESS]

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

//>> PREP_[EC_PC_TRACE2_TR_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE2_TR_TR0_CONFIG_3]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_3]

//>> PUT_[EC_PC_TRACE2_TR_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE2_TR_TR0_CONFIG_3]


//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_3_C,
           EC_PC_TRACE2_TR_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_C]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_3_C,
           EC_PC_TRACE2_TR_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_C]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_CONFIG_3_C,
           EC_PC_TRACE2_TR_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_C]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_3_D,
           EC_PC_TRACE2_TR_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_D]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_3_D,
           EC_PC_TRACE2_TR_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_D]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_CONFIG_3_D,
           EC_PC_TRACE2_TR_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_3_D]

//>> PREP_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_SD_SDP_SDCR_UNIT_HOLD_OUT2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_SD_SDP_SDCR_UNIT_HOLD_OUT2;
#endif
    return fapi2::getScom(i_target, EC_SD_SDP_SDCR_UNIT_HOLD_OUT2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2]

//>> PUT_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return fapi2::putScom(i_target, EC_SD_SDP_SDCR_UNIT_HOLD_OUT2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2]


//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_S_ERR_HOLD_OUT_5]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T1_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T3_SS_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_LTAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T0_CCC_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_D_T2_CCC_STAG_LTZ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T0_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T1_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT2));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT2_P_WAT_T2_HOLD_OUT]

//>> PREP_[L2_L2MISC_L2CERRS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_FIR_REG_RW]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RW]

//>> PUT_[L2_L2MISC_L2CERRS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_FIR_REG_RW]

//>> PREP_[L2_L2MISC_L2CERRS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_FIR_REG_WO_AND]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_WO_AND]

//>> PUT_[L2_L2MISC_L2CERRS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_FIR_REG_WO_AND]

//>> PREP_[L2_L2MISC_L2CERRS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_FIR_REG_WO_OR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_WO_OR]

//>> PUT_[L2_L2MISC_L2CERRS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_FIR_REG_WO_OR]


//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RSVD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RSVD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_RSVD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_RSVD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_RSVD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_RSVD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_RSVD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_RSVD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_RSVD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_RSVD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_RSVD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_RSVD]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1,
           L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1,
           L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1,
           L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE2TO1]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]

//>> CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]
static inline bool GET_L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1,
           L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1]

//>> SET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1,
           L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1]

//>> GET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_REG_RW, L2_L2MISC_L2CERRS_FIR_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1,
           L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_REG_SPARE1TO1]

//>> PREP_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_CAC_WAY_DIS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_CAC_WAY_DIS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG]

//>> GET_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_CAC_WAY_DIS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_CAC_WAY_DIS_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_CAC_WAY_DIS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG]

//>> PUT_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_CAC_WAY_DIS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_CAC_WAY_DIS_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_CAC_WAY_DIS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG]


//>> SET_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_CAC_WAY_DIS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG,
           L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_CAC_WAY_DIS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG,
           L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG]

//>> GET_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_CAC_WAY_DIS_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG,
           L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_CAC_WAY_DIS_REG_L3_CAC_WAY_DIS_CFG]

//>> PREP_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG]

//>> GET_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG]

//>> PUT_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG]


//>> SET_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS,
           L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS]

//>> SET_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS,
           L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS]

//>> GET_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS,
           L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS]

//>> PREP_[NC_NCMISC_NCSCOMS_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_INJ_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_INJ_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_INJ_REG]

//>> GET_[NC_NCMISC_NCSCOMS_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_INJ_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_INJ_REG;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_INJ_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_INJ_REG]

//>> PUT_[NC_NCMISC_NCSCOMS_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_INJ_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_INJ_REG));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_INJ_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_INJ_REG]


//>> SET_[NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_INJ_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ,
           NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ]

//>> SET_[NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_INJ_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ,
           NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ]

//>> GET_[NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_INJ_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ,
           NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ]

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

//>> PREP_[PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSCOM_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PSCOM_MODE_REG]

//>> GET_[PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSCOM_MODE_REG;
#endif
    return fapi2::getScom(i_target, PSCOM_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PSCOM_MODE_REG]

//>> PUT_[PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return fapi2::putScom(i_target, PSCOM_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PSCOM_MODE_REG]


//>> SET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.setBit<PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> CLEAR_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.clearBit<PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> GET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> GET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline bool GET_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.getBit<PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.setBit<PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> CLEAR_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.clearBit<PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> GET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> GET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline bool GET_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.getBit<PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.setBit<PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> CLEAR_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.clearBit<PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> GET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> GET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline bool GET_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.getBit<PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_WATCHDOG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.setBit<PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> CLEAR_[PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.clearBit<PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> GET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> GET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline bool GET_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.getBit<PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_SCOM_HANG_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> SET_[PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_SCOM_HANG_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> GET_[PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PSCOM_MODE_REG_SCOM_HANG_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> SET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_FORCE_ALL_RINGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.setBit<PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> CLEAR_[PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.clearBit<PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> GET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& GET_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> GET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline bool GET_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.getBit<PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.setBit<PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> CLEAR_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.clearBit<PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> GET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> GET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline bool GET_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.getBit<PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

//>> SET_[PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& SET_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

//>> GET_[PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& GET_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

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
