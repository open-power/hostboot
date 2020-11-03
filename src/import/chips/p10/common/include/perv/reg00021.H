/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00021.H $         */
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

#ifndef __PERV_REG00021_H_
#define __PERV_REG00021_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[TOD_VALUE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_VALUE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_VALUE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_VALUE_REG]

//>> GET_[TOD_VALUE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_VALUE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_VALUE_REG;
#endif
    return fapi2::getScom(i_target, TOD_VALUE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_VALUE_REG]

//>> PUT_[TOD_VALUE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_VALUE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_VALUE_REG));
#endif
    return fapi2::putScom(i_target, TOD_VALUE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_VALUE_REG]


//>> SET_[TOD_VALUE_REG_TOD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_VALUE_REG_TOD_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_VALUE_REG));
#endif
    return o_data.insertFromRight<TOD_VALUE_REG_TOD_VALUE,
           TOD_VALUE_REG_TOD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_VALUE_REG_TOD_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_VALUE_REG_TOD_VALUE]

//>> SET_[TOD_VALUE_REG_TOD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_VALUE_REG_TOD_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_VALUE_REG));
#endif
    return o_data.insertFromRight<TOD_VALUE_REG_TOD_VALUE,
           TOD_VALUE_REG_TOD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_VALUE_REG_TOD_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_VALUE_REG_TOD_VALUE]

//>> GET_[TOD_VALUE_REG_TOD_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_VALUE_REG_TOD_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_VALUE_REG));
#endif
    return i_data.extractToRight<TOD_VALUE_REG_TOD_VALUE,
           TOD_VALUE_REG_TOD_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_VALUE_REG_TOD_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_VALUE_REG_TOD_VALUE]

//>> SET_[TOD_VALUE_REG_WOF_COUNTER_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_VALUE_REG_WOF_COUNTER_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_VALUE_REG));
#endif
    return o_data.insertFromRight<TOD_VALUE_REG_WOF_COUNTER_VALUE,
           TOD_VALUE_REG_WOF_COUNTER_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_VALUE_REG_WOF_COUNTER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_VALUE_REG_WOF_COUNTER_VALUE]

//>> SET_[TOD_VALUE_REG_WOF_COUNTER_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_VALUE_REG_WOF_COUNTER_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_VALUE_REG));
#endif
    return o_data.insertFromRight<TOD_VALUE_REG_WOF_COUNTER_VALUE,
           TOD_VALUE_REG_WOF_COUNTER_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_VALUE_REG_WOF_COUNTER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_VALUE_REG_WOF_COUNTER_VALUE]

//>> GET_[TOD_VALUE_REG_WOF_COUNTER_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_VALUE_REG_WOF_COUNTER_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_VALUE_REG));
#endif
    return i_data.extractToRight<TOD_VALUE_REG_WOF_COUNTER_VALUE,
           TOD_VALUE_REG_WOF_COUNTER_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_VALUE_REG_WOF_COUNTER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_VALUE_REG_WOF_COUNTER_VALUE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
