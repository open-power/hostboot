/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00005.H $            */
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

#ifndef __C_REG00005_H_
#define __C_REG00005_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_FLMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FLMR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FLMR_RW]

//>> GET_[CPMS_FLMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FLMR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_RW;
#endif
    return fapi2::getScom(i_target, CPMS_FLMR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FLMR_RW]

//>> PUT_[CPMS_FLMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FLMR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FLMR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FLMR_RW]

//>> PREP_[CPMS_FLMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FLMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FLMR_WO_CLEAR]

//>> GET_[CPMS_FLMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FLMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_FLMR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FLMR_WO_CLEAR]

//>> PUT_[CPMS_FLMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FLMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FLMR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FLMR_WO_CLEAR]

//>> PREP_[CPMS_FLMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FLMR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FLMR_WO_OR]

//>> GET_[CPMS_FLMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FLMR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_FLMR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FLMR_WO_OR]

//>> PUT_[CPMS_FLMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FLMR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FLMR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FLMR_WO_OR]


//>> SET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_INITIAL_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_INITIAL_CYCLES,
           CPMS_FLMR_LARGE_INITIAL_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]

//>> SET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_INITIAL_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_INITIAL_CYCLES,
           CPMS_FLMR_LARGE_INITIAL_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]

//>> GET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_INITIAL_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_INITIAL_CYCLES,
           CPMS_FLMR_LARGE_INITIAL_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]

//>> SET_[CPMS_FLMR_LARGE_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_INITIAL_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_INITIAL_ACTION,
           CPMS_FLMR_LARGE_INITIAL_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_INITIAL_ACTION]

//>> SET_[CPMS_FLMR_LARGE_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_INITIAL_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_INITIAL_ACTION,
           CPMS_FLMR_LARGE_INITIAL_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_INITIAL_ACTION]

//>> GET_[CPMS_FLMR_LARGE_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_INITIAL_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_INITIAL_ACTION,
           CPMS_FLMR_LARGE_INITIAL_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_INITIAL_ACTION]

//>> SET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_PREFETCH_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_PREFETCH_ACTION,
           CPMS_FLMR_LARGE_PREFETCH_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]

//>> SET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_PREFETCH_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_PREFETCH_ACTION,
           CPMS_FLMR_LARGE_PREFETCH_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]

//>> GET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_PREFETCH_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_PREFETCH_ACTION,
           CPMS_FLMR_LARGE_PREFETCH_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]

//>> SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_RESPONSE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_RESPONSE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_LARGE_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> CLEAR_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_LARGE_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> GET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_RESPONSE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> GET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline bool GET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_LARGE_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_FLUSH_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_FLUSH_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_FLUSH_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_LARGE_FLUSH_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> CLEAR_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_LARGE_FLUSH_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> GET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_FLUSH_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> GET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline bool GET_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_LARGE_FLUSH_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> CLEAR_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> GET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> GET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline bool GET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_INITIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_INITIAL,
           CPMS_FLMR_LARGE_DITHER_INITIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_INITIAL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_INITIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_INITIAL,
           CPMS_FLMR_LARGE_DITHER_INITIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_INITIAL]

//>> GET_[CPMS_FLMR_LARGE_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_DITHER_INITIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_DITHER_INITIAL,
           CPMS_FLMR_LARGE_DITHER_INITIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_INITIAL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_REPEAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_REPEAT,
           CPMS_FLMR_LARGE_DITHER_REPEAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_REPEAT]

//>> SET_[CPMS_FLMR_LARGE_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_REPEAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_REPEAT,
           CPMS_FLMR_LARGE_DITHER_REPEAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_REPEAT]

//>> GET_[CPMS_FLMR_LARGE_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_DITHER_REPEAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_DITHER_REPEAT,
           CPMS_FLMR_LARGE_DITHER_REPEAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_REPEAT]

//>> SET_[CPMS_FLMR_LARGE_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_INCREASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_INCREASE,
           CPMS_FLMR_LARGE_DITHER_INCREASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_INCREASE]

//>> SET_[CPMS_FLMR_LARGE_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_INCREASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_INCREASE,
           CPMS_FLMR_LARGE_DITHER_INCREASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_INCREASE]

//>> GET_[CPMS_FLMR_LARGE_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_DITHER_INCREASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_DITHER_INCREASE,
           CPMS_FLMR_LARGE_DITHER_INCREASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_INCREASE]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_ACTION,
           CPMS_FLMR_PHASE1_RECOVERY_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_ACTION,
           CPMS_FLMR_PHASE1_RECOVERY_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]

//>> GET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE1_RECOVERY_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE1_RECOVERY_ACTION,
           CPMS_FLMR_PHASE1_RECOVERY_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE1_RECOVERY_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE1_RECOVERY_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]

//>> GET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE1_RECOVERY_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE1_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE1_RECOVERY_PREFETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_VECTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE1_RECOVERY_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_VECTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE1_RECOVERY_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]

//>> GET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE1_RECOVERY_VECTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE1_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE1_RECOVERY_VECTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_ACTION,
           CPMS_FLMR_PHASE2_RECOVERY_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_ACTION,
           CPMS_FLMR_PHASE2_RECOVERY_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]

//>> GET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE2_RECOVERY_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE2_RECOVERY_ACTION,
           CPMS_FLMR_PHASE2_RECOVERY_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE2_RECOVERY_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE2_RECOVERY_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]

//>> GET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE2_RECOVERY_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE2_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE2_RECOVERY_PREFETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_VECTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE2_RECOVERY_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_VECTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE2_RECOVERY_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]

//>> GET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE2_RECOVERY_VECTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE2_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE2_RECOVERY_VECTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_CYCLES,
           CPMS_FLMR_PHASE2_RECOVERY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_CYCLES,
           CPMS_FLMR_PHASE2_RECOVERY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]

//>> GET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE2_RECOVERY_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE2_RECOVERY_CYCLES,
           CPMS_FLMR_PHASE2_RECOVERY_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]

//>> SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> CLEAR_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> GET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> GET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline bool GET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> SET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PREDICT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_MMA_DROOP_PREDICT_SELECT,
           CPMS_FLMR_MMA_DROOP_PREDICT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PREDICT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]

//>> SET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PREDICT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_MMA_DROOP_PREDICT_SELECT,
           CPMS_FLMR_MMA_DROOP_PREDICT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PREDICT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]

//>> GET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_MMA_DROOP_PREDICT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_MMA_DROOP_PREDICT_SELECT,
           CPMS_FLMR_MMA_DROOP_PREDICT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PREDICT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]

//>> SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> CLEAR_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> GET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> GET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline bool GET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS,
           CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS,
           CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]

//>> GET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS,
           CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_GRANT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_GRANT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_CORE_UCODE_GRANT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> CLEAR_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_CORE_UCODE_GRANT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> GET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_CORE_UCODE_GRANT_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> GET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline bool GET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_CORE_UCODE_GRANT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> SET_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_FTC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_FTC_RESET]

//>> SET_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_FTC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_FTC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_FTC_RESET]

//>> SET_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_FTC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_FTC_RESET]

//>> CLEAR_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_FTC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_FTC_RESET]

//>> GET_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_FTC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_FTC_RESET]

//>> GET_[CPMS_FLMR_FTC_RESET]
static inline bool GET_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_FTC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_FTC_RESET]

//>> SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> CLEAR_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> GET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> GET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline bool GET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> SET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_DITHER_NTC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> SET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_DITHER_NTC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_DITHER_NTC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> SET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_PHASE1_DITHER_NTC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> CLEAR_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_PHASE1_DITHER_NTC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> GET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE1_DITHER_NTC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> GET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline bool GET_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_PHASE1_DITHER_NTC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> CLEAR_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> GET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> GET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline bool GET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> PREP_[CPMS_WPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_WPCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_WPCR]

//>> GET_[CPMS_WPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_WPCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPCR;
#endif
    return fapi2::getScom(i_target, CPMS_WPCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_WPCR]

//>> PUT_[CPMS_WPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_WPCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return fapi2::putScom(i_target, CPMS_WPCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_WPCR]


//>> SET_[CPMS_WPCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE,
           CPMS_WPCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE]

//>> SET_[CPMS_WPCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE,
           CPMS_WPCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE]

//>> GET_[CPMS_WPCR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_SPARE,
           CPMS_WPCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_SPARE]

//>> SET_[CPMS_WPCR_BASE_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_BASE_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_BASE_THROTTLE_INDEX,
           CPMS_WPCR_BASE_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_BASE_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_BASE_THROTTLE_INDEX]

//>> SET_[CPMS_WPCR_BASE_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_BASE_THROTTLE_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_BASE_THROTTLE_INDEX,
           CPMS_WPCR_BASE_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_BASE_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_BASE_THROTTLE_INDEX]

//>> GET_[CPMS_WPCR_BASE_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_BASE_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_BASE_THROTTLE_INDEX,
           CPMS_WPCR_BASE_THROTTLE_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_BASE_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_BASE_THROTTLE_INDEX]

//>> SET_[CPMS_WPCR_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE2,
           CPMS_WPCR_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE2]

//>> SET_[CPMS_WPCR_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE2,
           CPMS_WPCR_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE2]

//>> GET_[CPMS_WPCR_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_SPARE2,
           CPMS_WPCR_SPARE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_SPARE2]

//>> SET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_INTERVAL_PROXY_TARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_INTERVAL_PROXY_TARGET,
           CPMS_WPCR_INTERVAL_PROXY_TARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_INTERVAL_PROXY_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]

//>> SET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_INTERVAL_PROXY_TARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_INTERVAL_PROXY_TARGET,
           CPMS_WPCR_INTERVAL_PROXY_TARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_INTERVAL_PROXY_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]

//>> GET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_INTERVAL_PROXY_TARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_INTERVAL_PROXY_TARGET,
           CPMS_WPCR_INTERVAL_PROXY_TARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_INTERVAL_PROXY_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]

//>> SET_[CPMS_WPCR_WOF_INTERVAL_TARGET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_WOF_INTERVAL_TARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_WOF_INTERVAL_TARGET,
           CPMS_WPCR_WOF_INTERVAL_TARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_WOF_INTERVAL_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_WOF_INTERVAL_TARGET]

//>> SET_[CPMS_WPCR_WOF_INTERVAL_TARGET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_WOF_INTERVAL_TARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_WOF_INTERVAL_TARGET,
           CPMS_WPCR_WOF_INTERVAL_TARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_WOF_INTERVAL_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_WOF_INTERVAL_TARGET]

//>> GET_[CPMS_WPCR_WOF_INTERVAL_TARGET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_WOF_INTERVAL_TARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_WOF_INTERVAL_TARGET,
           CPMS_WPCR_WOF_INTERVAL_TARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_WOF_INTERVAL_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_WOF_INTERVAL_TARGET]

//>> SET_[CPMS_WPCR_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE3]

//>> SET_[CPMS_WPCR_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE3]

//>> SET_[CPMS_WPCR_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE3]

//>> CLEAR_[CPMS_WPCR_SPARE3]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_SPARE3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_SPARE3]

//>> GET_[CPMS_WPCR_SPARE3]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_SPARE3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_SPARE3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_SPARE3]

//>> GET_[CPMS_WPCR_SPARE3]
static inline bool GET_CPMS_WPCR_SPARE3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_SPARE3]

//>> SET_[CPMS_WPCR_PROXY_THRESH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PROXY_THRESH_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PROXY_THRESH_SELECT,
           CPMS_WPCR_PROXY_THRESH_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PROXY_THRESH_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PROXY_THRESH_SELECT]

//>> SET_[CPMS_WPCR_PROXY_THRESH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PROXY_THRESH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PROXY_THRESH_SELECT,
           CPMS_WPCR_PROXY_THRESH_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PROXY_THRESH_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PROXY_THRESH_SELECT]

//>> GET_[CPMS_WPCR_PROXY_THRESH_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PROXY_THRESH_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PROXY_THRESH_SELECT,
           CPMS_WPCR_PROXY_THRESH_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PROXY_THRESH_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PROXY_THRESH_SELECT]

//>> SET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PROXY_CARRYOUT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PROXY_CARRYOUT_SEL,
           CPMS_WPCR_PROXY_CARRYOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PROXY_CARRYOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]

//>> SET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PROXY_CARRYOUT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PROXY_CARRYOUT_SEL,
           CPMS_WPCR_PROXY_CARRYOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PROXY_CARRYOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]

//>> GET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PROXY_CARRYOUT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PROXY_CARRYOUT_SEL,
           CPMS_WPCR_PROXY_CARRYOUT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PROXY_CARRYOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_FTX_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_FTX_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> CLEAR_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> GET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_FTX_SAT_MAX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> GET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline bool GET_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_FTX_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_FTX_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> CLEAR_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> GET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_FTX_SAT_MIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> GET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline bool GET_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_ACCERR_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_ACCERR_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> CLEAR_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_ACCERR_SAT_MAX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline bool GET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_ACCERR_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_ACCERR_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> CLEAR_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_ACCERR_SAT_MIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline bool GET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_APP_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> SET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_APP_SATURATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_APP_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> SET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> CLEAR_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> GET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_APP_SATURATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> GET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline bool GET_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> SET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_STOP_STATE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> CLEAR_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> GET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_STOP_STATE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> GET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline bool GET_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> PREP_[L3_MISC_L3CERRS_MODE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_MODE_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_MODE_REG0]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_MODE_REG0;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_MODE_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0]

//>> PUT_[L3_MISC_L3CERRS_MODE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_MODE_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_MODE_REG0]


//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN,
           L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN,
           L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN,
           L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> PREP_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]

//>> PUT_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]


//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]

//>> PREP_[QME_CIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CIIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CIIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_CIIR]

//>> GET_[QME_CIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CIIR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CIIR;
#endif
    return fapi2::getScom(i_target, QME_CIIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_CIIR]

//>> PUT_[QME_CIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CIIR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return fapi2::putScom(i_target, QME_CIIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_CIIR]


//>> SET_[QME_CIIR_MSGSND_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_QME_CIIR_MSGSND_INTR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return o_data.insertFromRight<QME_CIIR_MSGSND_INTR_INJECT,
           QME_CIIR_MSGSND_INTR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CIIR_MSGSND_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CIIR_MSGSND_INTR_INJECT]

//>> SET_[QME_CIIR_MSGSND_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_QME_CIIR_MSGSND_INTR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return o_data.insertFromRight<QME_CIIR_MSGSND_INTR_INJECT,
           QME_CIIR_MSGSND_INTR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CIIR_MSGSND_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CIIR_MSGSND_INTR_INJECT]

//>> GET_[QME_CIIR_MSGSND_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& GET_QME_CIIR_MSGSND_INTR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return i_data.extractToRight<QME_CIIR_MSGSND_INTR_INJECT,
           QME_CIIR_MSGSND_INTR_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CIIR_MSGSND_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CIIR_MSGSND_INTR_INJECT]

//>> SET_[QME_CIIR_MSGSNDU_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_QME_CIIR_MSGSNDU_INTR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return o_data.insertFromRight<QME_CIIR_MSGSNDU_INTR_INJECT,
           QME_CIIR_MSGSNDU_INTR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CIIR_MSGSNDU_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CIIR_MSGSNDU_INTR_INJECT]

//>> SET_[QME_CIIR_MSGSNDU_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_QME_CIIR_MSGSNDU_INTR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return o_data.insertFromRight<QME_CIIR_MSGSNDU_INTR_INJECT,
           QME_CIIR_MSGSNDU_INTR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CIIR_MSGSNDU_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CIIR_MSGSNDU_INTR_INJECT]

//>> GET_[QME_CIIR_MSGSNDU_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& GET_QME_CIIR_MSGSNDU_INTR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return i_data.extractToRight<QME_CIIR_MSGSNDU_INTR_INJECT,
           QME_CIIR_MSGSNDU_INTR_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CIIR_MSGSNDU_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CIIR_MSGSNDU_INTR_INJECT]

//>> PREP_[QME_RMOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RMOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RMOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RMOR]

//>> GET_[QME_RMOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RMOR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RMOR;
#endif
    return fapi2::getScom(i_target, QME_RMOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RMOR]

//>> PUT_[QME_RMOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RMOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return fapi2::putScom(i_target, QME_RMOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RMOR]


//>> SET_[QME_RMOR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.insertFromRight<QME_RMOR_DATA,
           QME_RMOR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_RMOR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_DATA]

//>> SET_[QME_RMOR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.insertFromRight<QME_RMOR_DATA,
           QME_RMOR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_RMOR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_DATA]

//>> GET_[QME_RMOR_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_RMOR_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return i_data.extractToRight<QME_RMOR_DATA,
           QME_RMOR_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_RMOR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RMOR_DATA]

//>> SET_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.insertFromRight<QME_RMOR_URMOR_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_URMOR_SELECT]

//>> SET_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_URMOR_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.insertFromRight<QME_RMOR_URMOR_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_URMOR_SELECT]

//>> SET_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.setBit<QME_RMOR_URMOR_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_URMOR_SELECT]

//>> CLEAR_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.clearBit<QME_RMOR_URMOR_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_RMOR_URMOR_SELECT]

//>> GET_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& GET_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return i_data.extractToRight<QME_RMOR_URMOR_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RMOR_URMOR_SELECT]

//>> GET_[QME_RMOR_URMOR_SELECT]
static inline bool GET_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return i_data.getBit<QME_RMOR_URMOR_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RMOR_URMOR_SELECT]

//>> PREP_[QME_SCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCR_RW]

//>> GET_[QME_SCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCR_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_RW;
#endif
    return fapi2::getScom(i_target, QME_SCR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCR_RW]

//>> PUT_[QME_SCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCR_RW]

//>> PREP_[QME_SCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCR_WO_CLEAR]

//>> GET_[QME_SCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_SCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCR_WO_CLEAR]

//>> PUT_[QME_SCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCR_WO_CLEAR]

//>> PREP_[QME_SCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCR_WO_OR]

//>> GET_[QME_SCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_SCR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCR_WO_OR]

//>> PUT_[QME_SCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCR_WO_OR]


//>> SET_[QME_SCR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_SCR_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_SCR_DATA,
           QME_SCR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCR_DATA]

//>> SET_[QME_SCR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_SCR_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_SCR_DATA,
           QME_SCR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCR_DATA]

//>> GET_[QME_SCR_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_SCR_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return i_data.extractToRight<QME_SCR_DATA,
           QME_SCR_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCR_DATA]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
