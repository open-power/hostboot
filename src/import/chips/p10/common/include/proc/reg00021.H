/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00021.H $         */
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

#ifndef __PROC_REG00021_H_
#define __PROC_REG00021_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_VC_ENDC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_FLUSH_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_VC_ENDC_FLUSH_CTRL]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_FLUSH_CTRL;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_FLUSH_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL]

//>> PUT_[INT_VC_ENDC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_FLUSH_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_VC_ENDC_FLUSH_CTRL]


//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6,
           INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6,
           INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6,
           INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]

//>> PREP_[PB_PTLSCOM10_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_FP23_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FP23_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_FP23_CFG]

//>> GET_[PB_PTLSCOM10_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_FP23_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FP23_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_FP23_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG]

//>> PUT_[PB_PTLSCOM10_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_FP23_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_FP23_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_FP23_CFG]


//>> SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME,
           PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]

//>> SET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME,
           PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]

//>> GET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME,
           PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]

//>> PREP_[INT_PC_REGS_TCTXT_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_TCTXT_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_TCTXT_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_PC_REGS_TCTXT_CFG]

//>> GET_[INT_PC_REGS_TCTXT_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_TCTXT_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_TCTXT_CFG;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_TCTXT_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG]

//>> PUT_[INT_PC_REGS_TCTXT_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_TCTXT_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_TCTXT_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_PC_REGS_TCTXT_CFG]


//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_2_3,
           INT_PC_REGS_TCTXT_CFG_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_2_3,
           INT_PC_REGS_TCTXT_CFG_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_2_3,
           INT_PC_REGS_TCTXT_CFG_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_7_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_7_11,
           INT_PC_REGS_TCTXT_CFG_RESERVED_7_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_7_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_7_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_7_11,
           INT_PC_REGS_TCTXT_CFG_RESERVED_7_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_7_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_7_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_7_11,
           INT_PC_REGS_TCTXT_CFG_RESERVED_7_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_7_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_14_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_14_16,
           INT_PC_REGS_TCTXT_CFG_RESERVED_14_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_14_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_14_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_14_16,
           INT_PC_REGS_TCTXT_CFG_RESERVED_14_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_14_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_14_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_14_16,
           INT_PC_REGS_TCTXT_CFG_RESERVED_14_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_14_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_18_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_18_19,
           INT_PC_REGS_TCTXT_CFG_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_18_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_18_19,
           INT_PC_REGS_TCTXT_CFG_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_18_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_18_19,
           INT_PC_REGS_TCTXT_CFG_RESERVED_18_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]

//>> SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_21_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_21_24,
           INT_PC_REGS_TCTXT_CFG_RESERVED_21_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_21_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_21_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_21_24,
           INT_PC_REGS_TCTXT_CFG_RESERVED_21_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_21_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_21_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_21_24,
           INT_PC_REGS_TCTXT_CFG_RESERVED_21_24_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_21_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS,
           INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS,
           INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS,
           INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO,
           INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO,
           INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO,
           INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE,
           INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE,
           INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE,
           INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
