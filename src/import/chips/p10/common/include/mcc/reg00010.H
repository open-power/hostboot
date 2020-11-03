/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00010.H $          */
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

#ifndef __MCC_REG00010_H_
#define __MCC_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[DSTL_DSTLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DSTL_DSTLFIRACT1]

//>> GET_[DSTL_DSTLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRACT1;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DSTL_DSTLFIRACT1]

//>> PUT_[DSTL_DSTLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRACT1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT1));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DSTL_DSTLFIRACT1]


//>> SET_[DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT1));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1,
           DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1]

//>> SET_[DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT1));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1,
           DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1]

//>> GET_[DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT1));
#endif
    return i_data.extractToRight<DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1,
           DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
