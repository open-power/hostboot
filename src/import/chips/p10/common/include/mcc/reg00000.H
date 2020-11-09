/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00000.H $          */
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

#ifndef __MCC_REG00000_H_
#define __MCC_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[DSTL_DSTLFIRACT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRACT2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRACT2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DSTL_DSTLFIRACT2]

//>> GET_[DSTL_DSTLFIRACT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRACT2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRACT2;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRACT2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DSTL_DSTLFIRACT2]

//>> PUT_[DSTL_DSTLFIRACT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRACT2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT2));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRACT2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DSTL_DSTLFIRACT2]


//>> SET_[DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT2));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2,
           DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]

//>> SET_[DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT2));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2,
           DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]

//>> GET_[DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT2));
#endif
    return i_data.extractToRight<DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2,
           DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]

//>> SET_[P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT2));
#endif
    return o_data.insertFromRight<P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2,
           P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]

//>> SET_[P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT2));
#endif
    return o_data.insertFromRight<P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2,
           P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]

//>> GET_[P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT2));
#endif
    return i_data.extractToRight<P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2,
           P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DSTL_DSTLFIRACT2_DSTLFIRACT2_ACTION_2]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
